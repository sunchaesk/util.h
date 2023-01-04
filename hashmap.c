
// capable of dealing with hash_value clashes

// NOTE: works fine when checked with gdb but print function is messed up

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTABLE_SIZE 100

typedef struct HashmapEntry {
    char * key;
    int value;
    struct HashmapEntry * next;
} HashmapEntry;

typedef struct Hashmap{
    // list of array of linked list
    HashmapEntry * entries[HASHTABLE_SIZE];
} Hashmap;

/* int hash(char* key){ */
/*     int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; */
/*     int hash_value = 1; */
/*     for (size_t i = 0; i < strlen(key); i++){ */
/*         hash_value *= primes[(int)key[i] - 97]; */
/*     } */
/*     return hash_value % HASHTABLE_SIZE; */
/* } */

int hash(char * key){
    return 1;
}

void hashmap_put(Hashmap * map, char * key, int value){
    int hash_value = hash(key);
    HashmapEntry * entry = map->entries[hash_value];
    while (entry != NULL){
        // this is for the case of preexisting key
        if (strcmp(entry->key, key) == 0){
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    entry = malloc(sizeof(HashmapEntry));
    entry->key = key;
    entry->value = value;
    // insert to the front
    entry->next = map->entries[hash_value];
    map->entries[hash_value] = entry;
}

int hashmap_get(Hashmap * map, char * key){
    int hash_value = hash(key);
    HashmapEntry * entry = map->entries[hash_value];
    while (entry != NULL){
        if (strcmp(entry->key, key) == 0){
            return entry->value;
        }
        entry = entry->next;
    }
    // assuming all values are positive
    return -1;
}

Hashmap * initialize_hashmap(){
    Hashmap * map = (struct Hashmap *)malloc(sizeof(Hashmap));
    for (int i = 0; i < HASHTABLE_SIZE; i++){
        map->entries[i] = NULL;
    }
    return map;
}

void print_hashmap(Hashmap * map){
    for (int i = 0; i < HASHTABLE_SIZE; i++){
        printf("%d", i);
        HashmapEntry * current = map->entries[i];
        while (current != NULL){
            printf("%d", current->value);
        }
        printf("\n");
    }
}

int main(){
    Hashmap * map = initialize_hashmap();
    hashmap_put(map, "a", 10);
    hashmap_put(map, "b", 12);
    //print_hashmap(map);
    return 0;
}
