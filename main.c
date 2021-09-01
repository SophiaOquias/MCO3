#include "bst.h"

int main() {
	nodeType *tree = NULL; // initialize tree
	string words[10] = {"apple", "banana", "banana", "orange", "cherry", "umbrella", "penguin", "orange", "nine", "ten"}; 
	int i;
	
	for(i = 0; i < 10; i++) {
		if(tree == NULL) {
			tree = create(words[i]); 
		}
		else if(search(tree, words[i]) == 1) {
			incrementCount(searchNode(tree, words[i]));
		}
		else
			insert(tree, words[i]); 
	}
	
	inorder(tree); 
	
	
	
	return 0; 
}
