/*
	Implement an algorithm to determine if a string has all unique characters.
	What if you cannot use additional data structures?
*/

#include <stdio.h>
#include <stdbool.h>

void initializeStrignArray(char array[], int length){
	for(int i = 0; i < length; i++){
		array[i] = '\n';
	}
}

/// @brief First implementation. Takes N log N to compute
/// @param string 
/// @param length 
/// @return 
bool isUniqueCharString01(char string[], int length){
	for(int i = 0; i < 50; i++){
		if(string[i] == '\n'){
			break;
		}
		char letter = string[i];

		for(int j = i+1; j < 50; j++){
			if(string[j] == '\n'){
				break;
			}
		
			if(letter == string[j]){
				printf("Repeated: %c", letter);
				return false;
			}
		}
	}
	return true;
}

void run01(char string[], int length){
	bool allUnique = isUniqueCharString01(string, length);
	if(allUnique){
		printf("The string has all unique chars.\n");
	}
}

bool isUniqueCharacterString02(char string[], int length){
	int charsCounter[35] = {0};

	for(int i = 0; i < length; i++){
		char c = string[i];
		int index;
		if(c >= 65 && c <= 90){
			index = c-65;
		}else if(c >= 97 && c <= 122){
			index = c - 97;
		}else if(c >= 48 && c <= 57){
			index = c + 26 - 48;
			// 0 = 48
			// 48+25 - 48
			// 25
		}

		

		if(++charsCounter[index] > 1){
			printf("Repeated char: %c", c);
			return false;
		}
	}

	return false;
}

void run02(char string[], int length){
	isUniqueCharacterString02(string, length);
}

int main(){
	const int length = 50;
	char s[50];

	initializeStrignArray(s, length);
	scanf("%s", s);	

	// run01(s, length);
	run02(s, length);	
}