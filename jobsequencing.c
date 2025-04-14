
#include "stdio.h"
#include "stdlib.h"

int main()
{
  int *jobDL, *jobProfit, *jobNo, *jobSeq;
  int jobCount, i, j, key[3], maxTime=0, totProfit=0;

  printf("Enter Job Count: ");
  scanf("%d", &jobCount);

  jobDL = (int*) malloc(sizeof(int)*jobCount);
  jobProfit = (int*) malloc(sizeof(int)*jobCount);
  jobNo = (int*) malloc(sizeof(int)*jobCount);

  printf("Enter Job Info: ");
  for(i=0; i<jobCount;i++){
    printf("\nDeadLine for Job %d: ", i+1);
    scanf("%d", &jobDL[i]);
    printf("Profit for Job %d: ", i+1);
    scanf("%d", &jobProfit[i]);

    jobNo[i] = i+1;
    if(maxTime < jobDL[i]){
      maxTime = jobDL[i];
    }
  }

  // Sorting Jobs
  for(i = 1; i<jobCount;i++){
    key[0] = jobNo[i];
    key[1] = jobDL[i];
    key[2] = jobProfit[i];
    j = i-1;

    while(j >= 0 && jobProfit[j] < key[2]){
      jobNo[j+1] = jobNo[j];
      jobDL[j+1] = jobDL[j];
      jobProfit[j+1] = jobProfit[j];
      j--;
    }
    jobNo[j+1] = key[0];
    jobDL[j+1] = key[1];
    jobProfit[j+1] = key[2];
  }

  jobSeq = (int*) calloc(maxTime,sizeof(int));

  for(i=0; i<jobCount;i++){
    if(jobSeq[jobDL[i]-1] == 0){
      jobSeq[jobDL[i]-1] = jobNo[i];
      totProfit += jobProfit[i];
    }else {
      for(j=jobDL[i]-1; j >=0; j--){
        if(jobSeq[j] == 0){
          jobSeq[j]=jobNo[i];
          totProfit += jobProfit[i];
          break;
        }
      }
    }
  }


  printf("Job Order: ");
  for(i=0; i<maxTime;i++){
    printf("J%d, ", jobSeq[i]);
  }
  printf("\nTotal Profit: %d\n", totProfit);

}
