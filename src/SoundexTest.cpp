#include <string>
#include "Soundex.h"

#include "gmock/gmock.h"
using namespace testing;

//Fixture-Klasse: Definiert Funktionen und Memberdaten für eine Reihe von
//miteinander verwanten Tests um Redundanz zu vermeiden.
//(Agiert hinter den Kulissen) Jeder Test muss nun von TEST auf TEST_F 
//geändert werden. F steht für Fixture (eingene Fixture verwenden)
//Vorteil: Aenderung muss nur noch an einer Stelle vorgenommen werden
//z.B bei der Instanzierung von Soundex muss noch eine Sprache angegeben werden
class SoundexEncoding : public Test {
public:
 Soundex soundex;
};


TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encode("A"), Eq("A000")); 
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
   ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
   ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
	ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

