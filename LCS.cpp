#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int x, int y) {
	return (x > y) ? x : y;
}

//Longest Common Subsequence
int LCS(char *X, char *Y, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	else if (X[m-1] == Y[n-1]) {
		return 1 + LCS(X, Y, m - 1, n - 1);
	}
	else {
		return max(LCS(X, Y, m - 1, n), LCS(X, Y, m, n - 1));
	}
}

int main() {
	char X[] = "spanking";
	char Y[] = "amputation";

	int m = strlen(X);
	int n = strlen(Y);

	printf("answer : %d\n", LCS(X, Y, m, n));

	return 0;
}