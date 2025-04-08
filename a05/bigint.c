/*
 * file: bigint.h 
 * author: Ramneet Kaur Pannu
 * Date: 8/04/25
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "bigint.h"
 
 BIGINT bigint(char *p) {
   BIGINT bn = {0};
   if (p == NULL) 
     return bn;
   else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
     return bn;
   }
   else if (*p == '0' && *(p+1) == '\0') {// just "0"
     dll_insert_end(&bn, dll_node(*p -'0'));
     return bn;
   }  
   else { 
     while (*p) {
       if (*p >= '0' && *p <= '9' ){
         dll_insert_end(&bn, dll_node(*p -'0'));
       } else {
         dll_clean(&bn);
         break;
       }
       p++;
     }
     return bn;
   }
 }
 
 BIGINT bigint_add(BIGINT op1, BIGINT op2) {
    BIGINT sum = bigint(NULL);

    NODE *ptr1 = op1.end;
    NODE *ptr2 = op2.end;
    int carry = 0, a,b,s;

    while(ptr1 || ptr2){
        a=0;b=0;
        if(ptr1){
            a=ptr1->data;
            ptr1->prev;
        }
        if(ptr2){
            b=ptr2->data;
            ptr2->prev;
        }
        s = a+b+carry;
        carry = s/10;
        dll_insert_start(&sum, dll_node(s%10));
    }
    if (carry > 0){
        dll_insert_start(&sum, dll_node(carry));
    }
    return sum;


 }
 
 BIGINT bigint_fibonacci(int n) {
    BIGINT f1 = bigint("0");
    BIGINT f2 = bigint("1");
    BIGINT fn = bigint(NULL);

    if (n == 0) {
      return f1;
    } else if (n == 1){
      return f2;
    } else {
      for(int i = 2; 1<n; i++){
        fn = bigint_add(f1, f2);
        dll_clean(&f1);
        f1=f2;
        f2=fn;
      }
      return fn;
    }




 }