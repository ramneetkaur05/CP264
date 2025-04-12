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
 // your code
 }
 
 void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
 // your code;
 }
 
 void delete_edge(EDGELIST *g, int from, int to) {
 // your code
 }
 
 int weight_edgelist(EDGELIST *g) {
 // your code
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
 