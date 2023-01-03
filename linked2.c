
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

Node * head = NULL;

void insert_front(int value){
    Node * new_node = (struct Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

void insert_back(int value){
    Node * current = head;
    while(current->next != NULL){
        current = current->next;
    }

    Node * new_node = (struct Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    current->next = new_node;
}

void print_linked_list(){
    Node * current = head;
    while(current != NULL){
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}

int main(){
    insert_front(10);
    insert_front(9);
    insert_back(99);
    print_linked_list();
    return 0;
}
