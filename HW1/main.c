#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b) {
	if (a == NULL || b == NULL) {
		return -1;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int *searchmax(int *mas, int size, int sizemax) {
	int err = 0;
	if (mas == NULL) {
		return NULL;
	}
	int i, j;
	for (i = 1; i < size; ++i) {
		for (j = i; j > 0 && mas[j - 1] > mas[j]; j--) {

			err = swap(&mas[j - 1], &mas[j]);
			if (err == -1) {
				return NULL;
			}
		}
	}
	int *buffmax = NULL;
	buffmax = (int *)calloc(sizemax, sizeof(int));
	if (buffmax == NULL) {
		return NULL;

	}
	for (i = 0; i < sizemax; ++i) {
		buffmax[i] = mas[size - i - 1];

	}

	return buffmax;
}


int main() {
	int size = 0;
	int sizemax = 0;
	int err = scanf("%d", &size);
	if (err != 1) {
		printf("[error]");
		return 0;
	}
	int *buff = NULL;
	buff = (int *)calloc(size, sizeof(int));
	if (buff == NULL) {
		printf("[error]");
		return 0;
	}
	int i = 0;
	//enter numbers
	for (i = 0; i < size; ++i) {

		err = scanf("%d", &buff[i]);
		if (err != 1) break;

	}
	err = scanf("%d", &sizemax);
	if (err != 1) {
		printf("[error]");
		free(buff);
		return 0;
	}
	//printf("%d ", i);
	if (size < sizemax || i < size) {

		printf("[error]");
		free(buff);
		return 0;
	}
	int *buffmax = NULL;
	buffmax = searchmax(buff, size, sizemax);
	if (buffmax == NULL) {
		printf("[error]");
		free(buff);
		return 0;
	}
	for (i = 0; i < sizemax; ++i) {

		printf("%d ", buffmax[i]);
	}
	free(buff);
	free(buffmax);
	return 0;
}
