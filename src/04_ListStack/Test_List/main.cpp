#include <iostream>
#include <string>
#include "TList.h"
#include "exceptions.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Rus");
	try{
		cout << "------------------------СОЗДАНИЕ----------------------------" << endl;
		cout << "Тест невозможного вывода" << endl;
		TList<int, int> test;
		cout << test << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list(node0);
		cout << list << endl;

		TList<int, int> list_copy(list);
		cout << "Скопировали list в list_copy: " << list_copy << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "---------------------------ПОИСК---------------------------" << endl;
		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list(node0);

		cout << "ПОИСК 3: " << list.Search(3) << endl;
		cout << "ПОИСК -1: " << list.Search(-1) << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------PUSHBEGIN-----------------------" << endl;
		TList<int, int> list1;
		list1.PushBegin(4, NULL);
		cout << "В пустой список в начало добавили 4: " << list1 << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list2(node0);
		cout << "В список " << list2 << " добавили 9 в начало" << endl;
		list2.PushBegin(9, NULL);
		cout << list2 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------PUSHEND-----------------------" << endl;
		TList<int, int> list1;
		list1.PushEnd(5, NULL);
		cout << "В пустой список в конец добавили 5: " << list1 << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list2(node0);
		cout << "В список " << list2 << " добавили 9 в конец" << endl;
		list2.PushEnd(9, NULL);
		cout << list2 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------PUSHBEFORE-----------------------" << endl;
		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list1(node0);

		cout << "В список list1: " << list1 << "добавили 30 перед 2: " << endl;
		list1.PushBefore(2, 30, NULL);
		cout << list1 << endl;

		cout << "В список list1: " << list1 << "добавили 30 перед 78: " << endl;
		list1.PushBefore(78, 30, NULL);
		cout << list1 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------PUSHAFTER-----------------------" << endl;
		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list1(node0);

		cout << "В список list1: " << list1 << "добавили 30 после 2: " << endl;
		list1.PushAfter(2, 30, NULL);
		cout << list1 << endl;

		cout << "В список list1: " << list1 << "добавили 30 после 78: " << endl;
		list1.PushAfter(78, 30, NULL);
		cout << list1 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------REMOVE-----------------------" << endl;
		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list1(node0);

		cout << "Из list1: " << list1 << " удалили 2: " << endl;
		list1.Remove(2);
		cout << list1 << endl;

		cout << "Из list1: " << list1 << " удалили 123: " << endl;
		list1.Remove(123);
		cout << list1 << endl;
	}
	catch (Exception ex)	{
		cout << ex.what() << endl << endl;
	}
	system("pause");
}