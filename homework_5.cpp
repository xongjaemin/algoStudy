#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Train {
	int time;
	char city[10];
}Train;

int main() {
	int city_num, train_set_num;
	int test_num;
	int temp;
	int train_in_set[100];
	int first_time;
	char city[20][10];
	char start_city[20];
	char end_city[20];
	int path[10][2];
	Train train[10][10];
	Train curr;
	//char curr[10];
	int min_path[2];
	int count = 0;
	int q = 0;
	int t = 0;
	path[0][0] = -10;

	scanf("%d", &test_num);

	while (test_num > 0) {
		scanf("%d", &city_num);

		for (int i = 0; i < city_num; i++) {
			scanf("%s", city[i]);
		}

		scanf("%d", &train_set_num);

		for (int i = 0; i < train_set_num; i++) {
			scanf("%d", &temp);
			train_in_set[i] = temp - 1;
			for (int j = 0; j < temp; j++) {
				scanf("%d", &train[i][j].time);
				scanf("%s", train[i][j].city);
			}
		}

		scanf("%d", &first_time);
		scanf("%s", start_city);
		scanf("%s", end_city);


		/*finding every path*/
		for (int i = 0; i < train_set_num; i++) {
			if (strcmp(train[i][0].city, start_city) == 0) {
				if (train[i][0].time >= first_time) {
					if (strcmp(train[i][train_in_set[i]].city, end_city) == 0) {
						path[t][0] = train[i][0].time;
						path[t][1] = train[i][train_in_set[i]].time;
						t++;
					}

					else {
						count = 0;
						q = 0;
						strcpy(curr.city, train[i][train_in_set[i]].city);
						curr.time = train[i][train_in_set[i]].time;
						for (int j = 0; j < train_set_num; j++) {
							if (strcmp(curr.city, train[j][0].city) == 0 && (curr.time <= train[j][0].time)) {
								if (strcmp(train[j][train_in_set[j]].city, end_city) == 0) {
									path[t][0] = train[i][0].time;
									path[t][1] = train[j][train_in_set[j]].time;
									t++;
								}
								else {
									strcpy(curr.city, train[j][train_in_set[j]].city);
									curr.time = train[j][train_in_set[j]].time;
									if (count == 0) {
										q = j;
									}
									j = 0;
									count++;
									if (count == train_set_num) {
										count = 0;
										curr.time = train[q + 1]->time;
										strcpy(curr.city, train[q + 1]->city);
										q = 0;
									}
								}
							}
						}
					}
				}
			}
		}

		/*
		* print every path
		for (int i = 0; i < t; i++) {
			printf("%d\n", path[i][0]);
			printf("%d\n", path[i][1]);
			printf("===========\n");
		}
		*/

		/*finding fastest path*/
		min_path[0] = path[0][0];
		min_path[1] = path[0][1];
		for (int i = 0; i < t; i++) {
			if (path[i][1] < min_path[1]) {
				min_path[0] = path[i][0];
				min_path[1] = path[i][1];
			}
			else if ((path[i][1] == min_path[1]) && (path[i][0] > min_path[0])) {
				min_path[0] = path[i][0];
				min_path[1] = path[i][1];
			}
		}

		/*output*/
		printf("\n========output=========\n");
		if (path[0][0] == -10) {
			printf("No connection\n");
		}
		else {
			printf("Departure : %d %s\n", min_path[0], start_city);
			printf("Arrival : %d %s\n", min_path[1], end_city);
		}

		test_num--;
	}

	return 0;
}