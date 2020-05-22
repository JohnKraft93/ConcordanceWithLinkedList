/*
280
Concordance
John Kraft
*/

#include <iostream>
#include "LinkedListWords.h"
using namespace std;

listofwords::listofwords() {
	top = nullptr;
	size = 0;
}

void listofwords::addWord(string v) {
	if (exist(v) == false) {
		wordNode* runner = new wordNode;
		wordNode* temp = new wordNode;
		temp->data = v;
		if (top == nullptr) {
			temp->next = nullptr;
			top = temp;
		}
		else if (temp->data <= top->data) {
			temp->next = top;
			top = temp;
		}
		else {
			runner = top;
			while (runner->next != nullptr && runner->next->data < temp->data) {
				runner = runner->next;
			}
			temp->next = runner->next;
			runner->next = temp;
		}
		size++;
	}
} //addword

void listofwords::display() {
	wordNode* runner = top;
	while (runner != nullptr) {
		cout << runner->data << " ";
		runner = runner->next;
	}
	cout << endl;
} //display

bool listofwords::exist(string v) {
	wordNode* runner = top;
	for (int i = 0; i < size; i++) {
		if (runner == nullptr) {
			return false;
		}
		if (runner->data == v) {
			return true;
		}
		runner = runner->next;
	}
	return false;
} //exist