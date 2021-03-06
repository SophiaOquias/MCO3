#include "sstring.h" // string manipulation header file 
#include <stdlib.h>


typedef struct node {
	string key;
	int count; 
	struct node *left, *right; 
} nodeType; 


// creates a BST that stores strings 
nodeType *create(string word) {
	
	nodeType *node = (nodeType*)malloc(sizeof(nodeType));
	
	strcpy(node->key, word);
	node->count = 1; 
	node->left = NULL;
	node->right = NULL;
	
	return node; 
}

// returns the node that matches the key 
nodeType *searchNode(nodeType *node, string key) {
	if(node == NULL || strcmp(key, node->key) == 0) // if key == node->key
		return node;
	if(strcmp(key, node->key) < 0) // if key < node->key
		return searchNode(node->left, key);
	else
		return searchNode(node->right, key);
}

// returns 1 if string exists in a tree, 0 if otherwise 
int search(nodeType *node, string key) {
	if(searchNode(node, key) == NULL)
		return 0; 
	else
		return 1; 
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
void inorder(nodeType *node, FILE *fp) {
	if(node != NULL) {
		inorder(node->left, fp); 
		printf("%-15s\t:\t%d\n", node->key, node->count);
		fprintf(fp,"%-15s\t:\t%d\n", node->key, node->count); /*word.txt*/
		inorder(node->right, fp); 
	}
}

// destroys tree 
void destroy(nodeType *node)  {
	if(node != NULL) {
		destroy(node->left);
		node->left = NULL; 
		destroy(node->right);
		node->right = NULL; 
		free(node); 
	}
}

// increments count property in node
void incrementCount(nodeType *node) {
	node->count += 1; 
}

