/*
 * file: avl.c
 * author: Ramneet Kaur Pannu
 * date: 9/04/25
 */ 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "avl.h"


 AVLNODE *avl_node(RECORD data)
 {
   AVLNODE *np = (AVLNODE *)malloc(sizeof(AVLNODE));
   if (np)
   {
     np->data = data;
     np->height = 1;
     np->left = NULL;
     np->right = NULL;
   }
   return np;
 }
 
 
 int max(int a, int b) 
 {
   return (a > b)? a : b;
 }
 
 
 int height(AVLNODE *np)
 {
  return np->height;
 }
 
 int balance_factor(AVLNODE *np)
 {
  return height(np->left) - height(np->right);
 }
 
 
 AVLNODE *rotate_left(AVLNODE *np)
 {
  AVLNODE *parent = np->right;
  AVLNODE *child = np->left;

  // rotation
  parent->left = np;
  np->right = child;

  // updating the heights
  np->height = 1 + max(height(np->left), height(np->right));
  parent->height = 1 + max(height(parent->left), height(parent->right));

  return parent;
 }
 
 AVLNODE *rotate_right(AVLNODE *root){
  AVLNODE *child = root->left;
  AVLNODE *gran_child = root->right;

  // rotation
  child->right = root;
  root->left = gran_child;

  // updating the heights
  root->height = 1 + max(height(root->left), height(root->right));
  child->height = 1 + max(height(child->left), height(child->right));

  return child;
 }
 
 AVLNODE *extract_smallest_node(AVLNODE **rootp) {
   AVLNODE *p = *rootp, *parent = NULL;
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
 
 void avl_insert(AVLNODE **rootp, RECORD data)
 {  
   // 1. Perform the normal BST insertion
   if (*rootp == NULL) {
     AVLNODE *np = (AVLNODE *) malloc(sizeof(AVLNODE));
       if (np) {
         np->data = data;
         np->height = 1;
         np->left = NULL;
         np->right = NULL;
       }
       *rootp = np;
   } else {
   
     AVLNODE *root = *rootp;
     
     if (strcmp(data.name, root->data.name) == 0 )
       return;
     else if (strcmp(data.name, root->data.name) < 0 ) {
       avl_insert(&root->left, data);
     }
     else {
       avl_insert(&root->right, data);
     }
     
     // 2. update height of this ancestor node
     root->height = 1 + max(height(root->left), height(root->right));
     
     /* 3. Get the balance factor of this ancestor node to 
     check whether this node became unbalanced */
     int balance = balance_factor(root);
    
     // 4. rebalance if not balanced
     if (balance == 2 && balance_factor(root->left) >= 0) rotate_right(root);
     else if (balance  == 2 && balance_factor(root->left) < 0){
      root->left = rotate_left(root->left);
      rotate_right(root);
     }
     else if (balance == -2 && balance_factor(root->right) <= 0) rotate_left(root);
     else if (balance == -2 && balance_factor(root->right) > 0){
      root->right = rotate_right(root->right);
      rotate_left(root);
     }
   }
 }
 
 void avl_delete(AVLNODE **rootp, char *name)
 {
   AVLNODE *root = *rootp;
   AVLNODE *np;
   if (root == NULL) return;
 
   if (strcmp(name, root->data.name) == 0) {
     if (root->left == NULL && root->right == NULL) {
       free(root);
       *rootp = NULL;
     } else if (root->left != NULL && root->right == NULL) {
       np = root->left;
       free(root);
       *rootp = np;
     } else if (root->left == NULL && root->right != NULL) {
       np = root->right;
       free(root);
       *rootp = np;
     } else if (root->left != NULL && root->right != NULL) {
       np = extract_smallest_node(&root->right);
       np->left = root->left;
       np->right = root->right;
       free(root);
       *rootp = np;
     }
   } else {
     if (strcmp(name, root->data.name) < 0) {
       avl_delete(&root->left, name);
     } else {
       avl_delete(&root->right, name);
     }
   }
 
   // If the tree had only one node then return
   if (*rootp == NULL) return;
   root = *rootp;
     
   // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
   root->height = 1 + max(height(root->left), height(root->right));
 
   // STEP 3: GET THE BALANCE FACTOR OF THIS NODE 
   int balance = balance_factor(root);
 
   // STEP 4: rebalance if not balanced
   if (balance == 2 && balance_factor(root->left) >= 0) rotate_right(root);
   else if (balance  == 2 && balance_factor(root->left) < 0){
    root->left = rotate_left(root->left);
    rotate_right(root);
   }
   else if (balance == -2 && balance_factor(root->right) <= 0) rotate_left(root);
   else if (balance == -2 && balance_factor(root->right) > 0){
    root->right = rotate_right(root->right);
    rotate_left(root);
   }
 
 }
 
 AVLNODE *avl_search(AVLNODE *root, char *name) {
  if (root == NULL) return NULL;

  else if (root->data.name == name) return root;
  else if (name < root->data.name){
    return avl_search(root->left, name);
  } else {
    return avl_search(root->right, name);
  }

 }
 
 
 void avl_clean(AVLNODE **rootp) {
   AVLNODE *root = *rootp;
   if (root) {
     if (root->left)
       avl_clean(&root->left);
     if (root->right)
       avl_clean(&root->right);
     free(root);
   }
   *rootp = NULL;
 }
 