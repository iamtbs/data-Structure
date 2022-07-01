#pragma once
#define MAXSIZE 5
#define STATUS_OK 1
#define STATUS_ERROR 0;
typedef int Elemtype;
typedef int status;
//线性表
//顺序存储结构
class CLineList {
private:
	Elemtype $data[MAXSIZE];
	int iLength=0;
public:
	status getElem(int iIndex,Elemtype*lpEle);
	status insertElem(int iIndex,Elemtype iEle);
	status addElem(Elemtype iEle);
	status deleteElem(int iIndex, Elemtype*lpEle);
	status clear();
	int getLength();
};