/*
280
Concordance
John Kraft
*/

#include <iostream>
using namespace std;

struct wordNode {
	string data;
	wordNode* next;
};

class listofwords {
private:
	wordNode* top;
	int size;
public:
	listofwords();
	void addWord(string);
	void display();
	bool exist(string);
};