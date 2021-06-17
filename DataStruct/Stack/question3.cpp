#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
/**
*Author:刘瑞琪 
*问题描述：设有两个栈s1,s2都采用顺序栈方式，并共享一个存储区[0,...,maxsize-1],为了尽量利用空间 
*减少溢出的可能，可采用栈顶相向，迎面增长的存储方式。试设计s1、s2有关入栈和出栈的操作算法。 
*
**/

typedef struct {
	int data[MAXSIZE];
	int top[2]={-1,MAXSIZE};
}SqStack; 

//  i=0  s1栈  i=1 s2栈  入栈 
bool push(SqStack &S,int i,int e){
	if(i<0||i>1)
		return false;
	if(S.top[1]-S.top[0]==1)
		return false;
	switch(i){
		case 0:
		S.data[++S.top[0]]=e;
		break;
		case 1:
		S.data[--S.top[1]]=e;
		break;
	}
}

void print_Stack(SqStack s){
	printf("Stack element is\t");
	for(int i=0;i<MAXSIZE;i++)
		printf("%d ",s.data[i]);
}

// 出栈 
bool pop(SqStack &S,int i,int &e){
	if(i<0||i>1)
		return false;
	switch(i){
		case 0:
		if(S.top[0]==-1)
			return false;
		e=S.data[S.top[0]--];
		break;
		case 1:
		if(S.top[1]==MAXSIZE)
			return false;
		e=S.data[S.top[1]++];
		break;
	}
	return true;
}


int main(){
	SqStack S;
	push(S,0,10);
	push(S,0,11);
	print_Stack(S);
	int e=-1;
	pop(S,0,e);
	printf("\ne=%d",e);
	
	
	
	
	return 0;
} 
