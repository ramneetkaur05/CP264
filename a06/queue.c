/*
 * file: queue.c 
 * author: Ramneet Kaur Pannu
 * date: 8/04/25
 */ 

 #include <stdio.h>
 #include "queue.h"
 
 void enqueue(QUEUE *qp, NODE *np) {
    if (qp->front == NULL){
        qp->front = np;
        qp->rear = np;
    } else {
        qp->rear->next = np;
        qp->rear = np;
    }
    qp->length++;
    return;
 }  
 
 NODE *dequeue(QUEUE *qp) {
    NODE *temp = qp->front;
    if (qp->front == NULL){
        return NULL;
    } else{
        qp->front = qp->front->next;
        qp->length--;
        return temp;
    }
 }
 
 void clean_queue(QUEUE *qp) {
   clean(&(qp->front));
   qp->front = NULL;
   qp->rear = NULL;
   qp->length=0;
 }