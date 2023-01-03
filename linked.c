
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
} Node;

void insert_front(Node** head, int value){
    Node* new_node = (struct Node *)malloc(sizeof(Node));
    new_node->data= value;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL){
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void insert_back(Node**head, int data){
    Node * new_node = (struct Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // first time inserting element
    if (*head == NULL){
        new_node->prev = NULL;
        *head = new_node;
    }

    // else
    Node * last = *head;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

int main(){

    return 0;
}
