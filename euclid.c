#include <stdio.h>

int x, y = 0;
int d = 0;

int extended_euclid(int a, int b) {
	int temp;

	if (b == 0) {
		x = 1;
		y = 0;
		d = a;
		return;
	}
	else {
		extended_euclid(b, a % b);
		temp = y;
		y = x - (a / b)*y;
		x = temp;
	}
}

void main() {
	int a, b = 0;

	scanf("%d", &a);
	scanf("%d", &b);

	extended_euclid(a, b);

	printf("%d %d %d",x, y, d);
}