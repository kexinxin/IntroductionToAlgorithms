#include <iostream>
#include<vector>
using namespace std;
struct Tree{
	int key;
	Tree *left = NULL;
	Tree *right = NULL;
	Tree *parent = NULL;
};

void inorderTreeWalk(Tree *x){
	if (x != NULL){
		inorderTreeWalk(x->left);
		cout << x->key << " ";
		inorderTreeWalk(x->right);
	}
}

Tree *getParent(Tree *root, Tree *x){
	if (root != NULL){
		if (root->left == x || root->right == x){
			return root;
		}
		Tree *left = NULL;
		Tree *right = NULL;
		if (root->left != NULL&&root->left != x){
			left = getParent(root->left, x);
		}
		if (left != NULL)
			return left;
		if (root->right != NULL&&root->right != x){
			right = getParent(root->right, x);
		}
		if (right != NULL){
			return right;
		}
	}
	else{
		return NULL;
	}
	return NULL;
}

Tree *treeSearch(Tree *x, int k){
	if (x == NULL || k == x->key){
		return x;
	}
	if (k<x->key){
		return treeSearch(x->left, k);
	}
	else{
		return treeSearch(x->right, k);
	}
}

Tree *iterativeTreeSearch(Tree *x, int k){
	while (x != NULL&&x->key != k){
		if (k<x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

Tree *treeMinimum(Tree *x){
	while (x->left != NULL){
		x = x->left;
	}
	return x;
}

Tree *treeMaximum(Tree *x){
	while (x->right != NULL){
		x = x->right;
	}
	return x;
}

Tree *treeSuccessor(Tree *x){
	if (x->right != NULL){
		return treeMinimum(x->right);
	}
	Tree *y = x->parent;
	while (y != NULL&&x == y->right){
		x = y;
		y = y->parent;
	}
	return y;
}

void treeInsert(Tree *node1, Tree *z){
	Tree *y=NULL;
	Tree *x = node1;
	while (x != NULL){
		y = x;
		if (z->key<x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		//tree T was empty
		node1 = z;
	else if (z->key<y->key)
		y->left = z;
	else
		y->right = z;
}

void transplant(Tree *root, Tree *u, Tree *v){
	if (u->parent == NULL){
		root = v;
	}
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void treeDelete(Tree *root, Tree *z){
	if (z->left == NULL){
		transplant(root, z, z->right);
	}
	else if (z->right == NULL){
		transplant(root, z, z->left);
	}
	else{
		Tree *y = treeMinimum(z->right);
		if (y->parent != z){
			transplant(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

Tree *buildBinaryTree(){
	Tree *node1 = new Tree();
	node1->key = 5;
	Tree *node2 = new Tree();
	node2->key = 3;
	Tree *node3 = new Tree();
	node3->key = 7;
	Tree *node4 = new Tree();
	node4->key = 2;
	Tree *node5 = new Tree();
	node5->key = 4;
	Tree *node6 = new Tree();
	node6->key = 6;
	Tree *node7 = new Tree();
	node7->key = 8;
	Tree *node8 = new Tree();
	node8->key = 1;
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	node4->left = node8;
	node2->parent = node1;
	node3->parent = node1;
	node4->parent = node2;
	node5->parent = node2;
	node6->parent = node3;
	node7->parent = node3;
	node8->parent = node4;
	return node1;
}

int main() {
	Tree *node1 = buildBinaryTree();
	cout << "build the binarySearchTree:" << endl;
	inorderTreeWalk(node1);
	cout << endl;
	Tree *searchResult = iterativeTreeSearch(node1, 3);
	Tree *max = treeMaximum(node1);
	Tree *min = treeMinimum(node1);
	Tree *parent = getParent(node1, node1);
	Tree *successor = treeSuccessor(node1->left->right);
	cout << "the node1->left->right successor is:" << successor->key << " " << endl;
	Tree *newNode = new Tree();
	newNode->key = 9;
	treeInsert(node1, newNode);
	cout << "insert treeNode which key is 9, and the result is:";
	inorderTreeWalk(node1);
	cout << endl;
	Tree *root = new Tree();
	root->key = 5;
	Tree *node2 = new Tree();
	node2->key = 3;
	treeInsert(root, node2);
	Tree *node3 = new Tree();
	node3->key = 7;
	treeInsert(root, node3);
	Tree *node4 = new Tree();
	node4->key = 2;
	treeInsert(root, node4);
	Tree *node5 = new Tree();
	node5->key = 4;
	treeInsert(root, node5);
	Tree *node6 = new Tree();
	node6->key = 6;
	treeInsert(root, node6);
	Tree *node7 = new Tree();
	node7->key = 8;
	treeInsert(root, node7);
	Tree *node8 = new Tree();
	node8->key = 1;
	treeInsert(root, node8);
	cout << "build tree:";
	inorderTreeWalk(root);
	cout << endl;
	cout << "delete tree node3 :";
	treeDelete(root, node3);
	inorderTreeWalk(root);
	getchar();
	return 0;
}
