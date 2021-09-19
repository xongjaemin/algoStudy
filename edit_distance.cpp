#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//edit distance cost

int min(int a, int b) {
	return (a < b) ? a : b;
}

int edit(char *X, char *Y, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	else if (X[m - 1] == Y[n - 1])
		return edit(X, Y, m - 1, n - 1) + 5;
	else
		return min(edit(X, Y, m - 1, n), edit(X, Y, m, n - 1)) + 10;
}

int main() {
	char X[] = "monkey";
	char Y[] = "money";

	printf("cost : %d\n", edit(X, Y, strlen(X), strlen(Y)));

	return 0;
}