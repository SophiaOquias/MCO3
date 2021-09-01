#include "bst.h"

int main() {
	nodeType *tree = create("first"); 
	string word1 = "word"; 
	
	insert(tree, "word");
	insert(tree, "animal"); 
	
	if(search(tree, word1)) {
		incrementCount(searchNode(tree, word1));
	}
	else {
		insert(tree, word1); 
	}
	
	inorder(tree); 
	
	if(search(tree, "exist") == 0)
    	printf("not exist\n"); 
	
	return 0; 
}
