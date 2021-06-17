#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
/**
*Author:������ 
*������������������ջs1,s2������˳��ջ��ʽ��������һ���洢��[0,...,maxsize-1],Ϊ�˾������ÿռ� 
*��������Ŀ��ܣ��ɲ���ջ������ӭ�������Ĵ洢��ʽ�������s1��s2�й���ջ�ͳ�ջ�Ĳ����㷨�� 
*
**/

typedef struct {
	int data[MAXSIZE];
	int top[2]={-1,MAXSIZE};
}SqStack; 

//  i=0  s1ջ  i=1 s2ջ  ��ջ 
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

// ��ջ 
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
