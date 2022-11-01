#include<stdio.h>
#include<random>

struct TNode
{
	int info;
	TNode* left;
	TNode* right;
};

struct BTree
{
	TNode* root;
};

TNode* createTNode(int x);
void showTNode(TNode* p);
void initTree(BTree& bt);
int isEmpty(BTree bt);
int insertTNodeLeft(TNode*& T, TNode* p);
int insertTNodeRight(TNode*& T, TNode* p);
int insertTNode(TNode*& root, TNode* p);

TNode* createTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap phat\n");
		return NULL;
	}
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void showTNode(TNode* p)
{
	printf("%d\t", p->info);
}

void initTree(BTree& bt)
{
	bt.root = NULL;
}

int isEmpty(BTree bt)
{
	return (bt.root == NULL) ? 1 : 0;
}

int insertTNodeLeft(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->left != NULL)
		return 0;
	T->left = p;
	return 1;
}

int insertTNodeRight(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->right != NULL)
		return 0;
	T->right = p;
	return 1;
}

int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
		root = p;
	if (root->left == NULL)
		insertTNode(root->left, p);
	else
		if (root->right == NULL)
			insertTNode(root->right, p);
		else
		{
			int x = rand() % 2;
			if (x == 0)
				insertTNode(root->left, p);
			else
				insertTNode(root->right, p);
		}
}

void traverseNLR(TNode* root)
{
	if (root == NULL)
		return;
	printf("%d\t", root->info);
	traverseNLR(root->left);
	traverseNLR(root->right);
}

void traverseNRL(TNode* root)
{
	if (root == NULL)
		return;
	printf("%d\t", root->info);
	traverseNLR(root->right);
	traverseNLR(root->left);
}

void traverseLNR(TNode* root)
{
	if (root == NULL)
		return;
	traverseLNR(root->left);
	printf("%d\t", root->info);
	traverseLNR(root->right);
}

void traverseRNL(TNode* root)
{
	if (root == NULL)
		return;
	traverseRNL(root->right);
	printf("%d\t", root->info);
	traverseRNL(root->left);
}

void traverseLRN(TNode* root)
{
	if (root == NULL)
		return;
	traverseLRN(root->left);
	traverseLRN(root->right);
	printf("%d\t", root->info);
}

void traverseRLN(TNode* root)
{
	if (root == NULL)
		return;
	traverseRLN(root->right);
	traverseRLN(root->left);
	printf("%d\t", root->info);
}

TNode* findTNode(TNode* root, int x)
{
	if (!root)
		return NULL;
	if (root->info == x)
		return root;
	TNode* p = findTNode(root->left, x);
	if (p)
		return p;
	return findTNode(root->right, x);
}

int deleteTNodeLeft(TNode* T)
{
	if (T == NULL)
		return 0;
	TNode* p = T->left;
	if (p == NULL)
		return 0;
	if (p->left == NULL || p->right == NULL)
		return 0;
	delete p;
	return 1;
}