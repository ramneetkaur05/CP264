/*
 * your program signature
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
 // your code
 }
 
 int balance_factor(AVLNODE *np)
 {
 // your code
 }
 
 
 AVLNODE *rotate_left(AVLNODE *np)
 {
 // your code
 }
 
 AVLNODE *rotate_right(AVLNODE *root)
 {
 // your code
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
     //root->height = ???
     
     // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
     //int balance = ???
    
     // 4. rebalance if not balanced
     //???
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
   //root->height = ???
 
   // STEP 3: GET THE BALANCE FACTOR OF THIS NODE 
   //int balance = ???
 
   // STEP 4: rebalance if not balanced
   //???
 
 }
 
 AVLNODE *avl_search(AVLNODE *root, char *name) {
 // your code
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
 