#include "stdio.h"
 void QuickSort(int* arr, int low, int high);
 int Partition(int* arr, int low, int high);
 
 void main()
 {
     int arr[] = {50, 31, 21, 28, 72, 41, 73, 93, 68, 43, 45, 78, 5, 17, 97, 71, 69, 61, 88, 75, 99, 44, 55, 9};
     int idx =0, len = 24;
 
 
     printf("Before Sorting: ");
     for (idx=0; idx < len; idx++)
     {
         printf("%d, ", arr[idx]);
     }
 
     QuickSort(arr, 0, len-1);
 
     printf("\nAfter Sorting: ");
     for (idx=0; idx < len; idx++)
     {
         printf("%d, ", arr[idx]);
     }
 
 }
 
 int  Partition(int* arr, int low, int high)
 {
     int pivot = low;
     int l = low+1;
     int h = high;
     int tmp;
 
     int dir = 0;
     while (l < h)
     {
         if (dir==0){
             while (pivot < h && arr[pivot] < arr[h])
             {
                 h--;
             }
             dir = 1;
         }else
         {
             while (pivot > l && arr[pivot] > arr[l])
             {
                 l++;
             }
 
             dir = 0;
         }
 
         if (dir == 1 && pivot < h)
         {
             tmp = arr[pivot];
             arr[pivot] = arr[h];
             arr[h] = tmp;
 
             pivot = h;
         }
         else if (dir == 0  && pivot > l)
         {
             tmp = arr[pivot];
             arr[pivot] = arr[l];
             arr[l] = tmp;
 
             pivot = l;
         }
     }
 
     return pivot;
 }
 
 
 void QuickSort(int* arr, int low, int high)
 {
     int mid;
     if(low >= high) return;
 
 
     mid = Partition(arr, low, high);
     QuickSort(arr, low, mid-1);
     QuickSort(arr, mid+1,  high);
 }
