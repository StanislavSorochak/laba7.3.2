// Lab_7_3_2.cpp
// < Сорочак Станіслав >
// Лабораторна робота № 7.3.2
//Ітераційний спосіб, Завдання 2
// Варіант 24

#include <iostream>
#include <Windows.h>
#include <iomanip>

void Create(int** matriz, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** matriz, const int rowCount, const int colCount);
void Sidlova(int** matriz, const int rowCount, const int colCount);

int main(void)
{
	srand((unsigned)time(NULL));

	using std::cout;
	using std::endl;

	const int rowCount = 2;
	const int colCount = 2;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	int High = 45;
	int Low = -16;
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	Sidlova(a, rowCount, colCount);

	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	using std::cout;
	using std::endl;
	using std::cin;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << std::setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sidlova(int** a, const int rowCount, const int colCount)
{
	using std::cout;
	using std::endl;
	int* masuv_min = new int[rowCount];
	int* masuv_max = new int[colCount];
	for (int i = 0; i < rowCount; i++)
	{
		masuv_min[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
		{
			int min = a[i][0];
			if (min > a[i][j])
			{
				min = a[i][j];
				masuv_min[i] = a[i][j];
			}
		}
	}
	for (int j = 0; j < colCount; j++)
	{
		masuv_max[j] = a[0][j];
		for (int i = 1; i < rowCount; i++)
		{
			int max = a[0][j];
			if (max < a[i][j])
			{
				max = a[i][j];
				masuv_max[j] = a[i][j];
			}
		}
	}

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			if (masuv_max[i] == masuv_min[j])
			{
				cout << "s_point: " << masuv_max[i] << endl;
				a[j][i] = 0;
			}
			else;
		}
	}
	delete[] masuv_min;
	delete[] masuv_max;
}
