#include <iostream>

using namespace std;

class Node
{
	int key;
	Node* left;
	Node* right;
public:
	Node(int k){
		key = k;
		left = NULL;
		right = NULL;
	}

	void printkey(){
		cout<<key<<endl;
	}
	~Node();
	
};


int main(int argc, char const *argv[])
{
	Node* head = new Node(10);
	head->printkey();
	return 0;
}