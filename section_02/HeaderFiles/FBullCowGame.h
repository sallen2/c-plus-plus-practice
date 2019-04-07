#pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum class EWordStatus{
  OK,
  Not_Isogram,
  Wrong_Length,
  Already_Entered,
  Not_Lowercase
};

struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

class FBullCowGame
{
public:
  FBullCowGame();
  void Reset();
  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;

  EWordStatus CheckGuessValidity(FString) const;
  bool IsGameWon() const;

  FBullCowCount SubmitGuess(FString);

private:
  int32 MyCurrentTry;
  int32 MyMaxTries;
  FString MyHiddenWord;
};