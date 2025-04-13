
#include<stdio.h>

void main(){
	int arr[10], l = 0, u = 10, mid, i, item;

	for(i=0;i<10;i++){
		printf("Enter Number %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("Enter Item to Search: ");
	scanf("%d", &item);



	while(l < u){
		mid = (u+l)/2;

		if(arr[mid] ==  item){
			printf("Found At %d", mid);
			return;
		}else if(arr[mid] > item){
			u = mid;
		}else {
			l = mid+1;
		}
	}

	printf("Item Not Found");

}
