//==============================================================================
// Name        : practical3.cpp
// Author      : your name
// Version     : 1.0
// Description : practical 3 test program to exercise the simple sort algorithms
//==============================================================================

#include <string>
#include <cstdlib>	// srand
#include <ctime>	// time
#include "Array.h"
#include "Sort.h"

using namespace std;


// PostCondition: returns difference in the largest and smallest elements in the array  
int maxDiff(const Array<int> & data) {
	// no additional space required as we don't sort the array
	int max = data[0], min = data[0];
	for (int i = 0; i < data.length(); i++) {
		if (data[i] > max) max = data[i];
		if (data[i] < min) min = data[i];
	}
	return max - min;
}

// PostCondition: returns difference in the largest and smallest elements in the array  
int maxDiffSort(const Array<int> & data) {
	// we cannot sort the parameter as its passed by constant reference so make a copy (space x2)
	Array<int> sorted(data);

	// sort the copy O(N2) at best!!
	insertionSort<int>(sorted);

	// return difference in last and first elements
	return sorted[sorted.length() - 1] - sorted[0];
}

// PostCondition: array is filled with random numbers 1..range
void fillRandom(Array<int> & data, int range = 100) {
	for (int i = 0; i < data.length(); i++) {
		data[i] = rand() % 100 + 1;
	}
}

// test selection sort
void testSelect() {
	Array<int> data(20);

	fillRandom(data);

	cout << "Select Unsorted: " << data << endl;
	selectionSort(data);
	cout << "Select Sorted  : " << data << endl << endl;
}

// test insertion sort
void testInsert() {
	Array<int> data(20);

	fillRandom(data);
	cout << "Insert Unsorted: " << data << endl;

	insertionSort(data);
	cout << "Insert Sorted  : " << data << endl;
	// resort
	insertionSort(data);
	cout << "Insert Resorted: " << data << endl << endl;
}

// Create two sorter objects, ensure each contains exact same unsorted data
// Print them, call insertionSort method on one, selectionSort method on
// other, then print them again.
void testBoth() {
	for (int i = 1; i < 10; i++) {
		Array<int> insert(10);
		fillRandom(insert);

		// use array copy constructor to make a duplicate of insert array
		Array<int> select(insert);

		//cout << "Select Unsorted: " << select << endl;
		//cout << "Insert Unsorted: " << insert << endl;

		insertionSort(insert);
		selectionSort(select);
		cout << endl;

		//cout << "Select Sorted: " << select << endl;
		//cout << "Insert Sorted: " << insert << endl;
	}
}

// test string
void testString() {
	Array<string> strings(5);

	for (int i = 0; i<strings.length(); i++) {
		cout << "Enter string " << i << ": ";
		cin >> strings[i];
	}

	cout << "Unsorted : " << strings << endl;
	selectionSort(strings);
	cout << "Sorted   : " << strings << endl;
}

// Main method.
int main() {
	//initialise the random number generator
	srand((unsigned)time(NULL));

	Array<int> data(10);
	fillRandom(data);

	cout << "Data: " << data << endl;
	cout << "Difference: " << maxDiff(data) << endl;

	testSelect();

	testInsert();

	testBoth();

	testString();

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}
