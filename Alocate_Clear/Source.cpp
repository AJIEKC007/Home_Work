#include <iostream>
using namespace std;
#define tab "\t"

void Allocate(int**& arr, int m, int n);
void Clear(int** arr,int m);
void insert_row(int**& arr, int& m, const int n, int index);

void main()
{
	setlocale(LC_ALL, "rus");
	int m;
	int n;
	int i;
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов массива: "; cin >> n;

	int** arr = new int* [m] {};


	Allocate(arr, m, n);


	cout << "Введите индекс добавляемой строки: "; cin >> i;
	insert_row(arr, m, n, i);
	int str;
	cout << "Введите количество добавляемых строк: "; cin >> str;
	for (int i = 0; i < str; i++)
	{
		insert_row(arr, m, n, i);
	}

	cout << "Память выделена!\n";
	system("pause");
	Clear(arr, m);
	
	
}

void Allocate(int**& arr, int m, int n)
{

	
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	cout << "Память выделена!\n";
	system("pause");
}
void Clear(int** arr,int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
delete[] arr;
	cout << "Память очищена!\n";
}
void insert_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m + 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[n] {};
	m++;
}