#include "bst.h"

// opens input textfile and displays error message if file not found 
FILE *openFile (){
	FILE *fp;
	char fname[100], temp;
  
	do {
    	printf ("Enter filename: ");
    	scanf("%s", fname);
		scanf("%c", &temp); // to accept 
    	fp = fopen(fname, "r");

		if (fp == NULL)
      		printf("<%s> not found\n\n", fname);

  	} while (fp == NULL);
  
  return fp;
}

/* reads text file and stores words in a bst
returns the root node */
nodeType *readFile(FILE *fp, nodeType *root) {
	string temp = "";
	char c; 
	int i = 0, j; 

	while((fscanf(fp, "%c", &c)) == 1) {

		if((isLetter(c) || c == '\'') && c != '\n') {
			if(isCapital(c))
				c = convertLowCase(c); 
			temp[i] = c; 
			i++; 
		}
		else { 
		
			temp[i] = '\0';
			
			// if word begins with an apostrophe (')
			if(temp[0] == '\'') {
				for(j = 0; j < strlen(temp); j++) {
					temp[j] = temp[j + 1];
				}
			}
			
			if(strlen(temp) >= 3) {
				if(root == NULL) 
					root = create(temp); // create node if tree is empty
				else if(search(root, temp) == 1)
					incrementCount(searchNode(root, temp)); // increment count if word already exists in tree
				else
					insert(root, temp); // insert new node if word does not already exist in tree 
			}

			i = 0; 
			strcpy(temp, ""); // reinitialize temp to null string
		}
	}

	return root; 
}

