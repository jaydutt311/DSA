
#include"stdio.h"
#define MAX 4
void matrixMulti(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX],
                 int aSRow, int aSCol, int bSRow,
                 int bSCol, int cSRow, int cSCol,
                 int aLen, int bLen, int cLen) ;

int main(){
  int i, j;
  int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int b[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int c[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  matrixMulti(a, b, c, 0,0, 0,0, 0,0, 4,4,4);

  for(i =0; i < 4;i++){
    for(j =0; j < 4;j++){
      printf("%d\t", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}


void matrixMulti(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX],
                 int aSRow, int aSCol, int bSRow, 
                 int bSCol, int cSRow, int cSCol, 
                 int aLen, int bLen, int cLen) {
  	int p[7];
	if(aLen == 2 && bLen == 2){
          p[0] = (a[aSRow][aSCol] + a[aSRow+1][aSCol+1]) * (b[bSRow][bSCol] + b[bSRow+1][bSCol+1]);
          p[1] = (a[aSRow+1][aSCol] + a[aSRow+1][aSCol+1]) * b[bSRow][bSCol];
          p[2] = a[aSRow][aSCol] * (b[bSRow][bSCol+1] - b[bSRow+1][bSCol+1]);
          p[3] = a[aSRow+1][aSCol+1] * (b[bSRow+1][bSCol] - b[bSRow][bSCol]);
          p[4] = (a[aSRow][aSCol] + a[aSRow][aSCol+1]) * b[bSRow+1][bSCol+1];
          p[5] = (a[aSRow+1][aSCol] - a[aSRow][aSCol]) * (b[bSRow][bSCol] + b[bSRow][bSCol+1]);
          p[6] = (a[aSRow][aSCol+1] - a[aSRow+1][aSCol+1]) * (b[bSRow+1][bSCol] + b[bSRow+1][bSCol+1]);

          c[cSRow][cSCol] += p[0] + p[3] - p[4]+p[6];
          c[cSRow][cSCol+1] += p[2] + p[4];
          c[cSRow+1][cSCol] += p[1] + p[3];
          c[cSRow+1][cSCol+1] += p[0] + p[2] - p[1]+p[5];
	}else {
          matrixMulti(a, b, c, aSRow, aSCol, bSRow, bSCol, cSRow, cSCol, aLen/2, bLen/2, cLen/2); // 11, 11
          matrixMulti(a, b, c, aSRow, aLen/2, bLen/2, bSCol, cSRow, cSCol, aLen/2, bLen/2, cLen/2); // 12, 21


          matrixMulti(a, b, c, aSRow, aSCol, bSRow, bLen/2, cSRow, cLen/2, aLen/2, bLen/2, cLen/2); // 11, 12
          matrixMulti(a, b, c, aSRow, aLen/2, bLen/2, bLen/2, cSRow, cLen/2, aLen/2, bLen/2, cLen/2); // 12, 22

          matrixMulti(a, b, c, aLen/2, aSCol, bSRow, bSCol, cLen/2, cSCol, aLen/2, bLen/2, cLen/2); // 21, 11
          matrixMulti(a, b, c, aLen/2, aLen/2, bLen/2, bSCol, cLen/2, cSCol, aLen/2, bLen/2, cLen/2); // 22, 21

          matrixMulti(a, b, c, aLen/2, aSCol, bSRow, bLen/2, cLen/2, cLen/2, aLen/2, bLen/2, cLen/2); // 21, 12
          matrixMulti(a, b, c, aLen/2, aLen/2, bLen/2, bLen/2, cLen/2, cLen/2, aLen/2, bLen/2, cLen/2); // 22, 22

	}
}
