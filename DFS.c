
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define NODE 6
int stack[MAX], top =-1;

void push(int node);
int pop();

int main(){
	int graph[NODE][NODE];
    int visited[NODE] = {0,0,0,0,0,0}, vCount =0, node, adjNode;

    graph[0][0] = 0;
	graph[0][1] = 1;
	graph[0][2] = 1;
	graph[0][3] = 0;
	graph[0][4] = 0;
	graph[0][5] = 0;

	graph[1][0] = 0;
	graph[1][1] = 0;
	graph[1][2] = 0;
	graph[1][3] = 1;
	graph[1][4] = 1;
	graph[1][5] = 0;

	graph[2][0] = 0;
	graph[2][1] = 0;
	graph[2][2] = 0;
	graph[2][3] = 0;
	graph[2][4] = 0;
	graph[2][5] = 1;

	graph[3][0] = 0;
	graph[3][1] = 0;
	graph[3][2] = 0;
	graph[3][3] = 0;
	graph[3][4] = 0;
	graph[3][5] = 0;

	graph[4][0] = 0;
	graph[4][1] = 0;
	graph[4][2] = 0;
	graph[4][3] = 0;
	graph[4][4] = 0;
	graph[4][5] = 0;


	graph[5][0] = 0;
	graph[5][1] = 0;
	graph[5][2] = 0;
	graph[5][3] = 0;
	graph[5][4] = 0;
	graph[5][5] = 0;

    push(0);
    visited[0] = 1;
    while(vCount < NODE){
      node = pop();
      if(node == -1){
        break;
      }

      visited[node] = 2;
      vCount++;
      printf("->%d", node);


      for(adjNode=NODE-1; adjNode>0; adjNode--){
        if(visited[adjNode] == 0 && graph[node][adjNode] == 1){
          push(adjNode);
          visited[adjNode] = 1;
        }
      }
    }
    printf("\n");
	return 0;
}

void push(int node){
	if(top == MAX-1){
		printf("Overflow\n");
		return;
	}


	top++;
	stack[top] = node;
}

int pop(){
	int node;
	if(top == -1){
		printf("Underflow\n");
		return -1;
	}

	node = stack[top];
	top--;
    return node;
}
