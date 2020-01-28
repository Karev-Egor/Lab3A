//#include h>
#ifndef _ConsoleApplication2_
#define _ConsoleApplication2_
#include <iostream>
int getNum(const char* msg);

struct Item {
	static const int L = 100; //Максимальная длина элемента
	int m_key; //Ключ
	int m_busy;//Про busy : 0 - пусто, 1 - есть элемент, 2 - элемент удален
	char m_info[L]; //Информация

	Item() : m_key(-1), m_busy(0), m_info("") {};
	Item(int key, char* info) : m_key(key), m_busy(1) { strcpy_s(m_info, info); };
};

class Table
{
private:
	static const int SZ = 10; //Максимальный размер таблицы
	Item mas[SZ];
	int top;//Текущий размер таблицы
	int findindex(int k);// Поиск индекса элемента для удаления элемента
public:
	Table();
	Table(int n);//Заполнение таблицы
	void output(); //Выборка из таблицы
	int addElem(int key, char* info); //Добавление элемента в таблицу
	void find(int key); //Поиск элемента в таблице
	void delElem();
	void clear();
	void SetN(int n);
	void findInfo(int key);
	int getSize() const { return top; } // Текущий размер таблицы
	int getMaxSize() const { return SZ; } //Максимальный размер таблицы
};
#endif