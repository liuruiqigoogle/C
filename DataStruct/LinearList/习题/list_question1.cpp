#include <stdio.h>
#include <stdlib.h>

/**
*������������˳���ɾ��������Сֵ��Ԫ��(����Ψһ)���ɺ������ر�ɾԪ�ص�ֵ���ճ���λ����
*���һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С� 
*
**/ 

//α���� 
bool DeleteMinElem(SqList &L,int &e){
	if(L.length==0)
		return false;
	//�����һ��Ԫ������Сֵ
	int position=0;
	e=L.data[0];
	for(int i=1;i<L.length;i++){
		if(L.data[i]<e){
			e=L.data[i];
			position=i;
		}
	}
	L.data[position]=L.data[L.length-1];
	L.length--;
	return true;
	

} 




int main(){
	
	return 0;
} 
