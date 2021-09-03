#include "fileRead.h"

int main() {
	nodeType *tree = NULL; // initialize tree
	FILE *fp; 
	
	fp = fopen("input.txt", "r"); 
	
	tree = readFile(fp, tree); 
	
	inorder(tree);

	destroy(tree); 
	
	fclose(fp); 
	
	return 0; 
}
