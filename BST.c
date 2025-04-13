
#include<stdio.h>
 #include<stdlib.h>
 
 struct Node {
 	int data;
 	struct Node* left;
 	struct Node* right;
 };
 
 void insert(struct Node** root, struct Node* newNode);
 void delete(struct Node** root);
 void preorder(struct Node* root);
 void postorder(struct Node* root);
 void inorder(struct Node* root);
 void search(struct Node* root, int data,struct Node** par, struct Node** selected);
 void findSucc(struct Node* right, struct Node** par, struct Node** succ);
 void findPred(struct Node* left,struct Node** par, struct Node** pred);
 
 void main(){
 	int in;
 	struct Node* root = NULL;
 
 	while(1){
 		printf("\n1)Insert \n2)Delete \n3)Preorder \n4)Postorder \n5)Inorder \n6)Exit");
 		printf("\nEnter Choice:");
 		scanf("%d", &in);
 
 		switch(in){
 			case 1: insert(&root, NULL);
 				break;
 			case 2: delete(&root);
 				break;
 			case 3: preorder(root);
 				break;
 			case 4: postorder(root);
 				break;
 			case 5: inorder(root);
 				break;
 			case 6: exit(1);
 
 
 			default: printf("Invalid Option");
 		}
 	}
 }
 
 void insert(struct Node** root, struct Node* newNode){
 	if(newNode == NULL){
 		newNode = (struct Node*) malloc(sizeof(struct Node));
 		
 		printf("Enter Data:");
 		scanf("%d", &newNode->data);
 		newNode->left = NULL;
 		newNode->right = NULL;
 	}
 
 	if(*root == NULL){
 		*root = newNode;
 	}else if((*root)->data > newNode->data){
 		insert(&(*root)->left, newNode);
 	}else {
 		insert(&(*root)->right, newNode);
 	}
 }
 
 void delete(struct Node** root){
 	int item; 
 	struct Node *itemNode = NULL, *parNode = NULL;
 	struct Node *nearNode = NULL, *nearParNode = NULL;
 
 	if(*root == NULL){
 		printf("Tree is Empty");
 		return;
 	}
 
 	printf("Item to Delete: ");
 	scanf("%d", &item);
 
 	search(*root, item, &parNode, &itemNode);
 	if(itemNode==NULL){
 		printf("Item Not Found\n");
 		return;
 	}
 
 	// Leaf Node or Only Root
 	if(itemNode->left == NULL && itemNode->right == NULL){
 
 		if(parNode == NULL){
 			*root = NULL;
 		}else if(parNode->left == itemNode){
 			parNode->left = NULL;
 		}else {
 			parNode->right = NULL;
 		}
 
 		printf("Deleted Leaf or Only Root");
 	}else if(itemNode->left != NULL){
 		findPred(itemNode->left, &nearParNode, &nearNode);
 
 		// Root Node
 		if(parNode == NULL){
 			nearParNode->right = nearNode->left;
 			nearNode->right = (*root)->right;
 			nearNode->left = (*root)->left;
 			*root = nearNode;
 		}else {
 			nearParNode->right = nearNode->left;
 			nearNode->left = itemNode->left;
 			nearNode->right = itemNode->right;
 			
 			if(parNode->left == itemNode){
 				parNode->left = nearNode;
 			}else {
 				parNode->right = nearNode;
 			}
 		}
 
 		printf("Used Pred");
 	}else{
 		findSucc(itemNode->right, &nearParNode, &nearNode);
 
 		// Root Node
 		if(parNode == NULL){
 			nearParNode->left = nearNode->right;
 			nearNode->right = (*root)->right;
 			nearNode->left = (*root)->left;
 			*root = nearNode;
 		}else {
 			nearParNode->left = nearNode->right;
 			nearNode->left = itemNode->left;
 			nearNode->right = itemNode->right;
 			
 			if(parNode->left == itemNode){
 				parNode->left = nearNode;
 			}else {
 				parNode->right = nearNode;
 			}
 
 		}
 
 		printf("Used Succ");
 	}
 
 
 	free(itemNode);
 }
 void preorder(struct Node* root){
 	if(root == NULL) return;
 
 	printf("%d, ", root->data);
 
 	if(root->left != NULL){
 		preorder(root->left);
 	}
 
 	if(root->right != NULL){
 		preorder(root->right);
 	}
 }
 void postorder(struct Node* root){
 	if(root == NULL) return;
 
 	if(root->left != NULL){
 		postorder(root->left);
 	}
 
 	if(root->right != NULL){
 		postorder(root->right);
 	}
 
 	printf("%d, ", root->data);
 }
 void inorder(struct Node* root){
 	if(root == NULL) return;
 
 	if(root->left != NULL){
 		inorder(root->left);
 	}
 
 	printf("%d, ", root->data);
 
 	if(root->right != NULL){
 		inorder(root->right);
 	}
 
 }
 
 void search(struct Node* root, int data, struct Node** par, struct Node** selected){
 	if(root == NULL) return;
 
 	if(root->data == data){
 		*selected = root;
 		return;
 	}else if(root->data > data){
 		search(root->left, data, par, selected);
 	}else {
 		search(root->right, data, par, selected);
 	}
 
 	if(*selected != NULL && *par == NULL){
 		*par = root;
 	}
 
 }
 
 void findSucc(struct Node* right, struct Node** par, struct Node** succ){
 	if(right == NULL) return;
 
 	if(right->left != NULL){
 		findSucc(right->left, par, succ);
 	}
 
 	if(*succ == NULL){
 		*succ = right;
 		return;
 	}
 
 	
 	if(*succ != NULL && *par == NULL){
 		*par = right;
 	}
 }
 
 void findPred(struct Node* left,struct Node** par, struct Node** pred){
 	if(left == NULL) return;
 
 
 	if(left->right != NULL){
 		findPred(left->right, par, pred);
 	}
 
 	if(*pred == NULL){
 		*pred = left;
 
 		return;
 	}
 
 	if(*pred != NULL && *par == NULL){
 		*par = left;
 	}
 }
