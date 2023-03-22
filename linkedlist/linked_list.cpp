#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

int main(int argc, char const *argv[])
{
	Node *head = new Node(10);
	Node *temp1 = new Node(11);
	Node *temp2 = new Node(12);

	head->next = temp1;
	temp1->next = temp2;

	// while(true){

	// 	cout<<head.data<<endl;
	// 	head = *head.next;
	// 	if(head.next == NULL){
	// 		cout<<head.data<<endl;
	// 		break;
	// 	}
	// }



	return 0;
}