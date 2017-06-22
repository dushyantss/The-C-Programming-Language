#include <stdio.h>

/* shellsort: sort v[0]....v[n-1] into increasing order */
void shellsort(int v[], int n){
	int gap, i, j, temp;
	
	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; ++i)
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

int main(){
	int arr[] = {32,12,4,65,3,1,76,53,13};
	for(int i = 0; i < 9; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	shellsort(arr, 9);
	for(int i = 0; i < 9; ++i)
		printf("%d ", arr[i]);
	return 0;
}