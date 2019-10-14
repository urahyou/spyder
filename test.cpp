#include<iostream>
#include"SqList.h"
using namespace std;
int main() {
	SqList<int> sqlist;
	for (int i = 1; i < 30; i++) {
		sqlist.insertByOrder(i, i);
	}
	sqlist.traver();
	sqlist.delByOrder(23);
	sqlist.traver();
	sqlist.delFromEnd();
	sqlist.delFromHead();
	sqlist.traver();
	for (int i = 2; i < 23; i++) {
		int e;
		sqlist.getElem(i, e);
		cout << e << " ";
	}
	cout<<endl<<sqlist.Length();
	sqlist.insertFromHead(2000);
	sqlist.traver();
	cout << endl << sqlist.Length();
	sqlist.insertFromEnd(3423);
	cout << endl << sqlist.Length() << endl;
	sqlist.traver();
	//cout << "hell" << endl;
	system("pause");
	return 1;
	//sqlist.insertFromHead(3);
	//sqlist.traver();
	//system("pause");

}