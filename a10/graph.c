/*
 * file: graph.c
 * author: ramneet
 * date: 12/04/25
 */ 

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "queue_stack.h"
 #include "graph.h"
 
 GRAPH *new_graph(int order) {
   GRAPH *gp = malloc(sizeof(GRAPH));
   gp->nodes = malloc(order * sizeof(GNODE*));
   
   int i;
   for (i = 0; i < order; i++) {
     gp->nodes[i] = malloc(sizeof(GNODE));
     gp->nodes[i]->nid = i;
     strcpy(gp->nodes[i]->name, "null");
     gp->nodes[i]->neighbor = NULL;
   }
   
   gp->order = order;
   gp->size = 0;  
  
   return gp;
 }
 
 void insert_edge_graph(GRAPH *g, int from, int to, int weight) {

    ADJNODE *ptr = g->nodes[from]->neighbor;
    ADJNODE *prev = NULL;

    while (ptr != NULL){
        if (ptr->nid == to){
            // edge exsists, update wheight
            ptr->weight = weight;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    // node doesn't exsist
    ADJNODE *new_node = (ADJNODE*)malloc(sizeof(ADJNODE));
    new_node->nid = to;
    new_node->weight = weight;
    new_node->next = NULL;

    // add to the end of the list
    if (prev == NULL){
        g->nodes[from]->neighbor = new_node;
    } else {
        prev->next = new_node;
    }
    g->size++; // increase size
  }
 
 void delete_edge_graph(GRAPH *g, int from, int to) {
 // your code
 }
 
 int get_edge_weight(GRAPH *g, int from, int to) {
 // your code
 }
 
 void traverse_bforder(GRAPH *g, int nid) {
 // your code
 }
 
 
 // Use auxiliary stack data structure for the algorithm
 void traverse_dforder(GRAPH *g, int nid) {
 // your code
 }
 
 void clean_graph(GRAPH **gp) {
   int i;
   GRAPH *g = *gp;
   ADJNODE *temp, *ptr;
   for (i = 0; i < g->order; i++) {
     ptr = g->nodes[i]->neighbor;
     while (ptr != NULL) {
       temp = ptr;
       ptr = ptr->next;
       free(temp);
     }
     free(g->nodes[i]);
   }
   free(g->nodes);
   free(g);
   *gp = NULL;
 }
 
 void display_graph(GRAPH *g) {
   if (g ) {
   printf("order %d ", g->order);
   printf("size %d ", g->size);
   printf("(from to weight) ");
   int i;
   ADJNODE *ptr;
   for (i = 0; i < g->order; i++) {
     //printf("\n%d:", g->nodes[i]->nid);
     ptr = g->nodes[i]->neighbor;
     while (ptr != NULL) {
       printf("(%d %d %d) ", i,  ptr->nid, ptr->weight);
       ptr = ptr->next;
     }
   }
   }
 }
 