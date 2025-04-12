/*
 * file: edgelist.c
 * author: ramneet
 * date: 12/04/25
 */ 

 #include <stdio.h>
 #include <stdlib.h> 
 #include "edgelist.h"
 
 EDGELIST *new_edgelist() {
     EDGELIST *tp = malloc(sizeof(EDGELIST));
     tp->size = 0;
     tp->start = NULL;
     tp->end = NULL;
     return tp;
 }
 
 void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
    EDGENODE *new_node = (EDGENODE*)malloc(sizeof(EDGENODE));
    new_node->from = from;
    new_node->to = to;
    new_node->weight = weight;
    new_node->next = NULL;

    if(g->start == NULL){
        g->start = new_node;
        g->end = new_node;
    } else {
        g->end->next = new_node;
        g->end = new_node;
    }
    g->size++;
  }
 
 void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
    EDGENODE *new_node = (EDGENODE*)malloc(sizeof(EDGENODE));
    new_node->from = from;
    new_node->to = to;
    new_node->weight = weight;
    new_node->next = g->start;
    g->start = new_node;

    if(g->end == NULL){
        g->end = new_node;
    }
    g->size++;
 }
 
 void delete_edge(EDGELIST *g, int from, int to) {
    EDGENODE *ptr = g->start, *prev = NULL;

    while (ptr!= NULL){
        if (ptr->from == from && ptr->to == to) {
            if (prev = NULL){
                g->start = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            if(ptr == g->end){
                g->end = prev;
            }
            free(ptr);
            g->size--;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
 }
 
 int weight_edgelist(EDGELIST *g) {
    int weight = 0;
    EDGENODE *ptr = g->start;
    while (ptr!= NULL){
        weight += ptr->weight;
        ptr->next;
    }
    return weight;
  }
 
 void clean_edgelist(EDGELIST **gp) {
     EDGELIST *g = *gp;
     EDGENODE *temp, *p = g->start;
     while (p) {
         temp = p;
         p = p->next;
         free(temp);
     }
     free(g);
     *gp = NULL;
 }
 
 void display_edgelist(EDGELIST *g) {
     if (g == NULL)
         return;
     printf("size %d ", g->size);
     printf("(from to weight) ");
     EDGENODE *p = g->start;
     while (p) {
         printf("(%d %d %d) ", p->from, p->to, p->weight);
         p = p->next;
     }
 }
 