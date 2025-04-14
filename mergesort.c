#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int beg, int mid, int end);
void mergeSort(int arr[], int beg, int end);

int main(void)
int main()
{
int arr[] = {50, 31, 21, 28, 72, 41, 73, 93, 68, 43, 45, 78, 5, 17, 97, 71, 69, 61, 88, 75, 99, 44, 55, 9};
int idx =0, len = 24;

printf("Before Sorting: ");
for (idx=0; idx < len; idx++)
{
printf("%d, ", arr[idx]);
}

mergeSort(arr, 0, len-1);

printf("\nAfter Sorting: ");
for (idx=0; idx < len; idx++)
{
printf("%d, ", arr[idx]);
}
return 0;
}

void mergeSort(int arr[], int beg, int end)
{
if (beg >= end) return;
int mid = (beg + end)/2;
mergeSort(arr, beg, mid);
mergeSort(arr, mid+1, end);
merge(arr, beg, mid, end);
}
void merge(int arr[], int beg, int mid, int end)
{
int i = beg, j = mid+1, idx = 0, k=0;
int *temp = (int*) malloc(sizeof(int)*(end-beg));


while (i <= mid && j <= end)
{
if (arr[i] < arr[j])
{
temp[idx] = arr[i];
i++;
}else
{
temp[idx] = arr[j];
j++;
}
idx++;
}

while (i<=mid)
{
temp[idx] = arr[i];
idx++;
i++;
}

while (j<=end)
{
temp[idx] = arr[j];
idx++;
j++;
}

k=0;
while (k < idx)
{

arr[k+beg]  = temp[k];
k++;
}
free(temp);
