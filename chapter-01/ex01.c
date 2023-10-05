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
#pragma region Solution 1 
/// @brief First implementation. Takes O(N²) to compute
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
				return false;
			}
		}
	}
	return true;
}

void run01(char string[], int length){
	printf("----------------Running Solution 1----------------\n");
	bool allUnique = isUniqueCharString01(string, length);
	if(allUnique){
		printf("The string has all unique chars.\n");
	}else{
		printf("String has repeated characters.\n");
	}
	printf("--------------------------------------------------\n");
}

#pragma endregion

#pragma region Solution 2
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
		}else{
			break;
		}

		if(++charsCounter[index] > 1){
			printf("Repeated char: %c", c);
			return false;
		}
	}

	return true;
}

void run02(char string[], int length){
	printf("----------------Running Solution 2----------------\n");
	bool allUnique = isUniqueCharacterString02(string, length);
	if(allUnique){
		printf("The string has all unique chars.\n");
	}else{
		printf("String has repeated characters.\n");
	}
	printf("--------------------------------------------------\n");
}
#pragma endregion

#pragma region Solution 3

bool isUniqueCharactersString03(char string[], int length){
	int checker = 0; // bit vector initialized with 0000 (32 different values will test only for a-z)

	for(int i = 0; i < length; i++){
		char c = string[i];
		
		
		// maps A-a to 0, B-b to 1 and so on...
		if(c >= 65 && c <= 90){
			c -= 'a';
		} else if(c >= 97 && c <= 122){
			c -= 'A';
		}else{
			break;
		}
		// rotates 1(0001) c times. Ex.: c = 5  1 << 5 = 00010000
		int charBit = 1 << c;
		
		if((charBit & checker) > 0){
			return false;
		}
		
		checker |= charBit; 
	}

	return true;
}

void run03(char string[], int length){
	printf("----------------Running Solution 3----------------\n");
	bool isUnique = isUniqueCharactersString03(string, length);
	if(isUnique){
		printf("String has only unique characters.\n");
	}else{
		printf("String has repeated characters.\n");
	}
	printf("--------------------------------------------------\n");
}

#pragma endregion
int main(){
	const int length = 50;
	char s[50];

	initializeStrignArray(s, length);
	scanf("%s", s);	

	run01(s, length);
	run02(s, length);	
	run03(s, length);	
}