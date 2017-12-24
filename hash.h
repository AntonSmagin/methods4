#include "list"
#include "sstream"
using namespace std;

class hash1
{
	struct Node
	{
		int d;
		Node *next;
	};
	int quantity;
	Node *down;
public:
	hash1();
	~hash1();
	void hashtable(int *mass, int n);
	void showhashtable(void print(string data));
	int search(int d);
	void add(int d);
	void del(int d);
};
