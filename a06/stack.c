/*
 * file: stack.c
 * author: Ramneet Kaur Pannu
 * date: 8/04/25
 */ 
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    if (sp->length == 0){
        sp->top = np;
    }else{
        np->next = sp->top;
        sp->top = np;
    }
    sp->length++;
    return;
}

NODE *pop(STACK *sp) {
    NODE *ptr = sp->top;
    if (sp->top == NULL){
        return NULL;
    } else {
        sp->top = sp->top->next;
        sp->length--;
    }
    return ptr;
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}