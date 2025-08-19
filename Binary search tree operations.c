#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild;
	struct node *rchild;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->lchild = NULL;
	node->rchild = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->lchild = insert(root->lchild, data);
    else if (data > root->data)
        root->rchild = insert(root->rchild, data);

    return root;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->lchild != NULL)
        current = current->lchild;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->lchild = deleteNode(root->lchild, data);
    else if (data > root->data)
        root->rchild = deleteNode(root->rchild, data);
    else {
        if (root->lchild == NULL) {
            struct Node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL) {
            struct Node* temp = root->lchild;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

int main() {
    struct Node* root = NULL;

    // Insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 10);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal after insertion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 10);  
    root = deleteNode(root, 30);  
    root = deleteNode(root, 50);  

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

