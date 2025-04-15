
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void createList(struct Node** head);
void insertAtBeg(struct Node** head);
void insertAtAny(struct Node* head);
void displayData(struct Node* head);
void deleteFromBeg(struct Node** head);
void deleteSpecific(struct Node** head);
void countNodes(struct Node* head);
void searchNode(struct Node* head);

int main()
{
	int in;
	struct Node* start = NULL;

	while(1){
		printf("\n\n\n1) To Append \n2) To Insert At Beg \n3) To Insert At Any \n4) Display");
		printf("\n5) Delete From Beg \n6) Delete Specific \n7) Count Nodes \n8) Search Data");
		printf("\n9) For Exit");
		printf("\nEnter Choice: ");
		scanf("%d", &in);

		switch(in)
		{
			case 1: createList(&start);
				break;
			case 2: insertAtBeg(&start);
				break;
			case 3: insertAtAny(start);
				break;
			case 4: displayData(start);
				break;
			case 5: deleteFromBeg(&start);
				break;
			case 6: deleteSpecific(&start);
				break;
			case 7: countNodes(start);
				break;
			case 8: searchNode(start);
				break;
			case 9: exit(1);

			default: printf("Invalid Option");
		}

	}

    return 0;
}

void createList(struct Node** head){
	struct Node* q = *head, *p;
	int d;

	printf("Enter Data: ");
	scanf("%d", &d);

	if(*head == NULL){
		p = (struct Node*) malloc(sizeof(struct Node));
		p->data = d;
		p->next = p;
		*head = p;

		return;
	}

	while(q->next != *head)
		q = q->next;

	p = (struct Node*) malloc(sizeof(struct Node));
	p->data = d;
	p->next = *head;
	q->next = p;
}

void insertAtBeg(struct Node** head){
	struct Node *p, *q;
	int d;
	q = *head;

	printf("Enter Data: ");
	scanf("%d", &d);

	p = (struct Node*) malloc(sizeof(struct Node));

	if(q == NULL){
		p->data = d;
		p->next = p;
		*head = p;
	}else {
		while(q->next != *head)
			q = q->next;

		p->data = d;
		p->next = *head;
		q->next = p;
		*head = p;
	}
}


void insertAtAny(struct Node* head){
	struct Node *p, *q;
	int d;
	q = head;

	printf("Enter Item to Add After:");
	scanf("%d", &d);

	if(head == NULL){
		printf("List is empty");
		return;
	}


	while(q->data != d){
		if(q->next == head){
			printf("Not Found in List");
			return;
		}

		q = q->next;
	}

	p = (struct Node*) malloc(sizeof(struct Node));

	printf("Enter Data to Insert");
	scanf("%d", &d);

	p->data = d;
	p->next = q->next;
	q->next = p;
}

void displayData(struct Node* head){
	struct Node* p = head;

	if(head == NULL){
		printf("List is empty");
	}else {
		while(p->next != head){
			printf("%d\n", p->data);
			p = p->next;
		}
		printf("%d\n", p->data);
	}
}

void deleteFromBeg(struct Node** head){
	struct Node *p, *q;
	p = *head;
	q = p;
	
	if(*head == NULL){
		printf("List is empty");
		return;
	}


	if(p->next == p){
		*head = NULL;
		free(p);
	}else{
		while(q->next != *head)
			q = q->next;

		q->next = p->next;
		*head = p->next;
		free(p);
	}
}
void deleteSpecific(struct Node** head){
	struct Node *q, *p;
	int d;
	q = *head;

	if(*head == NULL){
		printf("List is empty");
		return;
	}

	printf("Data to Delete:");
	scanf("%d", &d);

	if(q->data == d){
		deleteFromBeg(head);
	}

	while(q->next->data != d){
		if(q->next->next == *head) {
			printf("Not Found");
			return;
		}

		q = q->next;
	}

	p = q->next;
	q->next = q->next->next;
	free(p);
}

void countNodes(struct Node* head){
	struct Node* p;
	int count = 0;

	if(head != NULL) {
		p = head;
		while(p->next != head){
			count++;
			p = p->next;
		}
		count++;
	}

	printf("%d", count);
}
void searchNode(struct Node* head){
	struct Node* p;
	int d, loc;

	if(head == NULL){
		printf("List is empty");
		return;
	}


	printf("Item to search: ");
	scanf("%d", &d);

	loc =0;
	p = head;
	while(p->data != d){
		if(p->next == head){
			printf("Not in the list");
			return;
		}
		loc++;
		p = p->next;
	}

	printf("Item found at %d location", loc+1);
}
