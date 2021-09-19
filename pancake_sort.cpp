#include<stdio.h>
#include<string.h>

void flip(int* pancake, int index) {
	int start = 0;
	int temp = 0;
	for (int i = 0; i < index; i++) {
		temp = pancake[index];
		pancake[index] = pancake[start];
		pancake[start] = temp;
		start++;
		index--;
	}
	
}

void sort(int *pancake, int n) {
	int max_value = 0;
	int max_index = 0;

	for (int curr = n; curr > 0; curr--) {

		//find maximum value and index
		max_value = 0;
		max_index = 0;
		for (int i = 0; i < curr; i++) {
			if (pancake[i] >= max_value) {
				max_value = pancake[i];
				max_index = i;
			}
		}

		//if maximum value is not at the end
		if (max_index != curr - 1) {
			if (max_index != 0) {
				flip(pancake, max_index); //move max value to first place
				printf("flip %d ", n - max_index);
			}

			flip(pancake, curr-1); //move max value to the end
			printf("flip %d ", n - (curr-1));
		}
	}
	printf("flip 0");
	printf("\n");
}

int main() {
	int n, testNum;
	int pancake[30];

	printf("number of tests : ");
	scanf_s("%d", &testNum);
	printf("\n");
	printf("=================\n");

	for (int j = 0; j < testNum; j++) {
		printf("insert number of pancakes : ");
		scanf_s("%d", &n);

		printf("\ninsert diameter of pancakes : ");

		for (int i = 0; i < n; i++) {
			scanf_s("%d", &pancake[i]);
		}

		printf("\n");

		sort(pancake, n);

		for (int i = 0; i < n; i++) {
			printf("%d ", pancake[i]);
		}

		printf("\n");
		printf("=================\n");
	}

}