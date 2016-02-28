#ifndef INTSEQUENCE_H
#define INTSEQUENCE_H
#include<vector>
#include<iostream>

using namespace std;

class IntSequence
{
public:
	IntSequence(); // default constructor
	void _read(); // read data elements
	void _print(); // print data elements
	void _sort(); // sort the sequence
	void _search(); // search for in the sequence
	void sort_menu();
	void search_menu();

private:
	vector<int> data_seq; // vector of data elements
	int count; // actual num of elements
	void linear_search();
	void binary_search();
	void insertion_sort();
	void bubble_sort();
	void selection_sort();
};

#endif // INTSEQUENCE_H