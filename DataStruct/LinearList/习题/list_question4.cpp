#include <stdio.h>

typedef struct {
	int data[10];
	int length;
}SqList;


//问题描述：有序顺序表删除其中给定值s与t之间的所有元素 

 void printList(SqList L){
 	for(int i=0;i<L.length;i++)
 		printf("%d\t",L.data[i]);
 }

bool DeleteRangeElem(SqList &L,int s,int t){
	if(L.length==0)
		return false;
	if(t<s||t==s)
		return false;
	int i=0;
	int j=L.length-1;
	
	while(L.data[i]<s||L.data[j]>t){
			if(L.data[i]<s){
				i++;
			}
			if(L.data[j]>t){
				j--;
			}
	}
	printf("s=%d\n",i);
	printf("t=%d\n",j);

	for(int k=j+1;k<L.length;k++){
		L.data[i]=L.data[k];
		i++;
	}	
	L.length=i;
}

int main(){
	 //test 
 	SqList L;
 	L.data[0]=1;
	L.data[1]=2;//
	L.data[2]=3;//
	L.data[3]=4;// 
	L.data[4]=5;//	
	L.data[5]=6;//
	L.data[6]=7;//
	L.data[7]=8;//
	L.data[8]=9;
	L.data[9]=10;
	//1 2 9 10	
 	L.length=10;
 //	printList(L);
 	DeleteRangeElem(L,2,8);
 	printList(L);
	return 0;
}
