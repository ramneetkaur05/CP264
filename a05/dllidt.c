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
    dllp->end = np;
    np->next = NULL;
 }
 
 void dll_insert_end(DLL *dllp, NODE *np) {
 // your code
 }
 
 void dll_delete_start(DLL *dllp) {
 // your code
 }
 
 void dll_delete_end(DLL *dllp) {
 // your code
 }
 
 void dll_clean(DLL *dllp) {
 // your code
 }