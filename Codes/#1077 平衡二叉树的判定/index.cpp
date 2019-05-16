#include <iostream>
#include <queue>
using namespace std;

class treenode
{
	friend class tree;
public:
	treenode(char a);
private:
	char data;
	treenode* left;
	treenode* right;
};
treenode::treenode(char a)
{
	data = a;
	left = NULL;
	right = NULL;
}
class tree
{
public:
	tree();
	void precreate(treenode* &current,queue<char> &Q);
	bool check_bt();
	int deep(treenode* current);
public:
	treenode* root;
};

tree::tree()
{
	root = NULL;
}

void tree::precreate(treenode* &current,queue<char>& Q)
{
	if (Q.empty())
		return;
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

bool tree::check_bt()
{
	int d_left = deep(root->left);
	int d_right =deep(root->right);
	if ((d_left - d_right )> 1 || (d_left - d_right) < -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int tree::deep(treenode* current)
{
	int r_num;
	int l_num;
	if (!current)
		return 1;
	else
	{
		r_num = deep(current->right)+1;
		l_num = deep(current->left)+1;
		if (r_num > l_num)
		{
			return r_num;
		}
		else
			return l_num;
	}
	
}


int main()
{
	queue<char> Q;
	char arr[1000];
	cin >> arr;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		Q.push(arr[i]);
	}
	tree T;
	T.precreate(T.root, Q);
	if(T.check_bt())
		cout<<"yes!";
	else
	{
		cout << "no!";
	}
	return 0;
}