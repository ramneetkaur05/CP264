/*
 * file: queue.c 
 * author: Ramneet Kaur Pannu
 * date: 8/04/25
 */ 

 #include <stdio.h>
 #include "queue.h"
 
 void enqueue(QUEUE *qp, NODE *np) {
    if (qp->length == 0){
        qp->front = np;
        qp->rear = np;
    } else {
        qp->rear->next = np;
        qp->rear = np;
    }
 }  
 
 NODE *dequeue(QUEUE *qp) {
    NODE *temp = qp->front;
    if (qp->front == NULL){
        printf("\nUNDERFLOW!! ABORT! ABORT!");
        return NULL;
    } else{
        qp->front->next = qp->front;
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