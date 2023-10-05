#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int length){
	for(int i = 0; i < length; i++){
		printf("%c - %d\n", i + 'a', array[i]);	
	}
	printf("\n");
}

bool testPermutation(char str1[], int length1, char str2[], int length2){
	int charCounter[26] = {0}; 
	
	for(int i = 0; i < length1; i++){
		int index = str1[i] - 'a';
		charCounter[index]++;
	}

	printArray(charCounter, 26);

	for(int i = 0; i < length2; i++){
		int index = str2[i] - 'a';
		if(charCounter[index] != 0){
			charCounter[index]--;
		}
	}
	printArray(charCounter, 26);
	for(int i = 0; i < 26; i++){
		if(charCounter[i] != 0){
			return false;
		}
	}

	return true;
}

bool arePermutation(char str1[], int length1, char str2[], int length2){
	if(length1 > length2){
		bool result = testPermutation(str2, length2, str1, length1);
		if(result){
			printf("Are permutation\n");
			return true;
		}

	}else{
		bool result = testPermutation(str1, length1, str2, length2);
		if(result){
			printf("Are permutation\n");
			return true;
		}
	}

	printf("Are not permutation\n");
	return false;
}

int main(){
	char str1[25] ={'\n'}, str2[25] = {'\n'};

	scanf("%s", str1);
	scanf("%s", str2);

	int length1, length2;
	for(int i = 0; i < 25; i++){
		if(str1[i] != '\n'){
			length1++;
		}
		if(str2[i] != '\n'){
			length2++;
		}
	}
	printf("%d - %d\n", length1, length2);

	arePermutation(str1, length1, str2, length2);
	return 0;
}