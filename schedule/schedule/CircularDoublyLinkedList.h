#include "iostream"

using namespace std;
struct MyList
{
	MyList()
	{
		head = nullptr;
	}

	void insert(int data);
	void remove(int data);
	void print();
	struct Node
	{
		int data;
		Node* next;
		Node* prev;

		Node(int data)
		{
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
	};

	Node* head;
};