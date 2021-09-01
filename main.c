#include "bst.h"

int main() {
	nodeType *tree = create("first"); 
	string words[10] = {"apple", "banana", "banana", "orange", "cherry", "umbrella", "penguin", "orange", "nine", "ten"}; 
	int i;
	
	for(i = 0; i < 10; i++) {
		if(search(tree, words[i]) == 1) {
			incrementCount(searchNode(tree, words[i]));
		}
		else
			insert(tree, words[i]); 
	}
	
	inorder(tree); 
	
	return 0; 
}
