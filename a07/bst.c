/*
 * file: bst.h
 * author: Ramneet Kaur Pannu
 * date: 9/04/25
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "bst.h"

 BSTNODE *bst_node(RECORD data);
 BSTNODE *extract_smallest_node(BSTNODE **rootp);
 
 BSTNODE *bst_search(BSTNODE *root, char *key) {
    if (root == NULL) return NULL;
    else if (key == root->data.name) return root;
    else if (key < root->data.name){
        return bst_search(root->left, key);
    } else {
        return bst_search(root->right, key);
    }
 }
 
 void bst_insert(BSTNODE **rootp, RECORD data) {
    if (rootp == NULL) {
        *rootp = bst_node(data);
        return;
    }
    if (strcmp(data.name, (*rootp)->data.name) < 0){
        bst_insert(&(*rootp)->left, data);
    } else {
        bst_insert(&(*rootp)->right, data);
    }
    
  }
 
 void bst_delete(BSTNODE **rootp, char *key) {
    BSTNODE *ptr = bst_search(*rootp, key);
    BSTNODE *temp;

    if (ptr->left == NULL){
        temp = ptr;
        ptr = ptr->right;
        free(temp);
    } else if (ptr->right == NULL){
        temp = ptr;
        ptr = ptr->left;
        free(temp);
    } else {
        temp = extract_smallest_node(&(ptr)->right);
        ptr->data = temp->data;
        free(temp);
    }

 }
 
 
 void bst_clean(BSTNODE **rootp) {
     BSTNODE *root = *rootp;
     if (root) {
         if (root->left)
             bst_clean(&root->left);
         if (root->right)
             bst_clean(&root->right);
         free(root);
     }
     *rootp = NULL;
 }

 BSTNODE *bst_node(RECORD data) {
    BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
    if (np) {
        memcpy(np, &data, sizeof(BSTNODE));
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}
 
 BSTNODE *extract_smallest_node(BSTNODE **rootp) {
     BSTNODE *p = *rootp, *parent = NULL;
     if (p) {
         while (p->left) {
             parent = p;
             p = p->left;
         }
 
         if (parent == NULL)
             *rootp = p->right;
         else
             parent->left = p->right;
 
         p->left = NULL;
         p->right = NULL;
     }
 
     return p;
 }
 