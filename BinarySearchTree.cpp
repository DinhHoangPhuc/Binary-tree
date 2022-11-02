#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<random>
#include"BinarySearchTree.h"

TNode* createTNode(int x)
{
	TNode* p = new TNode;
	if(p==NULL)
		return NULL;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void initBTree(BSTree& bt)
{
	bt.root = NULL;
}

int insertTNodeLeft(TNode* &T, TNode* p)
{
	if(T == NULL || p == NULL)
		return 0;
	if(T->left != NULL)
		return 0;
	T->left = p;
	return 1;
}

int insertTNodeRight(TNode* &T, TNode* p)
{
	if(T == NULL || p == NULL)
		return 0;
	if(T->right != NULL)
		return 0;
	T->right = p;
	return 1;
}

int insertTNode(TNode* &root, TNode* p)
{
	if(p == NULL)
		return 0;
	if(root == NULL)
	{
		root = p;
		return 1;
	}
	if(root->info == p->info)
		return 0;
	if(p->info < root->info)
		insertTNode(root->left, p);
	else
		insertTNode(root->right, p);
	return 1;
}

void traverseLNR(TNode* root)
{
	if(root == NULL)
		return;
	traverseLNR(root->left);
	printf("%d\t", root->info);
	traverseLNR(root->right);
}

void createBSTree(TNode* &root)
{
	FILE* f = fopen("BSTree.txt", "r");
	if (f == NULL)
	{
		printf("Loi file\n");
		return;
	}
	int n;
	fscanf_s(f, "%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x;
		fscanf_s(f, "%d", &x);
		TNode* p = createTNode(x);
		insertTNode(root, p);
	}
	fclose(f);
}