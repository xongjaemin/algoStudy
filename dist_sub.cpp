#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int dist_sub(char* str1, char* str2, int m, int n) {
	if (n > m)
		return 0;

	if (m == 0 || n == 0)
		return 1;
	else if (str1[m - 1] == str2[n - 1]) {
		return dist_sub(str1, str2, m-1, n) + dist_sub(str1, str2, m - 1, n - 1);
	}
	else
		return dist_sub(str1, str2, m-1, n);
}

int main() {
	int test_num = 0;
	char str1[10];
	char str2[10];

	printf("enter the number of test : ");
	scanf_s("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		printf("string 1 : ");
		scanf_s("%s", str1, sizeof(char) * 10);
		printf("string 2 : ");
		scanf_s("%s", str2, sizeof(char) * 10);

		printf("result : %d\n", dist_sub(str1, str2, strlen(str1), strlen(str2)));
	}

	return 0;
}