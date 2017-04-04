#include <iostream>
#include <string>
#include <sstream>

#define TESTLEVEL 5

#include "sablonok.hpp"
#include "fancy_iterators.hpp"
#include "gtest_lite.h"

int itomb[] = { 1, 8, -3, 4, 5 };
double dtomb[] = { 1.2, -2.1, 3.91, -4.1, 5.1, -10 };

int main() {

#if TESTLEVEL == 0
    printEach(itomb, itomb+5);
    std::cout << std::endl;
    printEach(dtomb, dtomb+5);
#endif // TESZLEVEL == 0

#if TESTLEVEL == 1
    printEach(itomb, itomb+5, std::cout);
    std::cout << std::endl;
    // default paraméterrel is kipróbáljuk
    printEach(dtomb, dtomb+5);
#endif // TESZLEVEL == 1

#if TESTLEVEL >= 2
    TEST(printEach, format) {
        std::stringstream out;
        printEach(itomb, itomb+4, out, "; ");
        EXPECT_EQ(std::string("1; 8; -3; 4\n"), out.str());
        out.str("");
        printEach(itomb, itomb+3, out, "// ");
        EXPECT_EQ(std::string("1// 8// -3\n"), out.str());
    END }
#endif // TESTLEVEL >=2


#if TESTLEVEL >= 3
    /// Annak vizsgálata, hogy a pre/post-inkremens operátorokon
    /// kívül használ-e más aritmetikai operátort a printEach.
    counting_iterator<int> i1(10), i2(15);      /// speciális iterátor ami sorozatot ad
    printEach(i1, i2);
#endif // TESTLEVEL >= 3

#if TESTLEVEL >= 4
    TEST(szamol_ha_negativ, int) {
        EXPECT_EQ(1, szamol_ha_negativ(itomb, itomb+5));
    END }

    TEST(szamol_ha_negativ, double) {
        EXPECT_EQ(3, szamol_ha_negativ(dtomb, dtomb+6));
    END }
#endif // TESTLEVEL >=4

#if TESTLEVEL >= 5
    TEST(szamol_ha, int) {
        EXPECT_EQ(3, szamol_ha(itomb, itomb+5, nagyobb_mint<int>(3)));
    END }

    TEST(szamol_ha, double) {
        EXPECT_EQ(2, szamol_ha(dtomb, dtomb+6, nagyobb_mint<double>(3.14)));
    END }
#endif // TESTLEVEL >=5

    return 0;
}
