# MCO3

## Members 
- Kalaw, Stacy
- Oquias, Sophia
- Sy, Richard 

### Main Algorithm (Still need to test)
1. While the fscanf does not detect EOF do: 
	1. If the scanned character is a letter, add it to character array word
		1. j++
	2. Else 
		1. the append a null byte to the end of the word 
		2. if root of tree is null, tree = create(word)
		3. else if search(tree, word) returns true, incrementCount(tree, word)
		4. else insert(tree, word); 
		5. strcpy(word, "")
		6. j = 0
	3. i++
	
	
	
	
	