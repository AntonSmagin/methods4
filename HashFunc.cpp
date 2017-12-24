#include "stdafx.h"
#include "hash.h"
#include <ctime>
#include <conio.h> 
#include <cstdlib>
#include "sstream"
using namespace std;


hash1::hash1()
{
	down = NULL;
	quantity = 0;
}


hash1::~hash1()
{

}


void hash1::hashtable(int *mass, int n)
{
	int hash;
	quantity = n / 3;
	delete[] down;
	down = new Node[quantity];
	for (int i = 0; i < quantity; i++)
	{
		down[i].next = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		hash = mass[i] % quantity;
		Node *elem = new Node;
		elem->d = mass[i];
		elem->next = NULL;
		if (down[hash].next == NULL)
		{
			down[hash].next = elem;
		}
		else
		{
			Node *iter = down[hash].next;
			while (iter->next != NULL)
			{
				iter = iter->next;
			}
			iter->next = elem;
		}
	}
}


void hash1::showhashtable(void print(string data))
{
	Node *iter;
	for (int i = 0; i < quantity; i++)
	{
		string str;
		stringstream out;
		out << i;
		str = out.str();
		str += ":";
		print(str);
		iter = down[i].next;
		while (iter != NULL)
		{
			string str;
			stringstream out;
			out << iter->d;
			str = out.str();
			str += ",";
			print(str);
			iter = iter->next;
		}

		print("endl");
	}
}


int hash1::search(int d)
{
	Node *iter;
	int hash = d % quantity;
	iter = down[hash].next;
	while (iter->next != NULL && iter->d != d)
	{
		iter = iter->next;
	}
	if (iter->d == d)
	{
		return hash;
	}
	else
	{
		return -1;
	}
}


void hash1::add(int d)
{
	int hash;
	hash = d % quantity;
	Node *elem = new Node;
	elem->d = d;
	elem->next = NULL;
	if (down[hash].next == NULL)
	{
		down[hash].next = elem;
	}
	else
	{
		Node *iter = down[hash].next;
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = elem;
	}
}


void hash1::del(int d)
{
	int hash;
	hash = d % quantity;
	Node *elem;
	if (down[hash].next != NULL && down[hash].next->d == d)
	{
		elem = down[hash].next;
		down[hash].next = elem->next;
		delete elem;
	}
	else
	{
		Node *iter = down[hash].next;
		while (iter->next != NULL && iter->next->d != d)
		{
			iter = iter->next;
		}
		if (iter->next != NULL && iter->next->d == d)
		{
			elem = iter->next;
			iter->next = elem->next;
			delete elem;
		}
	}
}
