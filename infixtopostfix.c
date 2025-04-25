
#include "stdio.h"
#include "stdlib.h"

struct Node {
    char data;
    struct Node* next;
};

// Stack Functions
void push(struct Node** head, char data);
char pop(struct Node** head);
char peek(struct Node* head);

// Polish Notation
void getPostOrder(char *, char*);
int getPrecedence(char);
int isOperand(char ch);

void main() {

    char str[50], postfix[50];

    printf("Enter Expression: ");
    scanf("%s", str);

    getPostOrder(str, postfix);

    printf("Postfix: %s\n", postfix);
}


void getPostOrder(char *str, char *post){
    int idx = 0, pidx =0;
    struct Node* start = NULL;

    while(str[idx] != '\0'){
        //printf("%c\n", str[idx]);
        if(isOperand(str[idx])){
            post[pidx++] = str[idx];
        }
        else if(str[idx] == ')'){

            while(peek(start) != '(' && start != NULL){
                post[pidx++] = pop(&start);
            }

            if(start == NULL){
                printf("Invalid Expression");
                exit(1);
            }else {
                pop(&start);
            }
        }else {
            
            if(start != NULL && str[idx] != '('){
                while(getPrecedence(str[idx]) <= getPrecedence(peek(start)) && start != NULL){
                    post[pidx++] = pop(&start);
                }
            }

            push(&start, str[idx]);
        }

        idx++;
    }

    while(start != NULL){
        post[pidx++] = pop(&start);
    }

    post[pidx] == '\0';
}


int getPrecedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
    }

    return -1;
}



int isOperand(char ch){
    return (ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90);
}


void push(struct Node** head, char data) {
    struct Node* p;
    p = (struct Node*) malloc(sizeof(struct Node));
    p->data = data;
    p->next = *head;

    *head = p;
}

char pop(struct Node** head) {
    struct Node* p = *head;

    char data = p->data;
    *head = p->next;
    free(p);

    return data;
}

char peek(struct Node* head){
    return head->data;
}
