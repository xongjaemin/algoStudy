#include<stdio.h>

int result1, result2;

int jewel(int num, int c1, int n1, int c2, int n2) {
	result1 = 0;
	result2 = 0;
	/*check cost-effectivity of each jewel box*/
	float effectivity1 = (float)n1 / c1;
	float effectivity2 = (float)n2 / c2;

	if (effectivity1 > effectivity2) {
		result1 = num / n1;

		if (result1 * n1 != num) {
			while (result1 >= 0) {
				if ((num - result1 * n1) % n2 == 0) {
					result2 = (num - result1 * n1) / n2;
					return 1;
				}
				else
					result1--;
			}
			return 0;
		}
		else
			return 1;
	}

	else {
		result2 = num / n2;

		if (result2 * n2 != num) {
			while (result2 >= 0) {
				if ((num - result2 * n2) % n1 == 0) {
					result1 = (num - result2 * n2) / n1;
					return 1;
				}
				else
					result2--;
			}
			return 0;
		}
		else
			return 1;
	}
}

int main() {
	int num = -1;

	int c1, n1, c2, n2;

	while (1) {
		scanf("%d", &num);

		if (num == 0)
			return 0;

		scanf("%d %d", &c1, &n1);
		scanf("%d %d", &c2, &n2);

		if (jewel(num, c1, n1, c2, n2) == 1)
			printf("%d %d\n", result1, result2);
		else
			printf("failed\n");
	}

	return 0;
}