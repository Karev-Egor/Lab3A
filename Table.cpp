//#include "..\laba3\Table.h"
//namespace EGOR {
//#include <stdafx.h>
#include "Table.h"
#include <iostream>
#include <string.h>
using namespace std;

// про busy : 0 - пусто, 1 - есть элемент, 2 - элемент удален

Table::Table() : top(0)
{
}
Table::Table(int n)
{
	int key;
	char info[100];
	top = 0;

	for (int i = 0; i < n; i++)
	{

		cout << "insert key and info";
		key = getNum("Enter key -> ");
		cin >> info;
		addElem(key, info);
		//mas[i] = Item(key, info);
	}
	//top = n;
}

int getNum(const char* msg)
{
	int k;
	const char* errmsg = "";
	do
	{
		//} while (true);
		//{
		std::cout << errmsg << std::endl;
		std::cout << msg;
		std::cin >> k;
		//			if (std::cin.eof())
		//				return -1;
		if (!(std::cin.good()) || k < 0)
		{
			errmsg = "Invalid value, try again\n";
			std::cin.clear();
			std::cin.ignore(255, '\n');
			//continue;
		}
		else
		{
			std::cin.clear();
			return k;
		}

	} while (true);
}



int Table::addElem(int key, char* info)
{
	//int k;
	//char info[10];

	if (top == SZ) // top это текущее количество элементов в таблице
	{
		//throw std::exception("Table overflow!");
		std::cout << "Table overflow!" << endl;
		return 0;
	}
	for (int i = 0; i < SZ; ++i)
	{
		if (key == mas[i].m_key)
		{
			cout << "Key  not unique" << endl;
			return -1;
		}

		if (mas[i].m_busy == 0 && key != mas[i].m_key)
		{
			mas[i].m_busy = 1;
			strcpy_s(mas[i].m_info, info);
			mas[i].m_key = key;
			top++;
			return 0;
		}
	}

}

void Table::find(int key)
{
	char info;
	for (int i = 0; i < top; ++i)
		if (key == mas[i].m_key && mas[i].m_busy == 1)
		{
			std::cout << "Key found! -> " << key << " " << mas[i].m_info << std::endl;
			return;
		}

	std::cout << "Key not found!" << std::endl;

}

void Table::findInfo(int key)
{
	char info;
	for (int i = 0; i < top; ++i)
		if (key == mas[i].m_key && mas[i].m_busy == 1)
		{
			std::cout << "Info found! -> " << " " << mas[i].m_info << std::endl;
			return;
		}

	std::cout << "Key not found!" << std::endl;

}

int Table::findindex(int k)
{
	for (int i = 0; i < top; ++i)
		if (k == mas[i].m_key && mas[i].m_busy == 1)
		{
			return i;
		}
	return -1;
}

void Table::delElem()
{
	int k, ind;
	k = getNum("Enter key -> "); // ключ элемента для удаления
	ind = findindex(k);
	if (ind != -1)
	{
		mas[ind].m_busy = 2; // 2 - элемент удален
	}
	else
		cout << "Key not found\n";
}

void Table::clear()
{
	for (int i = 0; i < top; ++i)
	{
		if (mas[i].m_busy == 2)
		{
			for (int j = i; j < top; ++j)
			{
				mas[j].m_busy = mas[j + 1].m_busy;
				for (int g = 0; g < 10; ++g)
					mas[j].m_info[g] = mas[j + 1].m_info[g];
				mas[j].m_key = mas[j + 1].m_key;
			}
			--top;
			--i;
		}
	}
}

void Table::output()
{
	for (int i = 0; i < top; ++i)
	{
		if (mas[i].m_busy == 1)
			std::cout << "Key-> " << mas[i].m_key << " Info-> " << mas[i].m_info << std::endl;
		else if (mas[i].m_busy == 2)
			std::cout << "Key-> " << mas[i].m_key << " Info-> " << mas[i].m_info << " DELETED" << std::endl;
	}
}

void Table::SetN(int n)
{
	int key;
	char info[100];

	if (n < 1 || n > 10)
		throw std::exception("");


	for (int i = 0; i < n; i++)
	{
		cout << "insert key and info";
		key = getNum("Enter key -> ");
		cin >> info;
		if (addElem(key, info) < 0)
			i--;
	}
	//top = n;
}
