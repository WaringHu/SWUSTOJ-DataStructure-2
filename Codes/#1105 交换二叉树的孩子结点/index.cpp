#include <iostream>
#include <queue>
using namespace std;

class treenode
{
	friend class tree;
public:
	treenode(char a) :data(a)
	{
		left = NULL;
		right = NULL;
	}
private:
	char data;
	treenode* left;
	treenode* right;
};
class tree
{
public:
	tree() :root(NULL){}
	void precreate(treenode* & current, queue<char> &Q);
	void swap(treenode* & current);
	void pre_oder(treenode* current);
	void in_oder(treenode* current);
	treenode* root;
};

void tree::pre_oder(treenode* current)
{
	cout << current->data;
	if (current->left)
		pre_oder(current->left);
	if (current->right)
		pre_oder(current->right);
}

void tree::in_oder(treenode* current)
{
	if (current->left)
		in_oder(current->left);
	cout << current->data;
	if (current->right)
		in_oder(current->right);
}

void tree::precreate(treenode* & current, queue<char> &Q)
{
	if (Q.empty())
	{
		return;
	}
	if (Q.front() == '#')
	{
		current = NULL;
		Q.pop();
	}
	else
	{
		current = new treenode(Q.front());
		Q.pop();
		precreate(current->left, Q);
		precreate(current->right, Q);
	}
}

void tree::swap(treenode* &current)
{
	treenode* temp = NULL;
	temp = current->left;
	current->left = current->right;
	current->right = temp;
	if(current->left)swap(current->left);
	if (current->right)swap(current->right);
}

int main()
{
	tree T;
	queue<char> Q;
	char arr[1000];
	cin >> arr;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		Q.push(arr[i]);
	}
	T.precreate(T.root, Q);
	T.swap(T.root);
	T.in_oder(T.root);
	cout << endl;
	T.pre_oder(T.root);
	return 0;
}