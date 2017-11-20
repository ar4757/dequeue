/*
 * dequeue.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: andrewratz
 */

#include <iostream>
#include "dequeue.h"
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	//Default print behavior
	string noarg = "";
	//Lets you see under the table of how the array looks
	string verbose = "verbose";
	//Creates a new BoundedDequeue holding integers
	BoundedDequeue<int>* int_deque = new BoundedDequeue<int>(10);
	cout << "Pushing to front" << endl;
	int_deque->push_front(5);
	cout << "Pushing to back" << endl;
	int_deque->push_back(6);
	cout << "Printing normal" << endl;
	int_deque->print(noarg);
	cout << "Pushing to front" << endl;
	int_deque->push_front(4);
	cout << "Pushing to back" << endl;
	int_deque->push_back(7);
	cout << "Printing normal" << endl;
	int_deque->print(noarg);
	cout << "Pushing to front" << endl;
	int_deque->push_front(3);
	cout << "Pushing to back" << endl;
	int_deque->push_back(8);
	cout << "Printing verbose" << endl;
	int_deque->print(verbose);
	cout << "Pushing to front" << endl;
	int_deque->push_front(2);
	cout << "Pushing to back" << endl;
	int_deque->push_back(9);
	cout << "Printing verbose" << endl;
	int_deque->print(verbose);
	cout << "Pushing to front" << endl;
	int_deque->push_front(1);
	cout << "Pushing to back" << endl;
	int_deque->push_back(10);
	cout << "Printing normal" << endl;
	int_deque->print(noarg);
	cout << "Testing for fullness" << endl;
	if (int_deque->is_full() == true) {
		cout << "True - Dequeue is full" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not full" << endl;
 	}
 	cout << "Popping front" << endl;
	int_deque->pop_front();
	cout << "Printing normal" << endl;
	int_deque->print(noarg);
	cout << "Printing verbose" << endl;
	int_deque->print(verbose);
	cout << "Popping back" << endl;
	int_deque->pop_back();
	cout << "Printing normal" << endl;
	int_deque->print(noarg);
	cout << "Printing verbose" << endl;
	int_deque->print(verbose);
	cout << "Front element is " << int_deque->peek_front() << endl;
	cout << "Back element is " << int_deque->peek_back() << endl;
	cout << "Length is " << int_deque->length() << endl;
	cout << "Testing for emptiness" << endl;
	if (int_deque->is_empty() == true) {
		cout << "True - Dequeue is empty" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not empty" << endl;
 	}
 	cout << "Clearing Dequeue...";
 	int_deque->clear();
 	cout << "Dequeue cleared" << endl;
 	cout << "Testing for emptiness" << endl;
 	if (int_deque->is_empty() == true) {
		cout << "True - Dequeue is empty" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not empty" << endl;
 	}
 	cout << "Peeking front" << endl;
 	cout << int_deque->peek_front();
 	cout << "Peeking back" << endl;
 	cout << int_deque->peek_back();
 	cout << "Printing verbose" << endl;
 	int_deque->print(verbose);
 	int_deque->~BoundedDequeue();
 	//Creates a new BoundedDequeue holding strings
 	BoundedDequeue<string>* str_deque = new BoundedDequeue<string>(5);
 	cout << "Pushing to front" << endl;
	str_deque->push_front("a");
	cout << "Pushing to back" << endl;
	str_deque->push_back("test");
	cout << "Printing verbose" << endl;
	str_deque->print(verbose);
	cout << "Pushing to front" << endl;
	str_deque->push_front("is");
	cout << "Pushing to back" << endl;
	str_deque->push_back(".");
	cout << "Printing normal" << endl;
	str_deque->print(noarg);
	cout << "Pushing to front" << endl;
	str_deque->push_front("this");
	cout << "Printing normal" << endl;
	str_deque->print(noarg);
	cout << "Pushing to front" << endl;
	str_deque->push_front("a");
	cout << "Pushing to back" << endl;
	str_deque->push_back("a");
	cout << "Testing for fullness" << endl;
	if (str_deque->is_full() == true) {
		cout << "True - Dequeue is full" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not full" << endl;
 	}
 	cout << "Popping front" << endl;
	str_deque->pop_front();
	cout << "Printing normal" << endl;
	str_deque->print(noarg);
	cout << "Printing verbose" << endl;
	str_deque->print(verbose);
	cout << "Popping back" << endl;
	str_deque->pop_back();
	cout << "Printing normal" << endl;
	str_deque->print(noarg);
	cout << "Printing verbose" << endl;
	str_deque->print(verbose);
	cout << "Front element is " << str_deque->peek_front() << endl;
	cout << "Back element is " << str_deque->peek_back() << endl;
	cout << "Length is " << str_deque->length() << endl;
	cout << "Testing for emptiness" << endl;
	if (str_deque->is_empty() == true) {
		cout << "True - Dequeue is empty" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not empty" << endl;
 	}
 	cout << "Clearing Dequeue...";
 	str_deque->clear();
 	cout << "Dequeue cleared" << endl;
 	cout << "Testing for emptiness" << endl;
 	if (str_deque->is_empty() == true) {
		cout << "True - Dequeue is empty" << endl;
 	}
 	else {
 		cout << "False - Dequeue is not empty" << endl;
 	}
 	cout << "Peeking front" << endl;
 	cout << str_deque->peek_front();
 	cout << "Peeking back" << endl;
 	cout << str_deque->peek_back();
 	cout << "Printing verbose" << endl;
 	str_deque->print(verbose);
 	str_deque->~BoundedDequeue();
}
