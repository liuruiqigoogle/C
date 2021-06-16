#include <stdio.h>
#include <stdlib.h>

/**
*问题：描述写一个算法判定所给的操作序列是否合法 
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
				printf("非法序列"); 
				exit(0);
			}
			break;
		}
		i++;
	}
	if(array==0){
		printf("合法序列");
	}else{
		printf("非法序列");
	}
	return true;

}

int main(){
	char c[]={'I','O','0','I','O','I','I','O'};
	isFormat(c);
		return 0;
}
