
#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node* next;
};


void push(struct Node**);
void pop(struct Node**);
void display(struct Node*);

int main(){
	int in;
	struct Node *top = NULL;

	while(1){
		printf("\n1)Push \n2)Pop \n3)Display \n4)Exit");
		printf("\nEnter Choice:");
		scanf("%d", &in);

		switch(in){
			case 1: push(&top);
				break;
			case 2: pop(&top);
				break;
			case 3: display(top);
				break;
			case 4: exit(1);

			default: printf("Invalid Choice");
		}
	}
	return 0;
}

void push(struct Node** top) {
	struct Node* p;
	p = (struct Node*) malloc(sizeof(struct Node));

	printf("Enter Data:");
	scanf("%d", &p->data);


	p->next = *top;
	*top = p;
}

void pop(struct Node** top) {
	struct Node* p = *top;

	if(*top == NULL){
		printf("Underflow");
		return;
	}

	printf("Popped: %d", p->data);

	*top = p->next;
	free(p);
}

void display(struct Node* top){
	struct Node* p = top;

	if(top == NULL){
		printf("Stack is empty");
		return;
	}

	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}
