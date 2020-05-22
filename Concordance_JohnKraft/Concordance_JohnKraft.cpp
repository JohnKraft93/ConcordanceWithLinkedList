/*
280
Concordance
John Kraft
*/

#include <iostream>
#include "LinkedListWords.h"
#include <fstream>
#include <string>
using namespace std;

struct charNode { 
	char data;
	charNode* next;
	listofwords words;
};

class CharLinkedList {
private:
	charNode* top;
	int count;
public:
	CharLinkedList();
	void append(string w);
	void display();
	bool exist(char v);
	charNode* find(char v);
};

CharLinkedList::CharLinkedList() {
	top = nullptr;
	count = 0;
}

charNode* CharLinkedList::find(char v) {
	charNode* temp = top;
	for (int i = 0; i < count; i++) {
		if (temp->data == v) {
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	return nullptr;
} //find

bool CharLinkedList::exist(char v) {
	charNode* runner = top;
	for (int i = 0; i < count; i++) {
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

void CharLinkedList::append(string w) {
	for (int i = 0; i < w.size(); i++) {
		w[i] = tolower(w[i]);
		if (w.at(i) == ',' || w.at(i) == '.') {
			w.erase(i, 1);
		}
	}
	if (exist(tolower(w.at(0))) == true) {
		charNode* tmp = find(tolower(w.at(0)));
		tmp->words.addWord(w);
	}
	else {
		charNode* runner = new charNode;
		charNode* temp = new charNode;
		temp->data = tolower(w.at(0));
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
		count++;
		temp->words.addWord(w);
	}
} //append

void CharLinkedList::display() {
	cout << "Character Linked List: " << endl;
	charNode* tmp = top;
	while (tmp != nullptr) {
		cout << tmp->data << endl;
		tmp->words.display();
		tmp = tmp->next;
	}
	cout << endl;
} //display

int main() {
	CharLinkedList cll = CharLinkedList();
	string str;
	ifstream ifile("gettysburg.txt");

	while (!ifile.eof()) {
		ifile >> str;
		cll.append(str);
	}
	ifile.close();

	cll.display();
} //main