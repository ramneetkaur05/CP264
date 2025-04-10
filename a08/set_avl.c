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
    return avl_search(s->root, e)? 1:0;
 }
 
 void set_add(SET *s, char *e){
    if (set_contain(s,e) == 0){
        RECORD r = {0};
        strcpy(r.name, e);
        avl_insert(s->root, r);
        s->size++;
    }
 }
 
 void set_remove(SET *s, char *e){
    if (set_contain(s,e) == 0){
        avl_delete(s->root, e);
        s->size--;
    }
 }
 
 void set_clean(SET *s){
    avl_clean(s->root);
 }   