/**
 * \file perziszt.cpp
 */

#define TESTLEVEL 2




#if TESTLEVEL >= 2

#include <iostream>
#include <sstream>

#include "palkalmazott.h"

#if TESTLEVEL >= 3
# include "pirodistak.h"
#endif

#include "gtest_lite.h"

void perzTeszt(){

    TEST(perzist, Alkalmazott) {
        std::stringstream ss;
        Alkalmazott  ld("Lusta Dick", 100);
        PAlkalmazott(ld).write(ss);
        PAlkalmazott rsLd("", 0);
        rsLd.read(ss);
        EXPECT_EQ(ld.getNev(), rsLd.getNev());
        EXPECT_EQ(ld.getFiz(), rsLd.getFiz());
    END }

#if TESTLEVEL >= 3
    TEST(perzist, CsopVez) {
        std::stringstream ss;
        CsopVez gt("Mr. Gatto", 100, 5);
        PCsopVez(gt).write(ss);
        PCsopVez rsGt("", 0, 0);
        rsGt.read(ss);
        EXPECT_EQ(gt.getNev(), rsGt.getNev());
        EXPECT_EQ(gt.getFiz(), rsGt.getFiz());
        EXPECT_EQ(gt.getCs(), rsGt.getCs());
    END }
#endif

#if TESTLEVEL >= 4
    TEST(perzist, HatIdeju) {
        std::stringstream ss;
        HatIdeju gr("Grabovszki", 100, 5000);
        PHatIdeju(gr).write(ss);
        PHatIdeju rsGr("", 0, 0);
        rsGr.read(ss);
        EXPECT_EQ(gr.getNev(), rsGr.getNev());
        EXPECT_EQ(gr.getFiz(), rsGr.getFiz());
        EXPECT_EQ(gr.getIdo(), rsGr.getIdo());
    END }
#endif

#if TESTLEVEL >= 5
    TEST(perzist, HatIdCsV) {
        std::stringstream ss;
        HatIdCsV tf("Mr. Tejfel", 100, 5555, 3);
        PHatIdCsV(tf).write(ss);
        PHatIdCsV rstf("", 0, 0, 0);
        rstf.read(ss);
        EXPECT_EQ(tf.getNev(), rstf.getNev());
        EXPECT_EQ(tf.getFiz(), rstf.getFiz());
        EXPECT_EQ(tf.getCs(), rstf.getCs());
        EXPECT_EQ(tf.getIdo(), rstf.getIdo());
    END }
#endif

#if TESTLEVEL >= 6
    TEST(perzist, HatIdCsVezH) {
        std::stringstream ss;
        HatIdCsV tf("Mr. Tejfel", 100, 5555, 3);
        HatIdCsVezH  safi("Safranek", 100, 55, tf);
        PHatIdCsVezH(safi).write(ss);
        PHatIdCsVezH rsafi("", 0, 0, tf);
        rsafi.read(ss);
        EXPECT_EQ(safi.getNev(), rsafi.getNev());
        EXPECT_EQ(safi.getFiz(), rsafi.getFiz());
        EXPECT_EQ(safi.getCs(), rsafi.getCs());
        EXPECT_EQ(safi.getIdo(), rsafi.getIdo());
    END }
#endif

}

#endif
