#include "LineList.h"
#include <stdio.h>
int main() {
	CLineList cLineList;
	//cLineList.addElem(3);
	//cLineList.addElem(2);
	//cLineList.addElem(1);
	//cLineList.addElem(4);
	//cLineList.addElem(5);
	//cLineList.addElem(6);
	//cLineList.addElem(7);
	//int iR=0;
	//int iS = 0;
	//for (int i = 0; i < 20; i++) {
	//	iS = cLineList.getElem(i, &iR);
	//	if (iS == STATUS_OK) {
	//		printf("STATUS_OK Index:%d ELem:%d \n",i, iR);
	//	}
	//	else {
	//		printf("STATUS_ERROR Index:%d ELem:%d \n", i, iR);
	//	}
	//}
	
	//随机存取特性实现
	//数组地址计算方法
	// a=数组地址 c=元素变量大小
	//Loc(a+i)=Loc(a)+i*c;
	int iSize = sizeof(Elemtype);
	printf("数组地址：%d 数组第一个元素地址：%d \n", (int)(&cLineList.$data), (int)(&cLineList.$data[0]));
	printf("数组第五个元素地址：%d 数组第五个元素地址(用数组地址计算)：%d \n", (int)(&cLineList.$data[5]), (int)(&cLineList.$data[0]) + iSize * 5);

	return 1;
}
status CLineList::clear() {
	this->iLength = 0;
	return STATUS_OK;
}
int CLineList::getLength() {
	return this->iLength;
}
status CLineList::getElem(int iIndex,Elemtype* lpEle) {
	if (iIndex < 0 || iIndex>=MAXSIZE) {
		return STATUS_ERROR;
	}
	*lpEle = this->$data[iIndex];
	return STATUS_OK;
}
status CLineList::insertElem(int iIndex, Elemtype iEle) {
	if (this->iLength + 1 > MAXSIZE
		||
		iIndex > this->iLength
		) {
		return STATUS_ERROR;
	}
	if (iIndex + 1 < this->iLength) {//过滤最后一位
		for (int i = iIndex; i < this->iLength; i++) {
			this->$data[i + 1] = this->$data[i];
		}
	}
	this->$data[iIndex] = iEle;
	this->iLength++;
	return STATUS_OK;
}
status CLineList::addElem(Elemtype iEle) {
	if (this->iLength + 1 > MAXSIZE) {
		return STATUS_ERROR;
	}
	this->$data[this->iLength++] = iEle;
	return STATUS_OK;
}
status CLineList::deleteElem(int iIndex, Elemtype* lpEle) {
	if (this->iLength <= 0 || iIndex >= this->iLength) {
		return STATUS_ERROR;
	}
	for (int i = this->iLength - 1;i > iIndex; i--)
		this->$data[i-1] = this->$data[i];
	for (int i = iIndex; i <  this->iLength ; i++)
		this->$data[i] = this->$data[i+1];
	this->iLength--;
}