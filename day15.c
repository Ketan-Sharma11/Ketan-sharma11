#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertBegin(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBegin() {
    if(head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void traverseForward() {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseReverse() {
    if(head == NULL) return;
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void makeCircular() {
    if(head == NULL) return;
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}

int main() {
    int choice, data;
    printf("DOUBLY CIRCULAR LINKED LIST MENU\n");
    printf("1.Insert Begin  2.Insert End\n");
    printf("3.Delete Begin  4.Delete End\n");
    printf("5.Traverse Forward  6.Traverse Reverse\n");
    printf("7.Make Circular  0.Exit\n");
    
    while(1) {
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                insertBegin(data);
                break;
            case 2:
                printf("Data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                deleteBegin();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                traverseForward();
                break;
            case 6:
                traverseReverse();
                break;
            case 7:
                makeCircular();
                printf("List made circular!\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}