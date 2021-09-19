#include<stdio.h>

int temp[5] = { 0, 1, };

int fib(int n) {
	if (n == 0 || n == 1) {
		return temp[n];
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		printf("fib(i) = %d\n", fib(i));
	}
}