#include<iostream>
#include<windows.h>
#include"part_A.h"
using namespace std;
int main()
{
	/*Stack<int> L;
	cout << L.isEmpty() << endl;
	L.isFull();
	L.Push(7);
	L.Push(7);
	L.Push(7);
	L.Pop();
	L.Pop();
	L.Pop();
	cout << L.isEmpty() << endl;*/
	HANDLE hConsole;
	int k = 3;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// pick the colorattribute k you want
	SetConsoleTextAttribute(hConsole, k);
	torr<string> t;
	t.url();
	

	return 0;
}

