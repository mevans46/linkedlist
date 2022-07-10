#include <iostream>

using namespace std;



class Node {
public:
	int data;
	Node* next;
};


class List {
private:
	Node* head;
public:
	List(void) { head = NULL; } //initialize first extry to null / placeholder
	/*
	Function: AddNode
	Purpose: add a node to end of the linked list.
	Comments: check to see if theres a head, if not then the head becomes the new node.
			  Otherwise, search for last entry in list and make the next a pointer to the new node.
	*/
	void AddNode(int value){
		Node* newNode = new Node;
		newNode->next = NULL;
		newNode->data = value;
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* nextNode = head;
			while(nextNode->next){
				nextNode = nextNode->next;
			}
			nextNode->next = newNode;
		}

	}
	/*
	Function: printList
	Purpose: print all items in the linked list
	Comments: from the head, follow each entry and print.
	*/
	void printList() {
		Node* currentNode = head;
		while (currentNode->next) {
			cout << "Current Node Value: " << currentNode->data << endl;
			currentNode = currentNode->next;
		}
		if (currentNode) {
			cout << "Current Node Value: " << currentNode->data << endl;
		}
	}
	/*
	Function: findNode
	Purpose: find a single entry in the linked list.
	Comments: from the head, follow each entry and if matches, return.
	*/
	Node* findNode(int value) {
		Node* currentNode = head;
		while (currentNode->next) {
			if (currentNode->data == value) {
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		if (currentNode) {
			if (currentNode->data == value) {
				return currentNode;
			}
		}
		return NULL;
	}
	/*
	Function: deleteNode
	Purpose: loop through until found, delete node.
	Comments: from the head, follow each entry and if matches, set previous next pointer to the deleted next pointer.
			  effectively skipping the deleted entry.
	*/
	void deleteNode(int value) {
		Node* foundNode = findNode(value);
		if (!foundNode) {
			cout << "Node not found for delete " << endl;
			return;
		}
		Node* currentNode = head;
		Node* previousNode = NULL;
		while (currentNode->next) {
			if (currentNode->data == value) {
				if (previousNode) {
					previousNode->next = currentNode->next;
				}
				return;
			}
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if (currentNode) {
			if (currentNode->data == value) {
				if (previousNode) {
					previousNode->next = currentNode->next;
				}
			}
		}

	}
	/*
	Function: printMax
	Purpose: find max entry in linked list.
	Comments: from the head, follow each entry, changing max to biggest number.
	*/
	void printMax() {
		Node* currentNode = head;
		int max = 0;
		while (currentNode->next) {
			if (currentNode->data > max) {
				max = currentNode->data;
			}
			currentNode = currentNode->next;
		}
		if (currentNode) {
			if (currentNode->data > max) {
				max = currentNode->data;
			}
		}
		cout << "Max Value: "<<max << endl;
	}
	/*
	Function: printMin
	Purpose: find min entry in linked list.
	Comments: from the head, follow each entry, changing min to smallest number.
	*/
	void printMin() {
		Node* currentNode = head;
		int min = INT_MAX;
		while (currentNode->next) {
			if (currentNode->data < min) {
				min = currentNode->data;
			}
			currentNode = currentNode->next;
		}
		if (currentNode) {
			if (currentNode->data < min) {
				min = currentNode->data;
			}
		}
		cout << "Min Value: " << min << endl;
	}
};

//create main function
int main()
{
	//create list
	List list;
	//add nodes to list
	list.AddNode(1);
	list.AddNode(3);
	list.AddNode(4);
	list.printList();
	//find a specific node
	Node* found = list.findNode(3);
	if (found) {
		cout << "Found " << found->data << " at address " << found << endl;
	}
	else {
		cout << "Data not found in list." << endl;
	}
	//delete node with value 4
	//list.deleteNode(4);

	//print list
	list.printList();

	//find max and min.
	list.printMax();
	list.printMin();
	return 0;
}