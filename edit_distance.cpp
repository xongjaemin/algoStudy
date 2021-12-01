#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//edit distance cost

int min(int a, int b, int c) {
	if (a < b && a < c)
		return a;
	if (b < a && b < c)
		return b;
	if (c < a && c < b)
		return c;
}

int edit(char *X, char *Y, int m, int n) {
	if (m == 0)
		return 10 * n;
	if (n == 0)
		return 10 * m;

	if (X[m - 1] == Y[n - 1])
		return edit(X, Y, m - 1, n - 1) + 5;
	else
		return min(edit(X, Y, m - 1, n) + 10, edit(X, Y, m, n - 1) + 10, edit(X, Y, m - 1, n - 1) + 20);
}

int main() {
	char X[] = "monkey";
	char Y[] = "money";

	printf("cost : %d\n", edit(X, Y, strlen(X), strlen(Y)));

	return 0;
}