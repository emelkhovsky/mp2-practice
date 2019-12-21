#include <iostream>
#include <string>
#include "TList.h"
#include "exceptions.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Rus");
	try{
		cout << "------------------------��������----------------------------" << endl;
		cout << "���� ������������ ������" << endl;
		TList<int, int> test;
		cout << test << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list(node0);
		cout << list << endl;

		TList<int, int> list_copy(list);
		cout << "����������� list � list_copy: " << list_copy << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "---------------------------�����---------------------------" << endl;
		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list(node0);

		cout << "����� 3: " << list.Search(3) << endl;
		cout << "����� -1: " << list.Search(-1) << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << endl << "--------------------------PUSHBEGIN-----------------------" << endl;
		TList<int, int> list1;
		list1.PushBegin(4, NULL);
		cout << "� ������ ������ � ������ �������� 4: " << list1 << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list2(node0);
		cout << "� ������ " << list2 << " �������� 9 � ������" << endl;
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
		cout << "� ������ ������ � ����� �������� 5: " << list1 << endl;

		TNode<int, int>* node3 = new TNode<int, int>(3, NULL);
		TNode<int, int>* node2 = new TNode<int, int>(2, NULL, node3);
		TNode<int, int>* node1 = new TNode<int, int>(1, NULL, node2);
		TNode<int, int>* node0 = new TNode<int, int>(0, NULL, node1);
		TList<int, int> list2(node0);
		cout << "� ������ " << list2 << " �������� 9 � �����" << endl;
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

		cout << "� ������ list1: " << list1 << "�������� 30 ����� 2: " << endl;
		list1.PushBefore(2, 30, NULL);
		cout << list1 << endl;

		cout << "� ������ list1: " << list1 << "�������� 30 ����� 78: " << endl;
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

		cout << "� ������ list1: " << list1 << "�������� 30 ����� 2: " << endl;
		list1.PushAfter(2, 30, NULL);
		cout << list1 << endl;

		cout << "� ������ list1: " << list1 << "�������� 30 ����� 78: " << endl;
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

		cout << "�� list1: " << list1 << " ������� 2: " << endl;
		list1.Remove(2);
		cout << list1 << endl;

		cout << "�� list1: " << list1 << " ������� 123: " << endl;
		list1.Remove(123);
		cout << list1 << endl;
	}
	catch (Exception ex)	{
		cout << ex.what() << endl << endl;
	}
	system("pause");
}