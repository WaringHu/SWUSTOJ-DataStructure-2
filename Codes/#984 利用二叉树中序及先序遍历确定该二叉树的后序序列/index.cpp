#include <iostream>
using namespace std;

class treenode
{
	friend class tree;
public:
	treenode(char a) :data(a){
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
	tree(){
		root = NULL;
	}
	void create(treenode* &T, char* pre, char *in, int n);
	void display(treenode* T);
	treenode* root;
};

void tree::create(treenode* &T, char* pre, char *in, int n)
{
	if (n <= 0)
	{
		T = NULL;
		return;
	}
	int k;
	char * p;
	T = new treenode(*pre);
	for (p = in; p < in + n; p++)
	{
		if (*p == *pre)
		{
			break;
		}
	}				
	k = p - in;		//记录根的位置，以便于将其分区
	create(T->left, pre + 1, in, k);//将中序以根为分界 ，左区域
	create(T->right, pre + k + 1, p + 1, n - k - 1);	//右区域
	return;
}

void tree::display(treenode* T)
{
	if (T)
	{
		display(T->left);
		display(T->right);
		cout << T->data;
	}
}

int main()
{
	tree* T = new tree;
	int n = 0;
	char arr_pre[100];
	char arr_in[100];
	cin >> arr_in;
	cin >> arr_pre;
	for (int i = 0; arr_in[i] != '\0'; i++)
	{
		n++;
	}
	T->create(T->root, arr_pre, arr_in, n);
	T->display(T->root);

	return 0;
}