#include <stdio.h>
#include <stdlib.h>

/**
*���⣺����дһ���㷨�ж������Ĳ��������Ƿ�Ϸ� 
*Author:lRQ-PRO
*/

// IOIIOIOO
bool isFormat(char c[]){
	int i=0;
	int array=0;
	while(c[i]!='\0'){
		switch(c[i]){
			case 'I':array++;break;
			case 'O':array--;
			if(array<0){
				printf("�Ƿ�����"); 
				exit(0);
			}
			break;
		}
		i++;
	}
	if(array==0){
		printf("�Ϸ�����");
	}else{
		printf("�Ƿ�����");
	}
	return true;

}

int main(){
	char c[]={'I','O','0','I','O','I','I','O'};
	isFormat(c);
		return 0;
}
