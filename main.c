#include "fileRead.h"

int main() {
	nodeType *tree = NULL; // initialize tree
	string filename; 
	FILE *fp; 
	char temp; 
	
	do {
		fprintf(stdout, "enter filename (<filename>.txt): ");
		fscanf(stdin, "%s", filename); 
		fscanf(stdin, "%c", &temp); // to ignore the enter key 
		
		if((fp = fopen(filename, "r")) == NULL)
			fprintf(stderr, "<%s> not found\n", filename);
			
		fprintf(stdout, "\n\n");
			
	} while((fp = fopen(filename, "r")) == NULL);
	
	tree = readFile(fp, tree); 
	
	inorder(tree);
	
	fclose(fp);
	
	fp = fopen("WORDS.txt", "w"); 
	
	outputFile(fp, tree);
	fprintf(stdout, "\n\nOutput file WORDS.txt successfully created"); 
	
	fclose(fp); 

	destroy(tree);  
	
	return 0; 
}
