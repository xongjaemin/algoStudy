#include <stdio.h>
#include <string.h>

char hashMap[10][5] = { " ",    " ",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void printWordsUtil(int input[], int index, char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (index == n) {
        printf("%s ", output);
        return;
    }

    // Try all 3 possible characters for current digit in
    // number[] and recur for remaining digits
    for (i = 0; i < strlen(hashMap[input[index]]); i++) {
        output[index] = hashMap[input[index]][i];
        printWordsUtil(input, index + 1, output, n);

        if (input[index] == 0 || input[index] == 1) // keypad 0 and 1 doesn't have alphabet
            return;
    }
}

void printWords(int input[], int n) {
	char* output = (char*)malloc(sizeof(char) * (n + 1));
	output[n] = '\0';
	printWordsUtil(input, 0, output, n);
}

int main(){
	int input[] = {2,3,4};
	int n = sizeof(input) / sizeof(input[0]);
	printWords(input, n);
	
	return 0;
}