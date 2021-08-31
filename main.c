#include "bst.h"

int main() {
	nodeType *tree = create("first"); 
	
	insert(tree, "word");
	insert(tree, "first"); 
	insert(tree, "animal"); 
	
	inorder(tree); 
	
	return 0; 
}
