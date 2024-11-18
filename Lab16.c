#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//1
double* full_elements(double* array, int size) {
	double x = 1;
	double y;
	int i = 0;
	while (i < size) {
		y = x * x * x - 4 * x * x + 2;
		array[i] = y;
		x += 0.2;
		i += 1;
	}
	return array;
}
double* calc_elements(double* array, int size) {
	int i = 0;
	while (i < size) {
		array[i] = array[i] * -1;
		i += 1;
	}
	return array;
}
double put_elements(double* array, int size) {
	int i = 0;
	while (i < size) {
		printf("array[%i]=%lf\n", i + 1, array[i]);
		i += 1;
	}
	calc_elements(array, size);
	int i1 = 0;
	while (i1 < size) {
		printf("Изменённый array[%i]=%lf\n", i1 + 1, array[i1]);
		i1 += 1;
	}
}
//2
double* insert(double* array, int* size, int index) {
	int size_new = (*size) + 1;
	if (array == NULL) return NULL;
	double* array_new = (double*)realloc(array, size_new * sizeof(double));
	if (array_new == NULL)return array;
	array = array_new;
	for (int i = size_new - 1; i > index; i--) {
		array[i] = array[i - 1];
	}
	*size = size_new;
	return array;
}
double* calc_elements1(double* array, int size, int k) {
	for (int i = k; i < (size - 1); i++) array[i-1] = array[i];
	return array;
}
double* full_elements1(double* array, int size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = -1 + rand() % 2;
	}
	return array;
}
double put_elements1(double* array, int size, int k) {
	int i = 0;
	while (i < size) {
		printf("array[%i]=%lf\n", i + 1, array[i]);
		i += 1;
	}
	calc_elements1(array, size, k);
	int i1 = 0;
	while (i1 < size) {
		printf("Изменённый array[%i]=%lf\n", i1 + 1, array[i1]);
		i1 += 1;
	}
}
double put_elements2(double* array, int size) {
	int i = 0;
	while (i < size) {
		printf("array[%i]=%lf\n", i + 1, array[i]);
		i += 1;
	}
}
int index1(double* array, int size, int index) {
	int minus = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] < 0)minus = i;
	}
	index = minus;
	return index;
}
void main() {
	setlocale(LC_CTYPE, "RUS");
	double* array;
	int size;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	array = (double*)malloc(size);
	if (array == NULL) {
		puts("error");
		return -1;
	}
	//1
	full_elements(array, size);
	put_elements(array, size);
	//2
	printf("\nЗадание 2\n");
	int k;
	printf("Удалить элемент k массива\nВведите k >");
	scanf("%i", &k);
	full_elements1(array, size);
	put_elements1(array, size, k);
	printf("Задание 2.2\n");
	int index=0;
	index1(array, size, index);
	index = index1(array, size, index);
	insert(array, &size, index);
	int num = -999;
	array[index] = num;
	put_elements2(array, size);
}