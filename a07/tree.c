/*
 * file: tree.h
 * author: Ramneet Kaur Pannu
 * date: 9/04/25
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "queue_stack.h"
 #include "tree.h"
 
 TPROPS tree_property(TNODE *root) {
    if (root == NULL){
        return (TPROPS) {0, -1}; //empty tree
    }
    TPROPS lp = tree_property(root->left);
    TPROPS rp = tree_property(root->right);

    TPROPS result;
    result.order = 1 + lp.order + rp.order;
    result.height = 1 + lp.height + rp.height;
 }
 
 void preorder(TNODE *root) {
    if (root){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
 }
 
 void inorder(TNODE *root) {
    if (root){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
 }
 
 void postorder(TNODE *root) {
    if (root){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
 }
 
 void bforder(TNODE *root) {
    QUEUE q = {0};
    enqueue(&q, root);
    while(q.front){
        TNODE *p = dequeue(&q);
        printf("%c", p->data);
        if (p->left) enqueue(&q, p->left);
        if (p->right) enqueue(&q, p->right);
    }
 }
 
 TNODE *bfs(TNODE *root, char val) {
 // your code
 }
 
 TNODE *dfs(TNODE *root, char val) {
 // your code
 }
 
 
 // the following functions are given, need to add to your program.
 
 TNODE *tree_node(char val) {
     TNODE *np = (TNODE *) malloc(sizeof(TNODE));
     if (np != NULL) {
         np->data = val;
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void clean_tree(TNODE **rootp) {
     TNODE *p = *rootp;
     if (p) {
         if (p->left)
             clean_tree(&p->left);
         if (p->right)
             clean_tree(&p->right);
         free(p);
     }
     *rootp = NULL;
 }
 
 void insert_tree(TNODE **rootp, char val) {
     if (*rootp == NULL) {
         *rootp = tree_node(val);
     } else {
         QUEUE queue = { 0 };
         TNODE *p;
         enqueue(&queue, *rootp);
         while (queue.front) {
             p = dequeue(&queue);
             if (p->left == NULL) {
                 p->left = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->left);
             }
 
             if (p->right == NULL) {
                 p->right = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->right);
             }
         }
     }
 }
 