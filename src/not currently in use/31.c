#include <stdio.h>

int binsearch(int x, int v[], int n){
	int low = 0, high = n - 1, mid;
	mid = (low + high)/2;
	while(low <= high && x != v[mid]){
		if(x > v[mid])
			low = mid + 1;
		else
			high = mid - 1;
		mid = (low + high) / 2;
	}
	if(low > high)
		return -1;
	else
		return mid;
}

int main(){
	int v[] = {2,5,7,8,12,16,18};
	printf("%d", binsearch(8, v, 7));
	return 0;
}