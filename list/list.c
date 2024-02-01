/*#include <stdio.h>

int main(int argc, char *argv[]) {

//standard input either wants to insert or delete a number from the list
//the list has to b sorted least to greatest
// the input will b i n or d n, output wtil be length : list in order
//read first character in input (if list length =0, put in list without comparing) if i , compare number and if less put before if more, put after
//print output
char inorout[1];
scanf("%s", inorout);
int num;
scanf("%d", num);
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

//insert- first run through list and check if n=anything in the list, if it does dont insert it
void insert(Node** head, int n) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == n) {
            return; 
        }
        current = current->next;
    }
 
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;

    if (*head == NULL || n < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && n > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(Node** head, int n) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == n) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != n) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char inorout;
    int n;
    Node* head = NULL;

    while (scanf("%c %d", &inorout, &n) != EOF) {
        getchar(); 
        if (inorout == 'i') {
            insert(&head, n);
        } else if (inorout == 'd') {
            deleteNode(&head, n);
        }
        
        Node* current = head;
        int length = 0;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        if (length==0){printf("0 :\n");}
        else{
        printf("%d : ", length);
        printList(head);}
    }

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}