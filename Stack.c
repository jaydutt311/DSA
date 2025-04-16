#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX], top =-1;
void push();
void pop();
void display();

int main(){
  int in;
  while(1){
    printf("\n1)Push \n2)Pop \n3)Display \n4)Exit");
    printf("\nEnter Choice: ");
    scanf("%d", &in);

    switch(in){
      case 1: push();
      break;
      case 2: pop();
        break;
      case 3: display();
        break;
      case 4: exit(1);
      default: printf("Invalid Choice");
    }
  }

  return 0;
}

void push(){
  int item;
  if(top == MAX-1){
    printf("Overflow\n");
    return;
  }

  printf("Enter Data: ");
  scanf("%d", &item);


  top++;
  stack[top] = item;
  printf("Pushed %d\n", item);
}

void pop(){
  int item;
  if(top == -1){
    printf("Underflow\n");
    return;
  }

  item = stack[top];
  top--;
  printf("Popped %d", item);
}

void display()
{
  int i=top;
  if(top == -1){
    printf("Underflow\n");
    return;
  }
  printf("\n");
  while(i>=0){
    printf("%d \n", stack[i]);
    i--;
  }
  printf("\n");

}
