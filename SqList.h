/*
*content: 顺序表的类实现
*author: urahyou
*date: 2019/10/13
*/
#ifndef _SqList_h
#define _SqList_h

#include<iostream>
using namespace std;
//定义一些常量
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0






//别名定义
typedef int Status;

template<typename T>
class SqList {
public:
	//构造函数，构造一个空的顺序表L
	SqList();
	//析构函数，销毁顺序表L
	~SqList();

	//初始化一个空顺序表
	Status initList();
	//销毁一个顺序表
	Status destroy();
	//清空顺序表
	Status clear();
	
	//返回顺序表的大小
	int Length();
	
	//判断是否为空表
	Status isEmpty();
	
	//获取指定位置上的元素
	Status getElem(int order, T &e);
	
	//根据元素值查找顺序表中的某个元素，找到了就返回序号；找不到就返回FALSE
	int locateElem(T e);
	
	//在指定位置插入元素
	Status insertByOrder(int order, T e);
	//在表头插入元素
	Status insertFromHead(T e);
	//在表尾插入元素
	Status insertFromEnd(T e);
	
	//删除指定位置的元素,成功则返回被删除的元素值，否则返回FALSE
	T delByOrder(int order);
	//删除表头元素,成功则返回被删除的元素值，否则返回FALSE
	T delFromHead();
	//删除表尾元素,成功则返回被删除的元素值，否则返回FALSE
	T delFromEnd();

	//遍历链表
	void traver();

private:
	T *elem;
	int length;
};

using namespace std;

//构造函数，构造一个空的线性表L
template<typename T>
SqList<T>::SqList() {
	if (initList()) {
		cout << "链表创建成功！" << endl;
	}
	else {
		cout << "链表创建失败!" << endl;
	}
}

//析构函数，销毁一个线性表L
template<typename T>
SqList<T>::~SqList() {
	if (destroy()) {
		cout << "链表销毁成功！" << endl;
	}
	else {
		cout << "链表销毁失败！" << endl;
	}
	
}

//初始化一个空表
template<typename T>
Status SqList<T>::initList() {
	elem = new T[MAXSIZE];
	if (!elem) {
		length = 0;
		return FALSE;
	}
	return TRUE;
}

//销毁顺序表,如果表不为空，摧毁并返回OK，否则返回
template<typename T>
Status SqList<T>::destroy() {
	if (!elem) {
		return ERROR;
	}
	delete[] elem;
	length = 0;
	return OK;
}

//清空顺序表
template<typename T>
Status SqList<T>::clear() {
	length = 0;
	return OK;
}

//返回链表长度
template<typename T>
int SqList<T>::Length() {
	return length;
}

//判断是否为空表
template<typename T>
Status SqList<T>::isEmpty() {
	if (!length) {
		return YES;
	}
	return NO;
}

//获取指定位置上的元素
template<typename T>
Status SqList<T>::getElem(int order, T &e) {
	if (order < 0) {
		cout << "下标小于0！" << endl;
		return ERROR;
	}
	if (order > length) {
		cout << "下标大于线性表长度！" << endl;
		return ERROR;
	}
	e = elem[order-1];
	return OK;
}

//根据元素值查找顺序表中的某个元素，找到了就返回序号；找不到就返回0
template<typename T>
int SqList<T>::locateElem(T e) {
	if (isEmpty()) {
		cout << "链表为空!" << endl;
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (e == elem[i]) {
			return i + 1;
		}
	}
	return 0;
}

//在指定位置插入元素
template<typename T>
Status SqList<T>::insertByOrder(int order, T e) {
	if (order<0 || order>=MAXSIZE) {
		cout << "超出有效范围!" << endl;
		return ERROR;
	}
	if (length >= MAXSIZE) {
		cout << "链表已满!" << endl;
		return ERROR;
	}
	//插入位置往后的元素后移
	for (int i = length; i >= order; i--) {
		elem[i] = elem[i - 1];
	}
	//插入元素
	elem[order - 1] = e;
	length++;
	return OK;
}

//在表头插入元素
template<typename T>
Status SqList<T>::insertFromHead(T e) {
	return insertByOrder(1, e);
}

//在表尾插入元素
template<typename T>
Status SqList<T>::insertFromEnd(T e) {
	return insertByOrder(length+1, e);
}

//删除指定位置的元素,成功则返回被删除的元素值，否则返回ERROR
template<typename T>
T SqList<T>::delByOrder(int order) {
	if (order <= 0 || order > length) {
		return ERROR;
	}
	for (int i = order - 1; i < length - 1; i++) {
		elem[i] = elem[i + 1];
	}
	length--;
	return OK;
}

//删除表头元素,成功则返回被删除的元素值，否则返回FALSE
template<typename T>
T SqList<T>::delFromHead() {
	return delByOrder(1);
}

//删除表尾元素,成功则返回被删除的元素值，否则返回FALSE
template<typename T>
T SqList<T>::delFromEnd() {
	return delByOrder(length);
}

//遍历链表
template<typename T>
void SqList<T>::traver() {
	if (isEmpty()) {
		cout << "链表为空!" << endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		cout << elem[i] << " ";
	}
	cout << endl;
	return;
}
#endif _SqList_h