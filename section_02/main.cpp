#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

int main()
{
  PrintIntro();

  constexpr int NUM_OF_TURNS = 5;
  for (int i = 0; i < NUM_OF_TURNS; i++)
  {
    string Guess = GetGuess();
    cout << "Your guess was " << Guess << endl;
    cout << endl;
  }

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

string GetGuess()
{
  string Guess = "";
  cout << "Enter your guess: ";
  getline(cin, Guess);

  return Guess;
}
