/*
 * file: expression.c
 * author: Ramneet Kaur Pannu
 * date: 8/04/25
 */ 

 #include <stdio.h>
 #include <stdlib.h>
 #include "common.h"
 #include "queue.h"
 #include "stack.h"
 #include "expression.h"


 /** 
 QUEUE infix_to_postfix(char *infixstr) {
    STACK *s = {0}; // aux stack
    QUEUE *pe = {0}; //for teh result expression queue
    char *p = infixstr; // pointer to the string
    int sign = 1, num = 0;

    while (*p){ // expresssion str traversall
        if (*p == '-' && (p==infixstr || *(p-1)== '(')) { // sign of an operand
            sign = -1;
        } 
        else if (mytype(*p) == 0){ //*p is a digit char, use horners algo to get operand
            num = *p -'0';
            while ((*(p+1) >= '0' && *(p+1) <= '9')){
                num = num*10 + *(p+1)-'0';
                p++;
            }
            enqueue(&pe, new_node(sign*num,0));
            sign = 1;
        }
        else if (mytype(*p) == 1){

        }


    }
  }
*/ //skipping bc its not going to be on the exam, and i am tired :(
 
 int evaluate_postfix(QUEUE queue) {
    NODE *ptr = queue.front;
    STACK *s = {0}; //aux stack
    int type = 0; //0:operand; 1:operator; 2:left parenthesis 3:right parenthesis

    if (queue.length == 0){
        return NULL;
    }
    while (ptr != NULL){
        type = ptr->type;
        if (type ==0){ // operand
            push(&s, new_node(ptr->data, 0));
        }
        else if (type == 1){ // operator
            int operator = ptr->data;
            NODE* op2 = pop(&s);
            if(operator == '+'){
                s->top->data = s->top->data + op2->data;
            }
            else if (operator == '-'){
                s->top->data = s->top->data - op2->data;
            }
            else if (operator == '*'){
                s->top->data = s->top->data * op2->data;
            }
            else if (operator == '/'){
                s->top->data = s->top->data / op2->data;
            }
            free(op2);
        }
        ptr = ptr->next;
    }
    int result = s->top->data;
    clean_stack(&s);
    return result;
 }
 
 int evaluate_infix(char *infixstr) {
    QUEUE postfixQueue = infix_to_postfix(infixstr);
    return evaluate_postfix(postfixQueue);
 }
 