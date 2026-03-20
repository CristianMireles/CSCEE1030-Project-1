#include <iostream>

using namespace std;

int main()
{
    string userName;
    bool userNameAccepted = false; //variable to update wether the username is good or not
	cout<<"Enter your username using letters, numbers, and spaces: "<<endl;
	getline(cin, userName);
	
	while(userNameAccepted == false) //run loop while the username is considered not accepted
	{
		for(int i=0; i<userName.length(); ++i)
		{
			if(isalnum(userName.at(i)) || isspace(userName.at(i))) 
			{
				userNameAccepted=true; 
			}
			else //if its not a number an alphabetic character or a space it will do the else
			{
				cout<<"Username incorrect please re-enter: ";
				getline(cin, userName); 
				userNameAccepted = false; //set acceptable to false to run while loop again since it might have been changed to true on a previous character
				break; //takes program out of for loop to the while loop which will run again starting character check at beginning of new string
			}		
		}
	}
	cout<<"Hello "<< userName<< "!"<< endl;

    int randNum1, randNum2;
    enum Menu {Multiply = 1, Divide = 2, Average = 3, Reveal = 4, GiveUp = 5, Exit = 6};

    do
    {
        srand(time(NULL));
        randNum1 = rand()%51 + 50; //random number between 50 - 100  inclusive
        randNum2 = rand()%51 + 50; 

    } while (randNum1 > randNum2);
    //cout << randNum1 << " " << randNum2 << endl; This was to check output of numbers

    bool stopPlaying = false; // if they chose to stop playing update this to true
    bool revealNum = false; // if user choses to reveal number update this variable to have the value revealed
    bool correctAnswer = false; // update if they get correct so that we can ask further question about restarting
    char restartGame; // if user wins ask if they want to restart the game and update this variable

    int playerPoints = 50; //intialize thier points update throughout game
    int menuChoice; //collect users choice for game
    float playerGuess = 0.00;   // float to get decimals


    do
    {

        cout<<"1. Multiply"<< endl;
		cout<<"2. Divide"<< endl;
		cout<<"3. Average"<< endl;
		cout<<"4. Reveal"<< endl;
		cout<<"5. Giveup"<< endl;
		cout<<"6. Exit"<< endl;
        if(revealNum == true)
        {
            cout<< "The first random number is " << randNum1<< endl;
        }
		cout<<"Enter choice: ";
		cin>>menuChoice;

        switch(menuChoice)
        {
            case Multiply:
				cout<< "Enter your guess for the product: ";
				cin>>playerGuess;
				if (((randNum1 * randNum2)-abs(playerGuess)<50) && ((randNum1 * randNum2)-abs(playerGuess)>-50))
				{
					cout<<"Your guess was close enough. You win."<< endl;
					playerPoints+=5;
					cout<< "Your updated points are: " << playerPoints<< endl;
					correctAnswer=true;
				}
				else
				{
					cout << "Your guess was wrong you lose 1 point." << endl;
                    cout << "Current points: " << playerPoints << endl;
					playerPoints-=1;
				}
                break;
            case Divide:
                cout << "Guess the qoutient of the two randum numbers only input 2 numbers after decimal(Example 0.45): ";
                cin >> playerGuess;
                if(playerGuess >= (randNum1/randNum2)-(0.5) && playerGuess <= (randNum1/randNum2)+(0.5))
                {
                    playerPoints = playerPoints + 5;
                    cout << "Your guess was correct and gain 5 points." << endl;
                    cout << "Current points: " << playerPoints << endl;
                    correctAnswer=true;             
                }
                else
                {
                    playerPoints = playerPoints - 1;
                    cout << "Your guess was wrong you lose 1 point." << endl;
                    cout << "Current points: " << playerPoints << endl;
                }
                cout << randNum1 / randNum2 << endl;
                break;
            case Average:
                cout<< "Enter your guess for the average of the two random numbers: ";
				cin>>playerGuess;
                if (((((randNum1 + randNum2)/2.0)-abs(playerGuess))<2.1) && ((((randNum1 + randNum2)/2.0)-abs(playerGuess))>-2.1))
				{
					cout<<"Your guess was close enough. You win."<< endl;
					playerPoints+=5;
					cout<< "Your updated points are: " << playerPoints<< endl;
					correctAnswer=true;
				}
				else
				{
					cout << "Your guess was wrong you lose 1 point." << endl;
                    cout << "Current points: " << playerPoints << endl;
					playerPoints-=1;
				}
                break;
            case Reveal:
                cout << "Using 3 points to reveal 1st number." << endl; 
                cout << "The first number is " << randNum1 << endl;
                playerPoints = playerPoints - 3 ;
                cout << "Current points: " << playerPoints << endl;
                revealNum=true;
                break;
            case Exit:
                cout << "Thanks for playing " << userName << " final score: " << playerPoints << endl;
                cout << "Exiting the program" << endl;
                stopPlaying = true;
                break;
            default:
                cout << "Wrong choice. Please enter again."<< endl;
        }
        cout<< endl;
    }while(stopPlaying == false);

    return 0;
}