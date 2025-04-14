
#include  "stdio.h"
#include "stdlib.h"
#include "limits.h"
void printOptimal(int** s, int i, int j);

int main(){
  int **table, **mats, **s, *p;
  int matCount, i, j, k, min, l, pCount=0;

  printf("Number of Matrices: ");
  scanf("%d", &matCount);

  table = (int**) malloc(sizeof(int*)*matCount);
  s = (int**) malloc(sizeof(int*)*matCount);
  mats = (int**) malloc(sizeof(int*)*matCount);
  p = (int*) calloc(matCount*2, sizeof(int));

  for(i =0; i<matCount; i++){
    mats[i] = (int*) malloc(sizeof(int)*2);
    printf("Enter Row Count of Mat %d: ", i+1);
    scanf("%d", &mats[i][0]);

    for(j=0; j< (matCount*2); j++){
      if(mats[i][0] == p[j]){
        break;
      }else if(p[j] == 0){
        p[j] = mats[i][0];
        pCount++;
        break;
      }
    }
    printf("Enter Col Count of Mat %d: ", i+1);
    scanf("%d", &mats[i][1]);


    for(j=0; j< (matCount*2); j++){
      if(mats[i][1] == p[j]){
        break;
      }else if(p[j] == 0){
        p[j] = mats[i][1];
        pCount++;
        break;
      }
    }

    table[i] = (int*) malloc(sizeof(int)*matCount);
    table[i][i] = 0;

    s[i] = (int*) calloc(matCount, sizeof(int));
  }


  for(l = 1; l<matCount;l++){

    for(i=0; i<matCount-l;i++){
      j = i+l;

      table[i][j] = INT_MAX;
      for(k=i;k<j;k++){

        min = table[i][k] + table[k+1][j] + p[i]*p[k+1]*p[j+1];
        if(min < table[i][j]){
          table[i][j] = min;
          s[i][j] = k+1;
        }
      }
    }
  }

  printf("\n");
  printOptimal(s, 0, matCount-1);
  printf("\n");
  return 0;
}


void printOptimal(int** s, int i, int j){
  if(i==j){
    printf("M%d", i);
  }else {
    printf("(");
    printOptimal(s, i, s[i][j]-1);
    printf("*");
    printOptimal(s, s[i][j], j);
    printf(")");
  }
}
