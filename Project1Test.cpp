#include <iostream>

using namespace std;
//my name is cristian
int main()
{
    char userName;
    int playerPoints = 50;
    int randNum1, randNum2;
    enum Menu {Multiply = 1, Divide = 2, Average = 3, Reveal = 4, GiveUp = 5, Exit = 6};

    do
    {
        srand(time(NULL));
        randNum1 = rand()%51 + 50; //random number between 50 - 100  inclusive
        randNum2 = rand()%51 + 50; 

    } while (randNum1 > randNum2);
    //cout << randNum1 << " " << randNum2 << endl; This was to check output of numbers
    int menuChoice;
    cout << "Enter your Menu Choice (1-6)" << endl;
    cin >> menuChoice;
     switch(menuChoice)
     {
        case Divide:
            cout << "Guess the qoutient of the two randum numbers only input 2 numbers after decimal(Example 0.45)" << endl;
            float guess;// float to get decimals
            cin >> guess;
            if(guess >= (randNum1/randNum2)-(0.5) && guess <= (randNum1/randNum2)+(0.5))
            {
                playerPoints = playerPoints + 5;
                cout << "Your guess was correct and gain 5 points." << endl;
                cout << "Current points: " << playerPoints << endl;
                cout << "Do you want to play again." << endl;               
            }
            else
            {
                playerPoints = playerPoints - 1;
                cout << "Your guess was wrong you lose 1 point." << endl;
                cout << "Current points: " << playerPoints << endl;
            }
            cout << randNum1 / randNum2 << endl;
            break;
        case Reveal:
            cout << "Using 3 points to reveal 1st number." << endl; 
            cout << "The first number is " << randNum1 << endl;
            playerPoints = playerPoints - 3 ;
            cout << "Current points: " << playerPoints << endl;
            break;
        case Exit:
            cout << "Thanks for playing " << userName << " final score: " << playerPoints << endl;
            cout << "Exiting the program" << endl;
            break;
     }

    return 0;
}