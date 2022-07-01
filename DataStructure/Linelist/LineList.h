#pragma once
#define MAXSIZE 5
#define STATUS_OK 1
#define STATUS_ERROR 0;
typedef int Elemtype;
typedef int status;
//线性表
//特点：
//①仅有一个开始结点和结束结点
//②最多只有一个前驱结点和一个后继结点。
//线性表&栈&队列&串
//顺序存储结构-实现
class CLineList {
public:
	Elemtype $data[MAXSIZE];
	int iLength=0;
public:
	status insertElem(int iIndex,Elemtype iEle);//插入元素
	status addElem(Elemtype iEle);//添加元素
	status deleteElem(int iIndex, Elemtype*lpEle);//删除元素
	status getElem(int iIndex, Elemtype* lpEle);//获得元素
	status clear();//清空元素
	int getLength();//得到元素数目
};