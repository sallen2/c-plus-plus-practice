#include <iostream>
#include <string>
#include "HeaderFiles/FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BullCowGame;

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
  for (int32 i = 0; i < MaxTries; i++)
  {
    FText Guess = GetGuess(); //TODO: check for valid guess
    FBullCowCount BullCowCount = BullCowGame.SubmitGuess(Guess);

    std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
    std::cout << "Cows: " << BullCowCount.Cows << std::endl;
    std::cout << "Your guess was " << Guess << std::endl;
    std::cout << std::endl;
  }

  // TODO: summarize game
  return;
}

FText GetGuess()
{
  int32 CurrentTry = BullCowGame.GetCurrentTry(); 
  std::cout << "Try " << CurrentTry << '.';
  FText Guess = "";
  std::cout << " Enter your guess: ";
  std::getline(std::cin, Guess);
  
  return Guess;
}

bool AskToPlayAgain()
{
  FText Play = "";
  std::cout << "Do you want to play again? yes/no: ";
  std::getline(std::cin, Play);
  return (Play[0] == 'y' || Play[0] == 'Y');
}
