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
 
 	for(i=0; i<len-1; i++){
 		for(j=0;j<len-i-1; j++){
 			if(arr[j] > arr[j+1]){
 				t = arr[j];
 				arr[j] = arr[j+1];
 				arr[j+1] = t;
 			}
 		}
 	}
 
 
 	printf("Sorted Array: ");
 	for(i=0;i<len;i++){
 		printf("%d, ", arr[i]);
 	}
 
 	free(arr);
 }
