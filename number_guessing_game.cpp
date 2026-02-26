#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int secretNumber = rand() % 10 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 10." << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber)
        {
            cout << "Too high! Try again.\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low! Try again.\n";
        }
        else
        {
            cout << "Correct! You guessed it in "
                 << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}