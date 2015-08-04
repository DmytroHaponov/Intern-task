#include <gtest/gtest.h>
#include "forfunc.h"
#include "unitfunc.h"
#include <QString>

TEST(test001, resulttest)
{
    //Actual
    afunc("1.txt", "11.txt");
   string actual = unitread("11.txt");

    //Expected
    string expected = "s p p o k k i h e a ";

    //Check
    EXPECT_EQ(expected, actual);
}

TEST(test002, resulttest)
{
    //Actual
    afunc("2.txt", "22.txt");
   string actual = unitread("22.txt");

    //Expected
    string expected = "W S S S R R P O L L K J J H F E D D A ";

    //Check
    EXPECT_EQ(expected, actual);
}

TEST(test003, resulttest)
{
    //Actual
    afunc("3.txt", "33.txt");
   string actual = unitread("33.txt");

    //Expected
    string expected = "W S R R R P P P P P L L K H G D ";

    //Check
    EXPECT_EQ(expected, actual);
}

TEST(test004, resulttest)
{
    //Actual
    afunc("4.txt", "44.txt");
   string actual = unitread("44.txt");

    //Expected
    string expected = "U P O O N K K K K J J I I H F E D A ";

    //Check
    EXPECT_EQ(expected, actual);
}

TEST(test005, resulttest)
{
    //Actual
    afunc("5.txt", "55.txt");
   string actual = unitread("55.txt");

    //Expected
    string expected = "U R Q P P N M M L L L L L J I H F F F E A ";

    //Check
    EXPECT_EQ(expected, actual);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest( &argc, argv);
    return RUN_ALL_TESTS();
}
