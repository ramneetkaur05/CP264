/*
 * file: hash.c
 * author: ramneet
 * date: 11/04/25
 */ 

 #include <stdio.h>
 #include <stdlib.h> 
 #include <string.h>
 #include "hash.h"
 
 HNODE *hashtable_search(HASHTABLE *ht, char *name) {
    int i = hash(name, ht->size);
    HNODE *ptr = ht->hna[i];

    while (ptr){
        if (strcmp(ptr->data.name, name) == 0){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
  }
 
 int hashtable_insert(HASHTABLE *ht, DATA data) {
    int i = hash(data.name, ht->size);
    HNODE *ptr = ht->hna[i];

    while (ptr){
        if (strcmp(ptr->data.name, data.name) == 0){
            ptr->data.value = data.value;
            return 0;
        }
        ptr = ptr->next;
    }

    // if not matched
    HNODE *new_node = (HNODE*) malloc(sizeof(HNODE));
    new_node->data = data;
    new_node->next = ht->hna[i];
    ht->hna[i] = new_node;
    ht->count++;
    return 1;
  }
 
 int hashtable_delete(HASHTABLE *ht, char *name) {
    int i = hash(name, ht->size);
    HNODE *ptr = ht->hna[i];
    HNODE *prev = NULL;

    while (ptr){
        if (strcmp(ptr->data.name, name) == 0){
            if (prev == NULL){
                ht->hna[i] = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            ht->count--;
            return 1;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return 0;


 }
 
 
 int hash(char* key, int size) {
     unsigned int hash = 0;
     while (*key) {
         hash += *key++;
     }
     return hash % size;
 }
 
 HASHTABLE *new_hashtable(int size) {
     HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
     ht->hna = (HNODE**) malloc(sizeof(HNODE**) * size);
     int i;
     for (i = 0; i < size; i++)
         *(ht->hna + i) = NULL;
 
     ht->size = size;
     ht->count = 0;
     return ht;
 }
 
 
 void hashtable_clean(HASHTABLE **htp) {
     if (*htp == NULL)
         return;
     HASHTABLE *ht = *htp;
     HNODE *p, *temp;
     int i;
     for (i = 0; i < ht->size; i++) {
         p = ht->hna[i];
         while (p) {
             temp = p;
             p = p->next;
             free(temp);
         }
         ht->hna[i] = NULL;
     }
     free(ht->hna);
     ht->hna = NULL;
     *htp = NULL;
 }
 