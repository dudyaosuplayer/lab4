#include "DList.h"

using namespace std;

int main() {

	DList e_list;

	e_list.PushBack(12);
	e_list.PushBack(122);
	e_list.PushBack(-25);
	e_list.PushBack(612);

	cout << e_list.PopFront() << endl;

	e_list.PushFront(32);
	e_list.PushFront(-75);
	e_list.PushFront(812);
	
	cout << e_list.PopBack() << endl;

	e_list.Print();

	e_list.Clear();

	e_list.Print();

	system("pause");
	system("cls");
	return 0;
}