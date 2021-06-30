#include <stdio.h>
#include <stdlib.h>
void swapSort(int arr[], int m, int n);

void main() {
	int arr[6];
	for (int i = 0; i < 10; i++)
		arr[i] = i + 1;
	swapSort(arr, 6, 4);
	getchar();
}

//123456
//623456
//612345

//512345
//511234
//561234

void swapSort(int arr[],int m,int n) {
	int j = m + n - 1;
	int i = 0;
	int count = m < n ? m:n;
	while (count > 0) {
		int temp = arr[i];
		arr[i] = arr[j];
		for (int k = m + n - 2; k >= 1; k--)
			arr[k + 1] = arr[k];
		arr[1] = temp;
		count--;
	}

	for (int t = 0; t < 10; t++)
		printf("arr[%d]=%d\n",t, arr[t]);

}

