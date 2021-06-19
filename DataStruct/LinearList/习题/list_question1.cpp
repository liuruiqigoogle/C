#include <stdio.h>
#include <stdlib.h>

/**
*问题描述：从顺序表删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由
*最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。 
*
**/ 

//伪代码 
bool DeleteMinElem(SqList &L,int &e){
	if(L.length==0)
		return false;
	//假设第一个元素是最小值
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
