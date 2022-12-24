#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
Node *removeDuplicates(Node *head)
{
	Node *temp = head;
	if (temp == NULL)
	{
		return temp;
	}
	Node *temp1 = head;
	Node *temp2 = head;
	temp2 = temp2->next;
	while (temp1->next != NULL && temp2->next != NULL)
	{
		if (temp1->data == temp2->data)
		{
			Node *a = temp2;
			temp1->next = temp2->next;
			temp2 = a->next;
			delete a;
		}
		else
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	if (temp1->next != NULL && temp2->next == NULL)
	{
		if (temp1->data == temp2->data)
		{
			Node *a = temp2;
			temp1->next = temp2->next;
			temp2 = a->next;
			delete a;
		}
	}
	return temp;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}