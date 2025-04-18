
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node * prev, *next;
    int data;
} node;

void insertAtBeginning(node **head);
void append(node **);
void insertAfter(node**);
void deleteAny(node **);
void countNode(node*);
void display(node*);
void search(node*);

int main(){
    int ch;
    node * start = NULL;
    while(1){
    printf("1) append \n 2) insert after \n 3) Insert Beginning \n4) Delete any \n 5) count node \n 6) search \n 7) display \n 8) Exit");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            append(&start);
            break;

        case 2: 
            insertAfter(&start);
            break;

	case 3: 
	    insertAtBeginning(&start);
	    break;
        case 4:
            deleteAny(&start);
            break;

        case 5:
            countNode(start);
            break;

        case 6: 
            search(start);
            break;

        case 7:
            display(start);
            break;
	
	case 8: exit(1);

	default: printf("Invalid Option");
    }
    }
    return 0;
}

void append(node ** head){
    node *p, * temp;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    printf("Enter data");
    scanf("%d",&temp->data);
    if(*head == NULL){
        *head = temp;
        return;
    }
    p = *head;
    while(p->next != NULL){
        p=p->next;
    }
    temp->prev = p;
    p->next = temp;

}

void insertAfter(node **head){
    int pos;
    node * p = *head, *temp;
    printf("Enter after which value you want to insert : ");
    scanf("%d", &pos);
    while(p != NULL && p->data != pos)
        p = p->next;
    if(p == NULL)
        printf("value not found \n ");
    else {
        int data;
        printf("Enter value to insert : ");
        scanf("%d", &data);
        temp = (node *) malloc (sizeof(node));
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
    }
}

void deleteAny(node **head){
    node *p = *head;
    int val;
    printf("Enter the value that you want to delete : ");
    scanf("%d", &val);
    while(p != NULL && p->data != val)
        p = p->next;
    if(p == NULL)
        printf("value not found \n ");
    else {
        if(p == *head)
            *head = p->next;
        else{
            (p->prev)->next = (p->next);
        }
        printf("\n now freeing \n");
        free(p);
    }
}


void countNode(node * head){
    node *ptr = head;
    int count = 0;
    if(ptr == NULL){
        printf("\n Count = 0 \n");
        return;
    }

    while(ptr != NULL){
        ptr = ptr->next;
        count ++;
    }

    printf("\n Count = %d \n",count);
}

void search(node *head){
    node *ptr = head;
    int data, count = 0;
    if(ptr == NULL)
    {
        printf("\n List is empty \n");
    }
    printf("Enter value to search : ");
    scanf("%d", &data);
    while(ptr != NULL){ 
        count ++;
        if(ptr->data == data){
            break;
        }
        ptr = ptr->next;
    }
    if(ptr != NULL)
        printf("\n Items found at  : %d \n", count);
    else
        printf("\n not found \n");
}

void display(node * head){
    node * ptr = head;
    if(head == NULL){
        printf("\n List is empty -------- \n");
        return;
    }
    printf(" \n");
    while(ptr != NULL){
        printf("-- %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

void insertAtBeginning(node **head)
{
	node *p;

	p = (node*) malloc(sizeof(node));

	printf("Enter Data:");
	scanf("%d", &p->data);

	p->prev = NULL;
	p->next = *head;
	*head = p;
}
