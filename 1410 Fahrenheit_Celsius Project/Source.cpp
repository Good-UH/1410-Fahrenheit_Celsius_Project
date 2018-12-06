/*
Write a program that converts Celsius to Fahrenheit and vice versa
Choice 1 from Cel to Fah and Choice 2 from Fah to Cel and any other choice will ask again
After the first calculation ask the user if he wants to continue or end the program
ASSUME THE USER ALWAYS INPUTS A VALID INTEGER
*/

#include <iostream>
using namespace std;

//Init a universal variable
double celsius, Celfah;
double fahrenheit, Fahcel;
int choice;
char answer;
double temperature;

//Functions Request, Print, and Verify Info
int getChoice();
char getAnswer();
void print();
bool isInfoValid(double x);

int main() {

	do { //Do while is used to print the instructions to the user at least once and continue the program
		
		print(); //print choices
		choice = getChoice(); //get choice function

		if (choice == 1) //convert Cel to Fah when choice 1 is selected
		{
			cout << "\n\tPlease enter the temperature in Celsius: ";
			cin >> temperature;
			Celfah = (temperature * (9.0 / 5.0)) + 32;
			cout << "\nThe temperature in Fahrenheit is: " << Celfah << " degrees\n";
		}
		else if (choice == 2) //convert Fah to Cel when choice 2 is selected
		{
			cout << "\n\tPlease enter the temperature in Fahrenheit: ";
			cin >> temperature;
			Fahcel = (temperature - 32) * (5.0 / 9.0);
			cout << "\nThe temperature in Celsius is: " << Fahcel << " degrees\n";
		}

		answer = getAnswer(); //get answer function

	} while (answer == 'y'); //repeat the program while the user enters 'y' to continue
}

int getChoice() //validate the choice
{
	cout << "Enter your choice: "; //request choice from the user
	cin >> choice;
	if (isInfoValid(choice)) //if the choice is valid return it
	{
		return choice;

	}
	else //if it is not a valid choice show error to user and request again
	{
		cout << "\n\t" << choice << " IS NOT A VALID CHOICE! (ENTER 1 OR 2)\n\n\tPlease make a valid selection!\n\n";
		print();
		getChoice();
	}
}

char getAnswer() //validate the answer
{
	cout << "\nDo you want to continue (y or n): "; //request answer from the user
	cin >> answer;

	if (answer == 'y') //if answer is 'y' return the answer 
	{
		return answer;
	}
	else if (answer == 'n') //if answer is 'n' end the program
	{
		cout << "\n\n\tThank You for using the Temperature Converter! Come back soon!\n\n";
		system("pause");
		exit(0);
	}
	else //if it is not a valid choice show error to user and request again
	{
		cout << "\n\t" << answer << " IS NOT VALID. Type (y or n)\n";
		getAnswer();
	}
}

void print() //print the menu to the user
{
	cout << "\tMenu\n";
	cout << "---------------------------\n\n";
	cout << "1- Celsius to Fahrenheit\n";
	cout << "2- Farenheit to Celsius\n\n";
}

bool isInfoValid(double x) //function to validate the choices
{
	if (x == 1 || x == 2) {
		return true;
	}
	else
	{
		return false;
	}
}
