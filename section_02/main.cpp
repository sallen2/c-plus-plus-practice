#include <iostream>
#include <string>
#include "HeaderFiles/FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();

FText GetValidGuess();
FBullCowGame BullCowGame;

bool AskToPlayAgain();

int main()
{

  bool playAgain = "";
  do
  {
    PrintIntro();
    PlayGame();
    playAgain = AskToPlayAgain();
  } while (playAgain == true);

  return 0;
}

void PrintIntro()
{
  std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
  std::cout << "Can you guess the " << BullCowGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
  std::cout << std::endl;

  return;
}

void PlayGame()
{
  BullCowGame.Reset();
  int32 MaxTries = BullCowGame.GetMaxTries();
  // change for to while when checking guess
  while (!BullCowGame.IsGameWon() && BullCowGame.GetCurrentTry() <= MaxTries)
  {
    FText Guess = GetValidGuess(); 

    FBullCowCount BullCowCount = BullCowGame.SubmitValidGuess(Guess);
    
    std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
    std::cout << "Cows: " << BullCowCount.Cows << std::endl;
    std::cout << "Your guess was " << Guess << std::endl;
    std::cout << std::endl;
  }

  PrintGameSummary();

  return;
}

FText GetValidGuess()
{
  FText UGuess = "";
  EGuessStatus Status = EGuessStatus::InvalidStatus;
  do
  {
    int32 CurrentTry = BullCowGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << '.';
    FText Guess = "";
    std::cout << " Enter your guess: ";
    std::getline(std::cin, Guess);
    Status = BullCowGame.CheckGuessValidity(Guess);
    switch (Status)
    {
    case EGuessStatus::Not_Isogram:
      std::cout << "Not Isogram\n";
      break;
    case EGuessStatus::Not_Lowercase:
      std::cout << "Not Lowercase\n";
      break;
    case EGuessStatus::Wrong_Length:
      std::cout << "Wrong Length\n";
      break;
    default:
      UGuess = Guess;
    }
    std::cout << std::endl;
  } while (Status != EGuessStatus::OK);
  return UGuess;
}

bool AskToPlayAgain()
{
  FText Play = "";
  std::cout << "Do you want to play again with the same word? yes/no: ";
  std::getline(std::cin, Play);
  return (Play[0] == 'y' || Play[0] == 'Y');
}

void PrintGameSummary()
{
  if (BullCowGame.IsGameWon())
  {
    std::cout << "You Won\n";
  }
  else
  {
    std::cout << "Bad Luck\n";
  }
}
