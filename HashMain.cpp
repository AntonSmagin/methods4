#include "stdafx.h"
#include "clocale" 
#include "iostream"
#include <conio.h> 
#include "fstream"
#include "string"
#include "time.h"
#include"hash.h"

using namespace std;

void print(string data)
{
	if (data == "endl")
	{
		cout << endl;
	}
	else
	{
		cout << data;
	}
}


int main()
{

	setlocale(LC_ALL, "Russian");
	hash1 A;
	clock_t t;
	string nameFile, string, substring;
	int data, index;
	int *mass = NULL;
	int elem, n, s, r = 20;
	do {
		system("cls");
		printf("1.Заполнить массив случайными числами\n");
		printf("2.Заполнить массив\n");
		printf("3.Распечатать массив\n");
		printf("4.Создать хеш-таблицу\n");
		printf("5.Распечатать хеш-таблицу\n");
		printf("6.Найти элемент\n");
		printf("7.Добавить элемент\n");
		printf("8.Удалить элемент\n");
		cin >> r;
		switch (r) {
		case 1:
			delete[] mass;
			cout << "Введите количество элементов:";
			cin >> n;
			mass = new int[n];
			for (int i = 0; i < n; i++)
			{
				int data = rand();
				mass[i] = data;
			}
			break;


		case 2:
			delete[] mass;
			cout << "Введите количество элементов:";
			cin >> n;
			mass = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> data;
				mass[i] = data;
			}
			break;


		case 3:
			if (mass == NULL)
			{
				cout << "Массив пуст";
			}
			else
			{
				cout << "Список элементов:" << endl;
				for (int i = 0; i < n; i++)
				{
					cout << mass[i] << endl;
				}
			}
			system("Pause");
			break;



		case 4:
			if (mass != NULL)
			{
				if (n < 3)
				{
					cout << "Elements is few";
					_getch();
				}
				else
				{
					A.hashtable(mass, n);
				}
			}
			else
			{
				cout << "Массив пуст" << endl;
				system("Pause");
			}
			break;


		case 5:
			if (mass != NULL)
			{
				A.showhashtable(print);
			}
			else
			{
				cout << "Массив пуст" << endl;
			}
			system("Pause");
			break;


		case 6:
			cout << "Введите значение элемента:";
			cin >> elem;
			s = A.search(elem);
			if (s == -1)
			{
				cout << "Такой элемент не существует" << endl;
			}
			else
			{
				cout << s << endl;
			}
			system("Pause");
			break;


		case 7:
			cout << "Введите элемент:";
			cin >> elem;
			A.add(elem);
			break;


		case 8:
			if (mass != NULL)
			{
				cout << "Введите значение элемента:";
				cin >> elem;
				s = A.search(elem);
				if (s == -1)
				{
					cout << "Такой элемент не существует" << endl;
				}
				else
				{
					A.del(elem);
					cout << "Элемент удалён" << endl;
				}
			}
			else
			{
				cout << "Массив пуст";
			}
			system("Pause");
			break;






		}

	} while (r);
	system("Pause");
	return 0;

}
