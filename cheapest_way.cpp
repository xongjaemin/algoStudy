#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int temp = 0;
	int row = 5, col = 6;

	scanf_s("%d", &row);
	scanf_s("%d", &col);

	int** matrix = (int**)malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}

	int** cost_mat = (int**)malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		cost_mat[i] = (int*)malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++) {
		cost_mat[i][0] = matrix[i][0];
	}

	for (int i = 0; i < col - 1; i++) {
		for (int j = 0; j < row; j++) {
			if (j == 0) { //first row
				cost_mat[row - 1][i + 1] = matrix[row - 1][i + 1] + cost_mat[j][i];
				cost_mat[j][i + 1] = matrix[j][i+1] + cost_mat[j][i];
				cost_mat[j + 1][i + 1] = matrix[j + 1][i + 1] + cost_mat[j][i];
			}
			else if (j == row - 1) { //last row
				temp = matrix[j - 1][i + 1] + cost_mat[j][i];
				if (temp < cost_mat[j - 1][i + 1]) {
					cost_mat[j - 1][i + 1] = temp;
				}
				
				temp = matrix[j][i + 1] + cost_mat[j][i];
				if (temp < cost_mat[j][i + 1]) {
					cost_mat[j][i + 1] = temp;
				}

				temp = matrix[0][i + 1] + cost_mat[j][i];
				if (temp < cost_mat[0][i + 1]) {
					cost_mat[0][i + 1] = temp;
				}
			}
			else { //the other rows
				temp = matrix[j - 1][i + 1] + cost_mat[j][i];
				if (temp < cost_mat[j - 1][i + 1]) {
					cost_mat[j - 1][i + 1] = temp;
				}

				temp = matrix[j][i + 1] + cost_mat[j][i];
				if (temp < cost_mat[j][i + 1]) {
					cost_mat[j][i + 1] = temp;
				}

				if (j == row - 2) {
					temp = matrix[j + 1][i + 1] + cost_mat[j][i];
					if (temp < cost_mat[j + 1][i + 1]) {
						cost_mat[j + 1][i + 1] = temp;
					}
				}
				else {
					cost_mat[j + 1][i + 1] = matrix[j + 1][i + 1] + cost_mat[j][i];
				}
			}
		}
	}

	/*
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", cost_mat[i][j]);
		}
		printf("\n");
	}
	*/
	int path[10] = { 0, };
	int currX = row - 1;
	int currY = col - 1;
	int result = matrix[currX][currY];
	temp = 8;

	path[9] = currX + 1;

	while (1) {
		if (currX == row - 1) {
			if ((cost_mat[currX - 1][currY - 1] <= cost_mat[currX][currY - 1]) && (cost_mat[currX - 1][currY - 1] <= cost_mat[0][currY - 1])) {
				path[temp] = currX;
				result += matrix[currX - 1][currY - 1];
				temp--;
				currX--;
				currY--;
			}

			else if ((cost_mat[currX][currY - 1] < cost_mat[currX - 1][currY - 1]) && (cost_mat[currX][currY - 1] < cost_mat[0][currY - 1])) {
				path[temp] = currX + 1;
				result += matrix[currX][currY - 1];
				temp--;
				currY--;
			}

			else {
				path[temp] = 1;
				result += matrix[0][currY - 1];
				temp--;
				currX = 0;
				currY--;
			}
		}

		else if (currX == 0) {
			if ((cost_mat[row - 1][currY - 1] < cost_mat[currX][currY - 1]) && (cost_mat[row - 1][currY - 1] < cost_mat[currX + 1][currY - 1])) {
				path[temp] = row;
				result += matrix[row - 1][currY - 1];
				temp--;
				currX = row - 1;
				currY--;
			}

			else if ((cost_mat[currX][currY - 1] < cost_mat[row - 1][currY - 1]) && (cost_mat[currX][currY - 1] < cost_mat[currX + 1][currY - 1])) {
				path[temp] = currX + 1;
				result += matrix[currX][currY - 1];
				temp--;
				currY--;
			}

			else {
				path[temp] = currX + 2;
				result += matrix[currX + 1][currY - 1];
				temp--;
				currX++;
				currY--;
			}
		}

		else {
			if ((cost_mat[currX - 1][currY - 1] <= cost_mat[currX][currY - 1]) && (cost_mat[currX - 1][currY - 1] <= cost_mat[currX + 1][currY - 1])) {
				path[temp] = currX;
				result += matrix[currX - 1][currY - 1];
				temp--;
				currX--;
				currY--;
			}

			else if ((cost_mat[currX][currY - 1] < cost_mat[currX - 1][currY - 1]) && (cost_mat[currX][currY - 1] < cost_mat[currX + 1][currY - 1])) {
				path[temp] = currX + 1;
				result += matrix[currX][currY - 1];
				temp--;
				currY--;
			}

			else {
				path[temp] = currX + 2;
				result += matrix[currX + 1][currY - 1];
				temp--;
				currX++;
				currY--;
			}
		}

		if (currX == 0 && currY == 0)
			break;
	}

	printf("\n");

	for (int i = temp+1; i < 10; i++) {
		printf("%d ", path[i]);
	}

	printf("\n");

	printf("%d", cost_mat[row - 1][col - 1]);

	return 0;
}