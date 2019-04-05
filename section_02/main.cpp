#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
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
  constexpr int WORD_LENGTH = 10;
  cout << "Welcome to Bulls and Cows, a fun word game!\n";
  cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
  cout << endl;

  return;
}

void PlayGame()
{
  constexpr int NUM_OF_TURNS = 5;
  for (int i = 0; i < NUM_OF_TURNS; i++)
  {
    string Guess = GetGuess();
    cout << "Your guess was " << Guess << endl;
    cout << endl;
  }
}

string GetGuess()
{
  string Guess = "";
  cout << "Enter your guess: ";
  getline(cin, Guess);

  return Guess;
}

bool AskToPlayAgain()
{
  string Play = "";
  cout << "Do you want to play again? true/false: ";
  cin >> Play;
  if (Play == "true")
  {
    return true;
  }
  else if (Play == "false")
  {
    return false;
  }
  else
  {
    return false;
  }
}
