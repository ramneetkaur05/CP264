/*
 * file: set_avl.c
 * author: Ramneet Kaur Pannu
 * date: 10/04/25
 */ 
 
 #include "string.h" 
 #include "avl.h"
 #include "set_avl.h"
 
 int set_size(SET *s) {
    return s->size;
 }
 
 int set_contain(SET *s, char *e){
    AVLNODE **root = s->root;
    return avl_search(*root, e)? 1:0;
 }
 
 void set_add(SET *s, char *e){
    AVLNODE **root = s->root;
    if (set_contain(s,e) == 0){
        RECORD r = {0};
        strcpy(r.name, e);
        avl_insert(*root, r);
        s->size++;
    }
 }
 
 void set_remove(SET *s, char *e){
    AVLNODE **root = s->root;
    if (set_contain(s,e) == 0){
        avl_delete(*root, e);
        s->size--;
    }
 }
 
 void set_clean(SET *s){
    AVLNODE **root = s->root;
    avl_clean(*root);
 }   