/*
问题描述：将两个有序顺序表合并为一个新的有序顺序表，并返回结果顺序表 
*/ 
#include <stdio.h>

typedef struct {
	int data[10];
	int length;
	int maxsize;
}SqList;



bool merge(SqList L1,SqList L2,SqList &L){
	if(L1.length+L2.length>L.maxsize){
		return false;
	}

	int i=0,j=0,k=0;
	while(i<L1.length&&j<L2.length){ 

		if(L1.data[i]<L2.data[j]){
			L.data[k]=L1.data[i];
			i++;
		}else{
			L.data[k]=L2.data[j];
			j++;
		}
		k++;
	}
	
	if(i==L1.length){
		for(int z=j;z<L2.length;z++)
			L.data[k++]=L2.data[z];
		}
		
	if(j==L2.length){
		for(int z=i;z<L1.length;z++)
			L.data[k++]=L1.data[z];
		}
	
	L.length=k;
	return true;
}

 void printList(SqList L){
 	for(int i=0;i<L.length;i++)
 		printf("%d\t",L.data[i]);
 }


int main(){
	 //test 
 	SqList L1;
 	L1.data[0]=7;
	L1.data[1]=8;
	L1.data[2]=9;
	L1.data[3]=10;
	L1.length=4;
	SqList L2;
 	L2.data[0]=1;
	L2.data[1]=2;
	L2.data[2]=3;
	L2.data[3]=4;
	L2.length=4;
	
	SqList L;
	L.maxsize=25;

	merge(L1,L2,L);
	printList(L);
	
	return 0;
}

