
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int qu[MAX], f=-1, r= -1;
void enqueue();
void dequeue();
void display();


void main(){
	int in;
	while(1){
		printf("\n1)Insert \n2)Delete \n3)Display \n4)Exit");
		printf("\nEnter Choice:");
		scanf("%d", &in);

		switch(in){
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(1);
			default: printf("Invalid Option");
		}
	}
}

void enqueue(){
	int data;

	if((r== MAX-1 && f == 0) || (f==r+1)){
		printf("Overflow");
		return;
	}

	printf("Enter Data:");
	scanf("%d", &data);

	if(r==-1){
		r = f= 0;
	}else if(r == MAX-1 && f > 0){
		r=0;
	}else {
		r++;
	}
	qu[r] = data;
}
void dequeue(){
	if(f== -1){
		printf("Underflow");
		return;
	}

	printf("Data Removed: %d", qu[f]);
	if(f == r){
		f = r = -1;
	}else if(f == MAX-1 && r >= 0){
		f = 0;
	}else{
		f++;
	}
}
void display(){
	int i;

	if(f== -1){
		printf("Queue is Empty");
		return;
	}

	printf("Data In Queue");

	if(f>r){
		for(i =f; i< MAX; i++){
			printf("%d (%d), ", qu[i], i);
		}
		for(i=0; i<=r; i++){
			printf("%d (%d), ", qu[i], i);
		}
	}else{
		for(i=f; i<=r; i++){
			printf("%d (%d), ", qu[i], i);
		}

	}
}
