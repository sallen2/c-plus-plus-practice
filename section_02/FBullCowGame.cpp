#include "HeaderFiles/FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    Reset();
}


int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "planets";
    constexpr int32 MAX_TRIES = 8;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    return;
}

bool FBullCowGame::IsGameWon() const
{

    return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
    if(false){
        
        return EWordStatus::Not_Isogram;
    }else if(false){

        return EWordStatus::Wrong_Length;
    } else if(false){

        return EWordStatus::Not_Lowercase;
    }else{

        return EWordStatus::OK;
    }
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
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

    return BullCowCount;
}