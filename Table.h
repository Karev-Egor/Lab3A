//#include h>
#ifndef _ConsoleApplication2_
#define _ConsoleApplication2_
#include <iostream>
int getNum(const char* msg);

struct Item {
	static const int L = 100; //������������ ����� ��������
	int m_key; //����
	int m_busy;//��� busy : 0 - �����, 1 - ���� �������, 2 - ������� ������
	char m_info[L]; //����������

	Item() : m_key(-1), m_busy(0), m_info("") {};
	Item(int key, char* info) : m_key(key), m_busy(1) { strcpy_s(m_info, info); };
};

class Table
{
private:
	static const int SZ = 10; //������������ ������ �������
	Item mas[SZ];
	int top;//������� ������ �������
	int findindex(int k);// ����� ������� �������� ��� �������� ��������
public:
	Table();
	Table(int n);//���������� �������
	void output(); //������� �� �������
	int addElem(int key, char* info); //���������� �������� � �������
	void find(int key); //����� �������� � �������
	void delElem();
	void clear();
	void SetN(int n);
	void findInfo(int key);
	int getSize() const { return top; } // ������� ������ �������
	int getMaxSize() const { return SZ; } //������������ ������ �������
};
#endif