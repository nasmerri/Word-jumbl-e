/*By hand, choose 10 single code words of your choice, and write down a hint for each word.
Create a new C++ project called Keywords
This Code Breaker Training Simulation Program should give the user directions and tell them what it is and how to use it based of the background description above.
Then your Code Breaker Training Simulation Program should randomly select 3 of the 10 words that are coded in your program.
Your code breaker will scramble each word on the fly and different each run randomly.
Now make the user try to solve each one of the three randomly picked coded word from your random list.
Each turn you should give your user feedback on if they got the guess correct or not.
You should also offer the user help.
At the end, you should display their stats and ask if they would like to try again.
After you have a project, publish your code to a new GitHub repository.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	for (int i = 0; i < 3; ++i)
	{


		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =

		{
			{"laser", "There are alot of these protecting the safe."},
			{"watch", " This is key to keeping track oif time during a mission."},
			{"tranquilizer", "You can use this to put your enemies to sleep."},
			{"jet", "We will take this to get to missions ASAP."},
			{"a.i.", "This system will help you navigate through challenging obstacles."},
			{"robot", "Many of our engineers work on this technology, for environments not safe for humans to be in."},
			{"headquarters", "This is homebase where all intel and agents meet."},
			{"comrades", "These will be your lifeline on the job. Don't leave anyone behind, there safety come before the mission."},
			{"companions", "Each agent has an animal partner."},
			{"gadgets", "These are tools to use in a tight spot."}
		};


		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD]; // word to guess 
		string theHint = WORDS[choice][HINT]; // hint for guess 
		string jumble = theWord; // jumbled version of the word 
		int length = jumble.size();
		// jumbling word 
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;


		}




		cout << "\t\t\tWelcome to the beginning of the rest of your life, Spy jumble!\n\n";
		cout << "The following is a test to see your place in this secret service, unscramble the following words to the best of your ability.\n";
		cout << "Now you may run into trouble, enter 'hint' for a clue on the word.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		cout << "The jumble is: " << jumble;

		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;

		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, That's not it.";

			}
			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "\n That's it you guessed it!\n";

		}
	}
	cout << "\nThanks for playing.\n";

	return 0;
}
