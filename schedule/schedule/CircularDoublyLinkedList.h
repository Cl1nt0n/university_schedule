#include "iostream"

using namespace std;
class CircularDoublyLinkedList
{
public:
	CircularDoublyLinkedList()
	{
		head = nullptr;
	}

	void insert(int data);
	void remove(int data);
	void print();
private:
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