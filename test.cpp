#include"BinarySearchTree.h"
#include"asciinode.h"
#include<stdio.h>
#include<conio.h>

void main()
{
	BSTree bt;
	initBTree(bt);
	createBSTree(bt.root);
	/*traverseLNR(bt.root);*/
	print_ascii_tree(bt.root);
	_getch();
}