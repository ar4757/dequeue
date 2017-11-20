/*
 * dequeue.h
 *
 *  Created on: Sep 1, 2017
 *      Author: andrewratz
 */

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include <iostream>
using namespace std;

//Template of class E, standing for "element"
template <class E>
//The virtual class for BoundedDequeue
class Dequeue {
public:
	Dequeue() {

	}
	virtual ~Dequeue() {

	}
	//Everything is set to 0 because it's a virtual class
	virtual void push_front(E element) = 0;
	virtual void push_back(E element) = 0;
	virtual void pop_front() = 0;
	virtual void pop_back() = 0;
	virtual E peek_front() = 0;
	virtual E peek_back() = 0;
	virtual int length() = 0;
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;
	virtual void clear() = 0;
};

template <class E>
//The class BoundedDequeue is what objects are made into
class BoundedDequeue: public Dequeue<E> {
	//Size of the array that the dequeue relies on
	int array_size;
	//Array of pointers of type E
	E *array;
public:
	//Constructor requires an integer size that sets the value of the backing array
	BoundedDequeue(int size) {
		//Sets the array size
		array_size = size+1;
		//Sets the array of pointers to an array of E's
		array = new E[array_size];
		//Fills the array with blank E's
		for (int i = 0; i < array_size-1; i++) {
			array[i] = E();
		}
	}
	//Deletes the array when the destructor is called
	~BoundedDequeue() {
		delete[] array;
	}
	//Pushes an element to the front of the dequeue
	void push_front(E element) {
		//If full, don't let a new element be pushed
		if (is_full() == true) {
			cout << "Dequeue is full, cannot push element to front" << endl;
			return;
		}
		//Otherwise
		else {
			//Position where all prior elements can be shifted right to
			int x = 0;
			//Iterator
			int i = 0;
			//While within the array bounds
			while (i <= array_size-2) {
				//If the array at the specified index is empty (E() signifies an empty array index)
				if (array[i] == E()) {
					//Set the position to the current index
					x = i;
					//And exit the loop
					break;
				}
				//Increments iterator
				i++;
			}
			//Performs the shifting of all elements to the right, making sure not to push out already stored elements
			for (int i = x-1; i >= 0; i--) {
				if (i == -1) {
					break;
				}
				//Shifts right by 1
				array[i+1] = array[i];
			}
			//Sets the front of the array to the user's desired element
			array[0] = element;
		}
		return;
	}
	//Pushes an element to the back of the dequeue
	void push_back(E element) {
		//If full, don't let a new element be pushed
		if (is_full() == true) {
			cout << "Dequeue is full, cannot push element to back" << endl;
		}
		//Otherwise
		else {
			//Position where all prior elements can be shifted left to
			int x = 0;
			//Iterator
			int i = array_size-2;
			//While within the array bounds
			while (i >= 0) {
			//If the array at the specified index is empty (E() signifies an empty array index)
			if (array[i] == E()) {
				//Set the position to the current index
				x = i;
				//And exit the loop
				break;
			}
			//Decrements iterator
			i--;
			}
			//Performs the shifting of all elements to the left, making sure not to push out already stored elements
			for (int i = x; i < array_size-2; i++) {
				//Shifts left by 1
				array[i] = array[i+1];
			}
			//Sets the back of the array to the user's desired element
			array[array_size-2] = element;
		}
		return;
	}
	//Pops an element off the front of the dequeue
	void pop_front() {
		//If empty, don't let an element be popped
		if (is_empty() == true) {
			cout << "Dequeue is empty, cannot pop element from front" << endl;
		}
		//Otherwise
		else {
			//Finds the first non-empty index of the array
			for (int i = 0; i < array_size-2; i++) {
				if (array[i] == E()) {
					continue;
				}
				//Shifts left by 1
				array[i] = array[i+1];
			}
			//Sets the end of the array to empty
			array[array_size-2] = E();
		}
		return;
	}
	//Pops an element off the back of the dequeue
	void pop_back() {
		//If empty, don't let an element be popped
		if (is_empty() == true) {
			cout << "Dequeue is empty, cannot pop element from back" << endl;
		}
		//Otherwise
		else {
			//Finds the first non-empty index of the array
			for (int i = array_size-2; i >= 1; i--) {
				if (array[i] == E()) {
					continue;
				}
				//Shifts right by 1
				array[i] = array[i-1];
			}
			//Sets the front of the array to empty
			array[0] = E();
		}
		return;
	}
	//Returns the front element of the array
	E peek_front() {
		if (is_empty() == true) {
			cout << "Dequeue is empty, cannot peek at front element" << endl;
		}
		//Finds the first non-empty index of the array
		for (int i = 0; i < array_size-2; i++) {
			if (array[i] == E()) {
				continue;
			}
			//Then returns it
			else {
				return array[i];
			}
		}
		return E();
	}
	//Returns the back element of the array
	E peek_back() {
		if (is_empty() == true) {
			cout << "Dequeue is empty, cannot peek at back element" << endl;
		}
		//Finds the last non-empty index of the array
		for (int i = array_size-2; i > 0; i--) {
			if (array[i] == E()) {
				continue;
			}
			//Then returns it
			else {
				return array[i];
			}
		}
		return E();
	}
	//Returns the number of non-empty indices of the array
	int length() {
		int count = 0;
		//Loop increments by 1 for non-empty indices
		for (int i = 0; i < array_size-1; i++) {
			if (array[i] != E()) {
				count++;
			}
		}
		//An returns the final count
		return count;
	}
	//Returns true if empty, false if not
	bool is_empty() {
		//If there is a non-empty element, return false
		for (int i = 0; i < array_size-1; i++) {
			if (array[i] != E()) {
				return false;
			}
		}
		//Otherwise, return true
		return true;
	}
	//Returns true if full, false if not
	bool is_full() {
		//If there is an empty element, return false
		for (int i = 0; i < array_size-1; i++) {
			if (array[i] == E()) {
				return false;
			}
		}
		//Otherwise, return true
		return true;
	}
	//Clears the backing array back to its default state
	void clear() {
		//Iterates through the array, setting the elements to their default value
		for (int i = 0; i < array_size-1; i++) {
			array[i] = E();
		}
		return;
	}
	//Prints out the dequeue's values, and takes in a string to let the user decide if they want to see a more detailed dequeue
	void print(string details) {
		//Iterates through, printing the elements
		for (int i = 0; i < array_size-1; i++) {
			//If non-empty, output the value of E
			if (array[i] != E()) {
				cout << array[i] << " ";
			}
			//Otherwise, output 0 if verbose, or ignore entirely if not
			else {
				if (details == "verbose") {
					cout << 0 << " ";
				}
			}
		}
		cout << endl;
		return;
	}
};

#endif /* DEQUEUE_H_ */
