
#include <stdio.h>
#include <stdlib.h>

typedef union{
    int int_val;
    double double_val;
    char * str_val;
} Value;

typedef enum {
INT,
DOUBLE,
STR
} Type;

typedef struct Node {
    Value value;
    Type type;
    struct Node * next;
} Node;

typedef struct linked_list {
    Node * head;
    size_t size;
} LinkedList;

LinkedList * initialize_linked_list(){
    LinkedList * linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    linked_list->head = NULL;
    linked_list->size = 0;
    return linked_list;
}

void push(LinkedList * list, Type type, Value value){
    Node * new_node = (struct Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->type = type;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

Value pop(LinkedList * list){
    if (list->size == 0){
        fprintf(stderr, "Error\n");
        exit(1);
    }

    Value val = list->head->value;
    Node * next = list->head->next;
    free(list->head);
    list->head = next;
    list->size--;
    return val;

}

int main(){

    return 0;
}
