/*Purpose of this program is to have the user input numbers that will then be pushed into a vector. Then the user will have the option to search the vector or sort the vector. If they choose to sort they can pick from
bubble, selection, and insertion sorts. If they choose to search then they will pick from binary and linear search. Then the program outputs to the user.*/



#include "IntSequence.h"
#include <iostream>
#include<vector>
#include <sstream>
#include <string>

using namespace std;

void main_menu()
{
	cout << "1. Read" << endl;
	cout << "2. Print" << endl;
	cout << "3. Sort" << endl;
	cout << "4. Search" << endl;
	cout << "5. Quit" << endl;

}
int main()
{
	//initialize object pointer
	IntSequence *intSeq = NULL;
	//initialize user input
	int mainChoice = 0;
	//while statement to run while they dont exit
	while (mainChoice != 5)
	{
		//get user choice
		main_menu();
		cin >> mainChoice;
		//switch statement to go to different parts of the menu
		switch (mainChoice)
		{
		case 1:
			delete intSeq;
			intSeq = new IntSequence();
			intSeq->_read();
			break;
		case 2:
			cout << "Sequence: ";
			intSeq->_print();
			break;
		case 3:
			intSeq->_sort();
			break;
		case 4:
			intSeq->_search();
			break;
		case 5:
			cout << "Than you for using this program,bye." << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
		}
	}
	return 0;
}