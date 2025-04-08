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

    NODE *p = NULL, *np = sllp->start;

    while(np != NULL){
        if (strcmp(np->data.name, name) == 0){
            np = p;
        } else{
            np = np->next;
        }
    }
    return p;

 }
 
 void sll_insert(SLL *sllp, char *name, float score) {
 // your code
 }
 
 int sll_delete(SLL *sllp, char *name) {
 // your code
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
 