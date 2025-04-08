/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h> 
 #include "dllist.h"
 
 NODE *dll_node(char data) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
 }
 
 void dll_insert_start(DLL *dllp, NODE *np) {
    if (dllp == NULL) return;
    if (dllp->start == NULL){
        dllp->start = np;
        dllp->end = np;
    } else {
        dllp->start->prev = np;
        np->next = dllp->start;
    }
    dllp->start= np; 
    np->prev = NULL;
 }
 
 void dll_insert_end(DLL *dllp, NODE *np) {
    if (dllp == NULL) return;
    if(dllp->start == NULL){
        dllp->start = np;
        dllp->end = np;
    } else {
        dllp->end->next = np;
        np->prev = dllp->end;
    }
    dllp->end = np;
    np->next = NULL;
 }
 
 void dll_delete_start(DLL *dllp) {
    if (dllp == NULL) return;
    NODE *temp = dllp->start;
    if (dllp->length == 1) {
        dllp->start = NULL;
        dllp->end = NULL;
    } else {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }
    free(temp);
    dllp->length--;
  }
 
 void dll_delete_end(DLL *dllp) {
    if (dllp->length == 0) return;

    NODE *temp = dllp->end;
    if (dllp->length == 1) {
        dllp->start = NULL;
        dllp->end = NULL;
    } else {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }
    free(temp);
    dllp->length--;
 }
 
 void dll_clean(DLL *dllp) {
    if (dllp == NULL) return;

    NODE *temp, *ptr = dllp->start;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
        dllp->length--;
    }
    dllp->start = NULL;
    dllp->end = NULL;
 }