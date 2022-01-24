#include <iostream>
#include <string>
#include <sstream>
#include "bengisuozdemir_Ozdemir_Bengisu_hw3_header.h"
using namespace std;
/* Bengisu Ozdemir 26683 29.03.21
The purpose of this program is displaying all of the ordered subsequences as in every possible outcome.
The aim of this homework is to improve using pointers and linked lists.
*/
int main()
{
	cout << "Please enter the numbers in a line: ";
	string numbers;
	int num;
	int toBeDeleted;
	SubSeqsList myList;
	getline(cin,numbers);
	istringstream strstream(numbers);
	while(strstream>>num)
	{
		if(num>=0)
		{
			cout << "Subsequence(s) containing "<<num<<" has/have been added"<<endl;
			myList.AddList(num);
		}
		else
		{
			toBeDeleted = -1*num;
			if(!myList.findToBeDeleted(toBeDeleted))
			{
				cout << "There is no subsequence that contains " <<toBeDeleted <<" to be deleted" << endl;
			}
			else
			{
				cout << "All subsequence(s) containing "<<toBeDeleted<<" has/have been deleted" << endl;
			}
		}
	}
	cout <<endl<< "FINAL CONTENT" << endl;
	if(myList.IsEmpty())
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		myList.Display();
	}
	return 0;
}