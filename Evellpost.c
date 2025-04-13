
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct Node {
    int data;
    struct Node* next;
};

// Stack Functions
void push(struct Node** head, int data);
int pop(struct Node** head);

// Eval Functions
int evaluate(char* postfix, int len);
int eval(int num1, int num2, char op);

int main(){
  char str[50];
  int len;

  printf("Enter Postfix Expression: ");
  scanf("%s", str);

  for(len=0; str[len] != '\0'; len++);

  printf("Answer: %d\n", evaluate(str,len));
}

int evaluate(char* postfix, int len){
  struct Node* stack = NULL;
  int idx = 0, a =0, b=0;
  while(idx<len){
    if(postfix[idx] >= 48 && postfix[idx] <= 57){
         push(&stack, postfix[idx]-48);
    }else {
         a = pop(&stack);
         b = pop(&stack);

         push(&stack, eval(b, a, postfix[idx]));
    }
    idx++;
  }

  return pop(&stack);
}

int eval(int num1, int num2, char op){
  int tot;
  switch(op){
    case '+' : tot = num1+num2;
      break;
    case '-' : tot = num1-num2;
      break;
    case '*' : tot = num1*num2;
      break;
    case '/' : tot = num1/num2;
      break;
    case '%' : tot = num1%num2;
      break;
    case '^' : tot = pow(num1, num2);
  }
  return tot;
}


void push(struct Node** head, int data) {
    struct Node* p;
    p = (struct Node*) malloc(sizeof(struct Node));
    p->data = data;
    p->next = *head;

    *head = p;
}

int pop(struct Node** head) {
    struct Node* p = *head;

    int data = p->data;
    *head = p->next;
    free(p);

    return data;
}
