#include <string.h>
#include <stdio.h>

typedef char string[46]; // based on the longest word in the English language 

// returns 1 if inputted character is a capital letter and 0 if otherwise 
int isCapital(char letter) {
	if(letter >= 'A' && letter <= 'Z')
		return 1;
	
	return 0; 
}

// returns 1 if inputted character is a letter and 0 if otherwise
int isLetter(char letter) {
	if((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
		return 1;
		
	return 0; 
}

// converts an uppercase latter to lowercase 
char convertLowCase(char letter) {
	if(isCapital(letter))
		letter += 32;

	return letter; 
}

