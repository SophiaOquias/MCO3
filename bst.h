#include "sstring.h" // string manipulation header file 
#include <stdlib.h>


typedef struct node {
	string key;
	struct node *left, *right; 
} nodeType; 


// creates a BST that stores strings 
nodeType *create(string word) {
	
	nodeType *node = (nodeType*)malloc(sizeof(nodeType));
	
	strcpy(node->key, word);
	node->left = NULL;
	node->right = NULL;
	
	return node; 
}

// returns 1 if string exists in a tree, 0 if otherwise 
int search(nodeType *node, string key) {
	if(strcmp(key, node->key) == 0) // if key == node->key
		return 1; 
	if(node == NULL)
		return 0;
	if(strcmp(key, node->key) < 0) // if key < node->key 
		return search(node->left, key);
	else
		return search(node->right, key); 
}

// inserts a string into a tree
nodeType *insert(nodeType *node, string word) {
	
	if(strcmp(word, node->key) <= 0) {
		if(node->left == NULL) 
			node->left = create(word); 
		else
			node->left = insert(node->left, word); 
	}
	
	else {
		if(node->right == NULL)
			node->right = create(word); 
		else
			node->right = insert(node->right, word); 
	}
	
	return node; 
}

// prints elements of tree inorder 
void inorder(nodeType *node) {
	if(node != NULL) {
		inorder(node->left); 
		printf("%s\n", node->key); 
		inorder(node->right); 
	}
}
