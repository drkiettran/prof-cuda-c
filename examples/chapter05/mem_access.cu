#include <stdio.h>
#include <time.h>

#define ROWS 999
#define COLUMNS 999
int m[ROWS][COLUMNS];
//Taking both dimensions same so that while running the loops,
//number of operations (comparisons, iterations, initializations)
//are exactly the same. Refer this for more
// https://www.geeksforgeeks.org/a-nested-loop-puzzle/

int main() {
	int i, j;
	clock_t start, stop;
	double d = 0.0;

	int count = 1;

	start = clock();
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLUMNS; j++)
			m[i][j] = count++;

	stop = clock();
	d = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("The run-time of %d x %d matrix with row major order is %lf\n", ROWS, COLUMNS, d);

	count = 1;
	start = clock();
	for (j = 0; j < COLUMNS; j++)
		for (i = 0; i < ROWS; i++)
			m[i][j] = count++;

	stop = clock();
	d = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("The run-time of %d x %d matrix with column major order is %lf\n\n", ROWS, COLUMNS, d);
}
