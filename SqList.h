/*
*content: ˳������ʵ��
*author: urahyou
*date: 2019/10/13
*/
#ifndef _SqList_h
#define _SqList_h

#include<iostream>
using namespace std;
//����һЩ����
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0






//��������
typedef int Status;

template<typename T>
class SqList {
public:
	//���캯��������һ���յ�˳���L
	SqList();
	//��������������˳���L
	~SqList();

	//��ʼ��һ����˳���
	Status initList();
	//����һ��˳���
	Status destroy();
	//���˳���
	Status clear();
	
	//����˳���Ĵ�С
	int Length();
	
	//�ж��Ƿ�Ϊ�ձ�
	Status isEmpty();
	
	//��ȡָ��λ���ϵ�Ԫ��
	Status getElem(int order, T &e);
	
	//����Ԫ��ֵ����˳����е�ĳ��Ԫ�أ��ҵ��˾ͷ�����ţ��Ҳ����ͷ���FALSE
	int locateElem(T e);
	
	//��ָ��λ�ò���Ԫ��
	Status insertByOrder(int order, T e);
	//�ڱ�ͷ����Ԫ��
	Status insertFromHead(T e);
	//�ڱ�β����Ԫ��
	Status insertFromEnd(T e);
	
	//ɾ��ָ��λ�õ�Ԫ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�FALSE
	T delByOrder(int order);
	//ɾ����ͷԪ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�FALSE
	T delFromHead();
	//ɾ����βԪ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�FALSE
	T delFromEnd();

	//��������
	void traver();

private:
	T *elem;
	int length;
};

using namespace std;

//���캯��������һ���յ����Ա�L
template<typename T>
SqList<T>::SqList() {
	if (initList()) {
		cout << "�������ɹ���" << endl;
	}
	else {
		cout << "������ʧ��!" << endl;
	}
}

//��������������һ�����Ա�L
template<typename T>
SqList<T>::~SqList() {
	if (destroy()) {
		cout << "�������ٳɹ���" << endl;
	}
	else {
		cout << "��������ʧ�ܣ�" << endl;
	}
	
}

//��ʼ��һ���ձ�
template<typename T>
Status SqList<T>::initList() {
	elem = new T[MAXSIZE];
	if (!elem) {
		length = 0;
		return FALSE;
	}
	return TRUE;
}

//����˳���,�����Ϊ�գ��ݻٲ�����OK�����򷵻�
template<typename T>
Status SqList<T>::destroy() {
	if (!elem) {
		return ERROR;
	}
	delete[] elem;
	length = 0;
	return OK;
}

//���˳���
template<typename T>
Status SqList<T>::clear() {
	length = 0;
	return OK;
}

//����������
template<typename T>
int SqList<T>::Length() {
	return length;
}

//�ж��Ƿ�Ϊ�ձ�
template<typename T>
Status SqList<T>::isEmpty() {
	if (!length) {
		return YES;
	}
	return NO;
}

//��ȡָ��λ���ϵ�Ԫ��
template<typename T>
Status SqList<T>::getElem(int order, T &e) {
	if (order < 0) {
		cout << "�±�С��0��" << endl;
		return ERROR;
	}
	if (order > length) {
		cout << "�±�������Ա��ȣ�" << endl;
		return ERROR;
	}
	e = elem[order-1];
	return OK;
}

//����Ԫ��ֵ����˳����е�ĳ��Ԫ�أ��ҵ��˾ͷ�����ţ��Ҳ����ͷ���0
template<typename T>
int SqList<T>::locateElem(T e) {
	if (isEmpty()) {
		cout << "����Ϊ��!" << endl;
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (e == elem[i]) {
			return i + 1;
		}
	}
	return 0;
}

//��ָ��λ�ò���Ԫ��
template<typename T>
Status SqList<T>::insertByOrder(int order, T e) {
	if (order<0 || order>=MAXSIZE) {
		cout << "������Ч��Χ!" << endl;
		return ERROR;
	}
	if (length >= MAXSIZE) {
		cout << "��������!" << endl;
		return ERROR;
	}
	//����λ�������Ԫ�غ���
	for (int i = length; i >= order; i--) {
		elem[i] = elem[i - 1];
	}
	//����Ԫ��
	elem[order - 1] = e;
	length++;
	return OK;
}

//�ڱ�ͷ����Ԫ��
template<typename T>
Status SqList<T>::insertFromHead(T e) {
	return insertByOrder(1, e);
}

//�ڱ�β����Ԫ��
template<typename T>
Status SqList<T>::insertFromEnd(T e) {
	return insertByOrder(length+1, e);
}

//ɾ��ָ��λ�õ�Ԫ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�ERROR
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

//ɾ����ͷԪ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�FALSE
template<typename T>
T SqList<T>::delFromHead() {
	return delByOrder(1);
}

//ɾ����βԪ��,�ɹ��򷵻ر�ɾ����Ԫ��ֵ�����򷵻�FALSE
template<typename T>
T SqList<T>::delFromEnd() {
	return delByOrder(length);
}

//��������
template<typename T>
void SqList<T>::traver() {
	if (isEmpty()) {
		cout << "����Ϊ��!" << endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		cout << elem[i] << " ";
	}
	cout << endl;
	return;
}
#endif _SqList_h