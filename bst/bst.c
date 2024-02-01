#include <stdio.h>
#include <stdlib.h>

//bst tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else{
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;}
}
//recursive function to search through bst
int searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {//data==data, so it found the node they want to delete
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        //if neither of the branches are null
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        printf("(");
        printTree(root->left);
        printf("%d", root->data);
        printTree(root->right);
        printf(")");
    }
}
//free tree starting from top
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char command;
    int value;
    struct Node* root;

    while (scanf("%c", &command) != EOF) {
        if (command == 'i') {
            scanf("%d", &value);
            if (searchNode(root, value)) {
                printf("not inserted\n");
            } else {
                root = insertNode(root, value);
                printf("inserted\n");
            }
        } else if (command == 's') { 
            scanf("%d", &value);
            if (searchNode(root, value)) {
                printf("present\n");
            } else {
                printf("absent\n");
            }
        }   else if (command == 'd') { 
            scanf("%d", &value);
            if (searchNode(root, value)) {
                root = deleteNode(root, value);
                printf("deleted\n");
            } else {
                printf("absent\n");
            }
        }
            else if (command == 'p') {
                printTree(root);
                printf("\n");
            }
    }

    freeTree(root);

    return 0;
}
