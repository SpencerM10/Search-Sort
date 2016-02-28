#include "IntSequence.h"
#include<vector>
#include<iostream>
#include <sstream>
#include <string>

using namespace std;
//constructor
IntSequence::IntSequence()
{
	this->data_seq.clear();
	this->count = 0;
}
void IntSequence::_read()
{
	string line;

	int ch;
	//while loop to read in user input
	while (true)
	{
		cout << "Enter the next element (Enter 'q' to stop):" << endl;
		cin >> line;
		//make sure user doesnt input q to stop 
		if (line != "q")
		{
			//add to the vector what the user inputs
			istringstream iss(line);
			if (!(iss >> ch))
			{
				continue;
			}
			data_seq.push_back(ch);
			//update the count each time
			this->count++;
		}
		else
			break;
	}

}
void IntSequence::_print()
{
	//print out what the vector contains
	for (std::vector<int>::iterator it = data_seq.begin(); it != data_seq.end(); ++it)
		cout << *it << "  ";
	cout << endl;
}
void IntSequence::_sort()
{
	//display sort menu and read in users selection
	sort_menu();
	string line;
	cin >> line;
	istringstream iss(line);
	int sortOption = 0;
	iss >> sortOption;
	//swtich statement for kind of sort the user wants
	switch (sortOption)
	{
	case 1:
		//insertion sort
		insertion_sort();
		break;
	case 2:
		//sele sort
		selection_sort();
		break;
	case 3:
		//bubble
		bubble_sort();
		break;
	default:
		//do nothing
		break;
	}
}
void IntSequence::_search()
{
	//display search menu and get search the user wants
	search_menu();
	int searchOption = 0;
	string line;
	cin >> line;
	istringstream iss(line);
	iss >> searchOption;
	//switch statement for the type of search user wants
	switch (searchOption)
	{
	case 1:
		//seq search
		this->linear_search();
		break;
	case 2:
		//binary search
		this->binary_search();
		break;
	default:
		//do nothing
		break;
	}
}
//sort menu
void IntSequence::sort_menu()
{
	cout << "1. Insertion sort" << endl;
	cout << "2. Selection sort" << endl;
	cout << "3. Bubble sort" << endl;
	cout << "4. Quit" << endl;
}
//search menu
void IntSequence::search_menu()
{
	cout << "1. Sequential search" << endl;
	cout << "2. Binary search" << endl;
	cout << "3. Quit" << endl;
}
void IntSequence::linear_search()
{
	cout << "Enter the key to find: " << endl;
	//initialize key
	//read in users key
	int key = 0;
	string line;
	cin >> line;
	istringstream iss(line);
	iss >> key;
	_print();
	// in case key is not found
	int index = -1;
	//for loop to seach the vector for the users key
	for (std::vector<int>::size_type i = 0; i != data_seq.size(); i++)
	{
		if (data_seq[i] == key)
		{
			index = i;
			break;
		}
	}
	//if key = -1 nothing was found 
	if (key == -1)
	{
		cout << "Key not found" << endl;
	}
	//else key found and the location + 1 is the amount of checks
	else
	{
		cout << "Key found at index " << index << endl;
		cout << "Search with " << (index + 1) << " comparison(s)." << endl;
	}
}
void IntSequence::binary_search()
{
	cout << "Enter the key to find: " << endl;
	//initialize the key
	//get the key from user
	int key = 0;
	string line;
	cin >> line;
	istringstream iss(line);
	iss >> key;
	//initialize left and mid
	size_t mid, left = 0;
	//right equal to size of vector
	size_t right = data_seq.size();
	int index = -1;
	//initialize comparisons to 0
	int comp = 0;
	//while left is less than the right which starts at size of vector
	while (left < right)
	{
		//set mid point of the vector
		mid = left + (right - left) / 2;
		//count the number of comparisons
		comp++;
		//if key is greater than mid
		if (key > data_seq[mid])
		{
			left = mid + 1;
		}
		//if key is less than mid
		else if (key < data_seq[mid])
		{
			right = mid;
		}
		else
		{
			index = mid;
			//key found
			break;
		}
	}
	//key was not found
	if (index == -1)
	{
		cout << "Key not found" << endl;
	}
	//print the index where key was found and how many times the comparison was done
	else
	{
		_print();
		cout << "Key found at index " << index << endl;
		cout << "Search with " << comp << " comparison(s)." << endl;
	}
}
void IntSequence::insertion_sort()
{
	cout << "===Insertion Sort====================================" << endl;
	unsigned int i, j;
	int max;
	//for loop length of vector
	for (i = 1; i<data_seq.size(); i++)
	{
		//what index j is being compared to
		max = data_seq[i];
		//j always equals index of i after comparing
		j = i;
		//while loop to run while one spot back is greater than the next spot
		while (j>0 && data_seq[j - 1] > max)
		{	//swap where they are located
			data_seq[j] = data_seq[j - 1];
			//decrement of j
			j = j - 1;
		}
		//index of j now is the higher value
		data_seq[j] = max;
		cout << "Insert " << max << ":\t";
		this->_print();
	}
	cout << "Sequence: ";
	this->_print();
}
void IntSequence::bubble_sort()
{
	cout << "===Bubble Sort====================================" << endl;
	unsigned int i, j;
	//for loop to iterate through the vector
	for (i = 0; i<data_seq.size(); i++)
	{
		//for loop to swap when j > j+1
		for (j = 0; j<data_seq.size() - i - 1; j++)
		{
			//if j > j+1 then swap them
			if (data_seq[j] > data_seq[j + 1])
			{
				//store j in temp
				int temp = data_seq[j];
				//put j into j+1
				data_seq[j] = data_seq[j + 1];
				//complete the swap
				data_seq[j + 1] = temp;
			}
		}
		cout << "Iteration " << (i + 1) << ":\t";
		this->_print();
	}
}
void IntSequence::selection_sort()
{
	cout << "===Selection Sort====================================" << endl;
	unsigned int i, j;
	unsigned int min_index;
	//first loop to hold the variable that will potentially be switched
	for (i = 0; i<data_seq.size() - 1; i++)
	{
		//set to the current index of vector
		min_index = i;
		//second loop to iterate and check if there should be a new min
		for (j = i + 1; j<data_seq.size(); j++)
		{
			//if there is a new min set it equal to j
			if (data_seq[j] < data_seq[min_index])
			{
				min_index = j;
			}
		}
		//if min_index isnt equal to i then there is a new min
		if (min_index != i)
		{
			//hold what was in i
			int temp = data_seq[i];
			//set index of i to new min
			data_seq[i] = data_seq[min_index];
			//set the index of min to swapped variable
			data_seq[min_index] = temp;
		}
		cout << "Min " << data_seq[i] << ", swap with " << data_seq[min_index] << ":\t";
		this->_print();
	}
	cout << "Sequence: ";
	this->_print();
}