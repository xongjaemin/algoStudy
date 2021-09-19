#include<string.h>
#include<stdio.h>

int main() {
	int test_num = 0;

	printf("enter the number of test : ");
	scanf_s("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		char str1[10] = " ";
		char str2[10] = " ";

		printf("string 1 : ");
		scanf_s("%s", str1);
		printf("string 2 : ");
		scanf_s("%s", str2);

		printf("result : ");
	}
}