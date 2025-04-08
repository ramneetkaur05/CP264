/*
 * file: myrecord_sllist.c
 * author: Ramneet Kaur Pannu
 * Date: 8/04/25
 */ 
 

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "myrecord_sllist.h"
 
 
 NODE *sll_search(SLL *sllp, char *name) {

    NODE *ptr = sllp->start;

    while(ptr != NULL){
        if (strcmp(ptr->data.name, name) == 0){
            return ptr;
        } 
        ptr = ptr->next;
        
    }
    return NULL;

 }
 
 void sll_insert(SLL *sllp, char *name, float score) {

    //create a node first
    NODE *np = (NODE*)malloc(sizeof(NODE));
    //initialize node
    strcpy(np->data.name, name);
    np->data.score = score;
    np->next = NULL;

    //insert node into SLL
    NODE *prev = NULL, *p = sllp->start;
    while (p!=NULL && strcmp(p->data.name, name) < 0){ //while the pointer != NULL and the name in the array does not surpase the name given lexically
        prev = p;
        p = p->next;
    }
    if (prev == NULL){ //if its empty, insert in the begining
        np->next = sllp->start;
        sllp->start = np;
    }else{
        prev->next = np; //otherwise, insert in between pointer and previous
        np->next = NULL;
    }
    sllp->length++; //update the sll length!


  }
 
 int sll_delete(SLL *sllp, char *name) {

    NODE *p = sllp->start;
    while (p!=NULL){ //while the pointer != NULL and the name in the array does not match the name given
        p = p->next;
        if (p->data.name == name) {
            p = p->next;
            free(p);
            return 1;
        }
    }
    return 0;

 }
 
 void sll_clean(SLL *sllp) {
     NODE *temp, *ptr = sllp->start;
     while (ptr != NULL) {
         temp = ptr;
         ptr = ptr->next;
         free(temp);
     }
     sllp->start = NULL;
     sllp->length = 0;
 }
 