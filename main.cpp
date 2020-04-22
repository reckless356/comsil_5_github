#include <iostream>
#include <string>
using namespace std;

// Linked List Node

template <class T>
class Node {
public:
	T data;
	Node *link;
	Node(T element) {
		data = element;
		link = 0;
	}
};

// Linked List Class

template <class T>
class LinkedList
{
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList() {
		first = 0;
		current_size = 0;
	};
	int GetSize() { return current_size; }; // return size of Nodes

	void Insert(T element) // Insert new Node at first
	{
		Node<T> *newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;
	}

	bool Delete(T &element); // Delete last Node

	void Print()	// Print the list
	{
		int i = 1;
		if (first == 0) return;
		Node<T>* current = first;
		while (current->link != 0) {
			
			cout << '[' << i++ << '|' << current->data << "]->";
			current = current->link;
		}

		cout << '[' << i << '|' << current->data << ']' << endl;
	}
};

template <class T>
bool LinkedList<T>::Delete(T &element) {
	// return the data of last Node and delete Node
	if (first == 0) return false;
	Node<T> *current = first, *previous = 0;
	while (1) {
		if (current->link == 0)    // find end node
		{
			if (previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;
	return true;
}

// Stack

template <class T>
class Stack : public LinkedList<T>
{
public:
	Stack() : LinkedList<T>() {};
	virtual bool Delete(T &element) {
		if (this->first == 0) return false;
		Node<T> *current = this->first;
		this->first = current->link;
		element = current->data;
		delete current;
		this->current_size--;
		return true;
	}
};

// Linked List Test
/*
int main() {
	double dVal;
	string strVal;

	LinkedList<double> dList;
	LinkedList<string> strList;

	dList.Insert(3.14);
	dList.Insert(123456);
	dList.Insert(-0.987654);
	dList.Print();
	dList.Delete(dVal);
	cout << "Lately Deleted Data: " << dVal << endl;
	dList.Print();
	dList.Insert(777.777);
	dList.Print();
	dList.Delete(dVal);
	cout << "Lately Deleted Data: " << dVal << endl;
	dList.Delete(dVal);
	cout << "Lately Deleted Data: " << dVal << endl;
	dList.Print();
	dList.Delete(dVal);
	cout << "Lately Deleted Data: " << dVal << endl;
	dList.Print();

	strList.Insert("This");
	strList.Insert("is a");
	strList.Insert("Template");
	strList.Insert("Example");
	strList.Print();
	strList.Delete(strVal);
	cout << "Lately Deleted Data: " << strVal << endl;
	strList.Insert("Class");
	strList.Print();

	return 0;
}
*/

void prnMenu() {
	cout << "*******************************************" << endl;
	cout << "* 1. Insert  2. Delete  3. Print  4. Exit *" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
	cout << "Choose the menu you want: ";
}





int main(){
	// Test Code for LinkedList and Stack
	int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"Choose Data Structure (1: Stack, Other: Linked List): ";
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();
			
		else
			p = new LinkedList<int>();


		do{
			prnMenu();
			cin>>selectNumber;
			
			switch(selectNumber){ 
				case 1:
					cout<<"Insert data you want: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<" was inserted."<<endl;
					break;
					
				case 2:
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<" was deleted."<<endl;
						
					else cout<<"It is empty. Failed to delete."<<endl;
					break;
					
				case 3:
					cout<<"size: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4:
					flag = true;     break;
					
				default:
					cout<<"Wrong Number."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}

