#include "HeaderFiles/FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const{ return bGameIsWon; }

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "planet";
    constexpr int32 MAX_TRIES = 8;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    bGameIsWon = false;
    return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;

    FBullCowCount BullCowCount;

    for (int32 i = 0; i < MyHiddenWord.length(); i++)
    {
        for (int32 j = 0; j < MyHiddenWord.length(); j++)
        {
            if (Guess[i] == MyHiddenWord[j] && j == i)
            {
                BullCowCount.Bulls++;
            }
            else if (Guess[i] == MyHiddenWord[j])
            {
                BullCowCount.Cows++;
            }
        }
    }

    if(BullCowCount.Bulls == MyHiddenWord.length()){
        
        bGameIsWon = true;

    }else{
        bGameIsWon = false;
    }

    return BullCowCount;
}

