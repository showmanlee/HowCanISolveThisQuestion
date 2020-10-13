// Z
// https://www.acmicpc.net/problem/1074

#include <stdio.h>
#include <math.h>

int foo(int size, int row, int column) {
	if (size == 1) {
		if (row)
			if (column)
				return 3;
			else
				return 2;
		else
			if (column)
				return 1;
			else
				return 0;
	}
	if (pow(2, size - 1) <= row && pow(2, size - 1) <= column)
		return (int)(pow(pow(2, size - 1), 2) * 3 + foo(size - 1, row - pow(2, size - 1), column - pow(2, size - 1)));
	if (pow(2, size - 1) <= row)
		return (int)(pow(pow(2, size - 1), 2) * 2 + foo(size - 1, row - pow(2, size - 1), column));
	if (pow(2, size - 1) <= column)
		return (int)(pow(pow(2, size - 1), 2) * 1 + foo(size - 1, row, column - pow(2, size - 1)));
	return (int)(foo(size - 1, row, column));
}

int main(void)
{
	int size, row, column;
	scanf("%d %d %d", &size, &row, &column);
	printf("%d", foo(size, row, column));
}