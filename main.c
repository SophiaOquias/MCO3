#include "fileRead.h"

int main() { 
	
  	FILE *input;
  	FILE *output; /*WORDS.txt*/
	nodeType *tree = NULL; 

	input = openFile(); 

	tree = readFile(input, tree);  
	
  	output = fopen("WORDS.txt","w"); /*WORDS.txt*/
  
	inorder(tree, output); 
	printf("\n\nOutput saved in WORDS.txt"); 
	
	fclose(input);
	fclose(output);

  	destroy(tree);
	
	return 0; 
}

