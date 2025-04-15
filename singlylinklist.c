#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void createList(struct Node** head);
void delnode(struct Node** head);
void insertatmiddle(struct Node** head);
void displayList(struct Node* head);
void insertatbeg(struct Node** head);

int main(){
	int ch;
	struct Node* start = NULL;
	
	while(1){
		printf("\n1) Append Node \n2) Display \n3) Beginning \n4) At middle \n5) delete Node \n6)Exit");
		printf("\nEnter Choice:");
		scanf("%d", &ch);
		
		switch(ch){
			case 1 : createList(&start);
				break;
			case 2 : displayList(start);
				break;
			case 3 : insertatbeg(&start);
					 break;
			case 4 : insertatmiddle(&start);
					 break;
			case 5 : delnode(&start);
					 break;
			case 6: exit(1);
					 break;
			default : printf("Invalid Choice");
					 break;
		}
	}
    return 0;
}

void createList(struct Node** head){
	struct Node *p, *q;
	if(*head == NULL){
		p = (struct Node*) malloc(sizeof(struct Node));
		
		printf("Enter A Value:");
		scanf("%d", &p->data);
		p->next = NULL;
		
		*head = p;
		
	}else {
		q = *head;
		while(q->next != NULL){
			q = q->next;
		}
		
		p = (struct Node*) malloc(sizeof(struct Node));
		printf("Enter A Value:");
		scanf("%d", &p->data);
		p->next = NULL;
		
		q->next = p;
	}
}
void displayList(struct Node* head){
	struct Node* ptr = head;
	if(head==NULL){
		printf("\t->List is empty");
		return;
	}
	while(ptr!= NULL){
		printf("\t-> %d\n", ptr->data);
		ptr = ptr->next;
	}
}

void insertatbeg(struct Node **head)
{
	struct Node *p;
	int d;
	printf("\n enter data:");
	scanf("%d",&d);
	p=(struct Node*)malloc(sizeof(struct Node));
	p->data=d;
	p->next=*head;
	*head=p;
}
void insertatmiddle(struct Node** head){
	struct Node *p,*q;
	int d,find;
	p=(struct Node*)malloc(sizeof(struct Node));
	if(*head==NULL){
		printf("List is empty");
		return;
	}
	printf("enter the value were you want to insert after: ");
	scanf("%d",&find);
	q=*head;
	while(q->data!=find){
		if(q->next==NULL){
			printf("data does not exist");
			return;
		}
		q=q->next;
	}
	printf("enter the Element:");
	scanf("%d",&d);
	p->data=d;
	p->next=q->next;
	q->next=p;
}
void delnode(struct Node **head){
	struct Node *p,*q;
	int d;
	if(*head==NULL){
		
		printf("\n\t\t->List is empty\n");
		return;
	}
	printf("enter the Element that you want to delete:");
	scanf("%d",&d);
	p=*head;
	q=p;
	if(p->data==d){
			*head=p->next;
			free(p);
			return;	
	}
//	p=p->next;
	while(p->data!=d){
		q=p;
		p=p->next;
			if(p==NULL){
			printf("\t->value does not exist");
			return;
		}
	}
	q->next=p->next;
	free(p);
