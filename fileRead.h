#include "bst.h"

nodeType *readFile(FILE *fp, nodeType *root) {
	string temp = "";
	char c; 
	int i = 0;
	
	// while there are still characters to read in the text file 
	while((fscanf(fp, "%c", &c)) == 1) {
		
		if(isLetter(c) && c != '\n') {
			temp[i] = c; 
			i++; 
		}
		else {
			temp[i] = '\0'; 
			
			convertLowCase(temp); 
			
			if(strlen(temp) >= 3) { // check if word is not less than 3 letters in length 
				if(root == NULL) {
					root = create(temp); 
				}
				else if (search(root, temp) == 1) {  // increment count of word if already exists in tree
					incrementCount(searchNode(root, temp)); 
				}
				else { // insert new node if not found
					insert(root, temp); 
				}
			}
			
			i = 0; 
			strcpy(temp, ""); 
		}

	} 
	
	return root; 
}
