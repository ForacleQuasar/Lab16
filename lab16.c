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
	for (int i = k; i < (size - 1); i++) array[i - 1] = array[i];
	return array;
}
double* full_elements1(double* array, int size) {
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
//3
double* full_elements2(int size) {
	double* array_ = (double*)malloc(size * sizeof(double));
	for (int i = 0; i < size; i++) {
		array_[i] = (double)rand() / RAND_MAX * 100;
	}
	return array_;
}
double* array_join(double* array1, int size1, double* array2, int size2, double* array3, int size3) {
	int Fullsize = size1 + size2 + size3;
	double* new_array = (double*)malloc(Fullsize * sizeof(double));
	int i = 0, i1 = 0, i2 = 0, i3 = 0;
	while (i1 < size1 || i2 < size2 || i3 < size3) {
		if (i1 < size1)new_array[i++] = array1[i1++];
		if (i2 < size2)new_array[i++] = array2[i2++];
		if (i3 < size3)new_array[i++] = array3[i3++];
	}
	return new_array;
}
void put_elements3(double* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("array[%i]=%lf\n", i + 1, array[i]);
	}
}
void main() {
	setlocale(LC_CTYPE, "RUS");
	double* array;
	int size;
	srand((unsigned)time(NULL));
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
	int index = 0;
	index1(array, size, index);
	index = index1(array, size, index);
	insert(array, &size, index);
	int num = -999;
	array[index] = num;
	put_elements2(array, size);
	//3
	printf("Задание 3\n");
	int size1 = rand() % 41 + 10; 
	int size2 = rand() % 41 + 10;
	int size3 = rand() % 41 + 10;
	double* array1 = full_elements2(size1);
	double* array2 = full_elements2(size2);
	double* array3 = full_elements2(size3);
	printf("Первый массив >\n");
	put_elements3(array1, size1);
	printf("\n");
	printf("Второй массив > \n");
	put_elements3(array2, size2);
	printf("\n");
	printf("Третий массив > \n");
	put_elements3(array3, size3);
	printf("\n");
	double* new_array = array_join(array1, size1, array2, size2, array3, size3);
	printf("Соединйнный четвёртый массив > \n");
	put_elements3(new_array, size1 + size2 + size3);

}