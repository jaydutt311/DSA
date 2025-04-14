
#include<stdio.h>
#include<stdlib.h>

void main(){
	int *arr, len, i, j, t;

	printf("Enter Number Count:");
	scanf("%d", &len);

	arr = (int*) malloc(sizeof(int)*len);

	for(i=0; i<len;i++){
		printf("Enter Number %d:", i+1);
		scanf("%d", &arr[i]);
	}

	for(i=0; i<len; i++){
		for(j=i+1;j<len; j++){
			if(arr[i] > arr[j]){
				t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
			}
		}
	}


	printf("Sorted Array: ");
	for(i=0;i<len;i++){
		printf("%d, ", arr[i]);
	}

	free(arr);
}
