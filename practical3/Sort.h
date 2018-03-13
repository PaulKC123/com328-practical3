/**
* Sort.h
*
* Completed Template based Sort functions
*
* @author  your name
* @version 2.0
*/

#ifndef SORT_H_
#define SORT_H_

// when defined debug comp/move figures printed
#define _SORT_DEBUG_

#include "Array.h"

// ------------------------ Sort Algorithm Templates ------------------------

// PostCondition: Array elements are sorted
template <class T>
void selectionSort(Array<T> & elements) {
	int min, moves = 0, comps = 0;

	for (int marker = 0; marker < elements.length() - 1; marker++) {
		min = marker;
		for (int i = marker + 1; i < elements.length(); i++) {
			comps++; // comparison
			if (elements[i] < elements[min]) {
				min = i;
			}
		}
		moves += 3; // movements
		// call local function to swap elements at position min and out
		lswap(elements[marker], elements[min]);
	
		//T tmp = elements[marker];
		//elements[marker] = elements[min];
		//elements[min] = tmp;
	}
#ifdef _SORT_DEBUG_
	std::cout << "Selection sort : Comps: " << comps << " Moves: " << moves << std::endl;
#endif
}

// PostCondition: collection elements are sorted
template <class T>
void insertionSort(Array<T> & elements) {
	int comps = 0, moves = 0;
	int in, out, temp;
	for (out = 1; out < elements.length(); out++) {
		temp = elements[out]; 	 moves++;
		// find position for temp
		for (in = out; in > 0 && elements[in - 1] >= temp; in--) {
			elements[in] = elements[in - 1];
			comps++; moves++;			// one comp and one move on each iteration
		}
		comps++;						// final comp which terminates loop above
		elements[in] = temp; moves++;	// additional move
	}
#ifdef _SORT_DEBUG_
	std::cout << "Insertion sort : Comps: " << comps << " Moves: " << moves << std::endl;
#endif
}

// swap algorithm to swap two parameters
template <class T>
void lswap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

#endif

