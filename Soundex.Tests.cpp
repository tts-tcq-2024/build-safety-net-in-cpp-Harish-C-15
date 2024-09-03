#include <gtest/gtest.h>
#include "Soundex.h"

// Test cases for the empty string check
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test cases for the single character check
TEST(SoundexTest, HandlesSingleCharacter) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string expected = std::string(1, c) + "000";
        EXPECT_EQ(generateSoundex(std::string(1, c)), expected);
    }
}


// Test cases for the names with vowels and certain consonants that should be ignored
TEST(SoundexTest, HandlesIgnoredCharacters) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
    EXPECT_EQ(generateSoundex("HW"), "H000");
}

// Test cases for the names with adjacent consonants that should be ignored
TEST(SoundexTest, HandlesAdjacentConsonants) {
    EXPECT_EQ(generateSoundex("BB"), "B100");
    EXPECT_EQ(generateSoundex("CC"), "C200");
    EXPECT_EQ(generateSoundex("DD"), "D300");
    EXPECT_EQ(generateSoundex("FF"), "F100");
    EXPECT_EQ(generateSoundex("GG"), "G200");
    EXPECT_EQ(generateSoundex("JJ"), "J200");
    EXPECT_EQ(generateSoundex("KK"), "K200");
    EXPECT_EQ(generateSoundex("LL"), "L400");
    EXPECT_EQ(generateSoundex("MM"), "M500");
    EXPECT_EQ(generateSoundex("NN"), "N500");
    EXPECT_EQ(generateSoundex("PP"), "P100");
    EXPECT_EQ(generateSoundex("QQ"), "Q200");
    EXPECT_EQ(generateSoundex("RR"), "R600");
    EXPECT_EQ(generateSoundex("SS"), "S200");
    EXPECT_EQ(generateSoundex("TT"), "T300");
    EXPECT_EQ(generateSoundex("VV"), "V100");
    EXPECT_EQ(generateSoundex("XX"), "X200");
    EXPECT_EQ(generateSoundex("YY"), "Y000");
    EXPECT_EQ(generateSoundex("ZZ"), "Z200");
}

// Test cases for the longer names that require truncation
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Devegowda"), "D123");
    EXPECT_EQ(generateSoundex("MSD"), "M230");
    EXPECT_EQ(generateSoundex("Raina"), "R500");
    EXPECT_EQ(generateSoundex("Balaji"), "B420");
    EXPECT_EQ(generateSoundex("Singh"), "S520");
    EXPECT_EQ(generateSoundex("NeilPattrickHarris"), "N413");
    EXPECT_EQ(generateSoundex("Rajamouli"), "R254");
}

// Test cases for the names with hyphens or spaces
TEST(SoundexTest, HandlesHyphensAndSpaces) {
    EXPECT_EQ(generateSoundex("Ruturaj-Gaikwad"), "R362");
    EXPECT_EQ(generateSoundex("Dinesh-Karthik"), "D526");
    EXPECT_EQ(generateSoundex("Virat Kohli"), "V632");
    EXPECT_EQ(generateSoundex("Amithab Bachhan"), "A531");
}

// Test cases for the names with non-alphabetic characters
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("J'Bumrah"), "J156");
    EXPECT_EQ(generateSoundex("Harish@15"), "H620");
}
