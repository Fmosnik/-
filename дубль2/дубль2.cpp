#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <stddef.h> 
#include <fstream>
int first, last;
using namespace std;
// Шеллом
void ShellSort(int size, int array[])
{
	int h, i, j, tmp;
	for (h = size / 2; h > 0; h /= 2)
		for (i = h; i < size; i++)

			for (j = i - h; j >= 0 && array[j] > array[j + h]; j -= h)
			{
				tmp = array[j];
				array[j] = array[j + h];
				array[j + h] = tmp;
			}
}
// Хоаром
void qicksort(int* a, int first, int last)
{
	int mid, count;
	int i = first, j = last;
	mid = a[(first + last) / 2];
	do {
		while (a[i] < mid)i++;
		while (a[j] > mid)j--;
		if (i <= j) {
			if (i < j) {
				count = a[i];
				a[i] = a[j];
				a[j] = count;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (first < j) { qicksort(a, first, j); };
	if (i < last) {
		qicksort(a, i, last);
	}
}
// Флойдом
void form(int* mass, int root, int bot)
{
	int max;
	int done = 0;
	while ((root * 2 <= bot) && (!done))
	{
		if (root * 2 == bot)
			max = root * 2;

		else if (mass[root * 2] > mass[root * 2 + 1])
			max = root * 2;
		else
			max = root * 2 + 1;

		if (mass[root] < mass[max])
		{
			int temp = mass[root];
			mass[root] = mass[max];
			mass[max] = temp;
			root = max;
		}
		else
			done = 1;
	}
}
void Sort(int* mass, int size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
		form(mass, i, size - 1);
	for (int i = size - 1; i >= 1; i--)
	{
		int temp = mass[0];
		mass[0] = mass[i];
		mass[i] = temp;
		form(mass, 0, i - 1);
	}
}
//Основная программа
int main()
{
	FILE* fyle;
	system("chcp 1251");    // переходим на русский язык в консоли
	system("cls");
	srand(time(NULL));
	clock_t  sh, qui, t;
	int  kod, n, ban = 0, b = 150000;
	int* A = new int[b];

	while (true) {
		cout << " Меню" << endl;
		cout << "1 - Создать массив" << endl;
		cout << "2 - Сортировка методом Флойда" << endl;
		cout << "3 - Сортировка методом Хоара" << endl;
		cout << "4 - Сортировка методом Шелла" << endl;
		cout << "5 - Об Авторе" << endl;
		cout << "6 - О программе" << endl;
		cout << "7 - Выход" << endl;
		cin >> kod;
		system("cls");
		switch (kod) {
		case 1://Создание массива
			int vibor;
			fyle = fopen("start.txt", "w");
			cout << "Способ заполения массива?" << endl;
			cout << "С клавиатуры(1) || Рандомом(2)" << endl;
			cin >> vibor;
			if ((vibor != 1) && (vibor != 2)) {
				cout << "Неверно выбран способ заполнения!" << endl;
				system("pause");
				break;
			}
			if (vibor == 2) {
				cout << "Кол-во элементов массива - " << endl;
				cin >> n;
				if (n <= 0) {
					cout << "Неверно указан размер массива!" << endl;
					break;
				}
				cout << " Исходный массив " << endl;
				for (int i = 0; i < n; i++) {
					A[i] = (rand() % 60 - 20);
					fprintf(fyle, "%d, ", A[i]);
					cout << setw(4) << A[i];
				}
				cout << endl;
			}
			if (vibor == 1) {
				cout << "Кол-во элементов массива - " << endl;
				cin >> n;
				if (n <= 0) {
					cout << "Неверно указан размер массива!" << endl;
					break;
				}
				cout << " Введите элементы массива " << endl;
				for (int i = 0; i < n; i++) {
					cin >> A[i];
					fprintf(fyle, "%d, ", A[i]);
				} system("cls");
				cout << " Исходный массив " << endl;
				for (int i = 0; i < n; i++) {
					cout << setw(4) << A[i];
				} cout << endl;
			}
			fclose(fyle);
			ban = 1;
			break;
		case 2://Сортировка Флойдом
			if (ban != 1) {
				cout << "Не создан массив! Создайте массив!" << endl;
				system("pause");
				break;
			}
			fyle = fopen("Floyd.txt", "w");
			cout << "Сортировка Флойдом - " << endl;
			t = clock();
			Sort(A, n);
			t = clock() - t;
			for (int i = 0; i < n; i++) {
				cout << setw(4) << A[i];
				fprintf(fyle, "%d, ", A[i]);
			}
			fclose(fyle);
			cout << " Время v секундax:" << fixed << (float)t / CLOCKS_PER_SEC << endl;
			cout << endl;
			break;
		case 3://Сортировка Хоаром
			if (ban != 1) {
				cout << "Не создан массив! Создайте массив!" << endl;
				system("pause");
				break;
			}
			fyle = fopen("Xoar.txt", "w");
			first = 0; last = n - 1;
			qui = clock();
			qicksort(A, first, last);
			qui = clock() - qui;
			cout << " Сортировка Хоаром -  " << endl;;
			for (int i = 0; i < n; i++) {
				fprintf(fyle, "%d, ", A[i]);
				cout << setw(4) << A[i];
			}
			fclose(fyle);
			cout << " Время v секундax:" << fixed << (float)qui / CLOCKS_PER_SEC << endl;
			cout << endl;
			break;
		case 4://Сортировка Шеллом
			if (ban != 1) {
				cout << "Не создан массив! Создайте массив!" << endl;
				system("pause");
				break;
			}
			fyle = fopen("Shell.txt", "w");
			sh = clock();
			ShellSort(n, A);
			sh = clock() - sh;
			cout << " Сортировка Шеллом -  " << endl;;
			for (int i = 0; i < n; i++) {
				fprintf(fyle, "%d, ", A[i]);
				cout << setw(4) << A[i];
			}
			fclose(fyle);
			cout << " Время v секундax:" << fixed << (float)sh / CLOCKS_PER_SEC << endl;
			cout << endl;
			break;
		case 5://Автор
			cout << "Шундрик Владислав Владимирович, студент 2 курса, группы А81ИСТ2" << endl;
			system("pause");
			system("cls"); break;
		case 6://Программа
			cout << "Программа предназначена для ознакомления с несколькими методами быстрых сортировок" << endl;
			system("pause");
			system("cls"); break;
		case 7://Выход
			exit(0);
		}
	}
}