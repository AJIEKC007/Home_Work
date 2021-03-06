#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void push_back(int*& arr,int& n, int value);
void push_front(int*& arr,int& n, int value);

void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n, int index);


void main() 
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int [n] {};
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое в конец массива значение: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое в начало массива значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента массива: "<<endl;
	pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление нулевого элемента массива: " << endl;
	pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента массива: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void push_back(int*& arr, int& n, int value)
{
int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
int* buffer = new int[n-1] {};
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void pop_front(int*& arr, int& n)
{
int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	arr = buffer;
	n--;
}