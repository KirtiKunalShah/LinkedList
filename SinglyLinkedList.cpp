#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;


class SinglyLinkedList
{
	private: 
		typedef struct Node {
			int _data =0;
			Node* _next = NULL;
		}*NodePtr;
		NodePtr _head;

	public:
		SinglyLinkedList()
		{
			_head = NULL;
		}
		~SinglyLinkedList()
		{
			if (_head != NULL)
			{
				NodePtr tmp = _head;
				while (tmp)
				{
					_head = _head->_next;
					delete tmp;
					tmp = _head;
				}
			}

		}
		void AddNode(int data);
		void DeleteNode(int data);
		void PrintAllNodes();
};      

void SinglyLinkedList::AddNode(int data)
{
	NodePtr node = new Node;
	node->_data = data;

	if (_head != NULL)
		node->_next = _head;
		
	_head = node;
}

void SinglyLinkedList::DeleteNode(int data)
{
	NodePtr tmp=_head, prev=_head;
	if(_head != NULL)
	{
		while ((tmp->_data != data) && tmp->_next)
		{
			prev = tmp;
			tmp = tmp->_next;
		}
		if (tmp->_data == data)
		{
			prev->_next = tmp->_next;
			cout << endl << "Deleted node " << tmp->_data;
			if (tmp == _head)
				_head = tmp->_next;
			delete tmp;
		}
	}
}

void SinglyLinkedList::PrintAllNodes()
{
	NodePtr tmp = _head, prev = _head;
	if (_head != NULL)
	{
		cout << endl << endl << "Nodes are...";
		while (tmp)
		{
			cout << endl << tmp->_data;
			tmp = tmp->_next;
		}
	}
	else
		cout << endl << endl << "No Nodes left!...";
}

int main(void)
{
	SinglyLinkedList*linkedList = new SinglyLinkedList();
	linkedList->AddNode(999);
	linkedList->AddNode(99);
	linkedList->AddNode(999);
	linkedList->AddNode(9);

	linkedList->PrintAllNodes();

	linkedList->DeleteNode(999);
	linkedList->PrintAllNodes();

	linkedList->DeleteNode(9);
	linkedList->PrintAllNodes();

	linkedList->DeleteNode(999);
	linkedList->PrintAllNodes();

	linkedList->DeleteNode(99);
	linkedList->PrintAllNodes();
	delete linkedList;
}