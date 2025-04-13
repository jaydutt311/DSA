#include<stdio.h>

void main(){
    int arr[10], max = 10, i, item;

    for(i=0;i<10;i++){
        printf("Enter Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Item to Search: ");
    scanf("%d", &item);

    for(i=0; i<max; i++){
      if(item == arr[i]){
        printf("Item found at %d\n", i+1);
        return;
      }
    }

    printf("Item Not Found");

}
