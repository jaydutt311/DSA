#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node * left;
    struct node * right;
} node;

node * getInPred(node*, node*);
void deleteNode(node **, node *, int, int);
void createTree(node ** root, int data);
void printing(node * root);

int main(){
    node * root = NULL;
    int d;
    while(1){
        printf("Enter \n1 for insert \n2 for display \n3 for delete \n9 for exit");
        scanf("%d",&d);
        if(d == 1){
            printf("Enter a value : ");
            scanf("%d",&d);
            createTree(&root, d);
        }
        else if(d == 2)
            printing(root);
        else if(d == 3){
            printf("Enter data to delete : ");
            scanf("%d", &d);
            deleteNode(&root, NULL, d, 0);
        }
        else if(d == 9)
            break;
        else
            printf("Wrong Choice : \n");
    }
    return 0;
}

node* getInPred(node* root, node* prev){
    if(root->left == NULL){
        if(prev != NULL)
            prev->left = NULL;
        return root;
    }
    getInPred(root->left, root);
    return NULL;
}
void deleteNode(node ** root, node * prev, int data, int l){
    if(*root == NULL)
        return;
    if((*root)->val == data){
        node * temp = *root;
        printf("Found data \n ");
        // delete leaf node
        if((*root)->left == NULL && (*root)->right == NULL){
            if(prev == NULL){
                *root = NULL;
            }
            else if(l == 1)
                prev->left = NULL;
            else
                prev->right = NULL;
        }
        // del with right child
        else if((*root)->left == NULL){
            if(prev == NULL)
                *root = (*root)->right;
            else if(l == 1)
                prev->left = (*root)->right;
            else
                prev->right = (*root)->right;
        }
        // del with left child
        else if((*root)->right == NULL){
            if(prev == NULL)
                *root = (*root)->left;

            else if(l == 1)
                prev->left = (*root)->left;
            else
                prev->right = (*root)->left;
        }
        // del with 2 child
        else{
            node * InPred = getInPred((*root)->right, NULL);
            if(InPred != (*root)->left)
                InPred->left = (*root)->left;
            if(InPred != (*root)->right)
                InPred->right = (*root)->right;
            if(prev == NULL)
                *root = InPred;
            else if(l == 1)
                prev->left = InPred;
            else
                prev->right = InPred;
        }
        free(temp);
    }
    else{
        deleteNode(&(*root)->left, *root, data, 1);
        deleteNode(&(*root)->right, *root, data, 0);
    }
}

void createTree(node ** root, int data){
    if(*root == NULL){
        *root = (node*)malloc(sizeof(node));
        (*root)->val = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if((*root)->val > data){
        if((*root)->left == NULL){
            node * temp = (node*)malloc(sizeof(node));
            temp->val = data;
            temp->left = NULL;
            temp->right = NULL;
            (*root)->left = temp;
        }
        else{
            createTree(&(*root)->left, data);
        }
        return;
    }
    else{
        if((*root)->right == NULL){
            node * temp = (node*)malloc(sizeof(node));
            temp->val = data;
            temp->left = NULL;
            temp->right = NULL;
            (*root)->right = temp;
        }
        else
            createTree(&(*root)->right, data);
        return;
    }
}

void printing(node * root){
    if(root == NULL)
        return;
    printing(root->left);
    printf("%d \n",root->val);
    printing(root->right);
}
