/*
 * file: mysort.c
 * author: Ramneet Kaur Pannu
 * date: 6/04/25
 */ 


 #include "mysort.h"

 // swap pointers
 void swap(void **x, void **y) {
      void *temp = *y;
      *y = *x;
      *x = temp;
 }
 
 // a compare floating values pointed by void pointers. 
 int cmp(void *x, void *y) {
    float a = *(float*)x;
    float b = *(float*)y; 
      if (a > b) return 1;
      else if (a < b) return -1;
      else return 0;
 }   
 
 void select_sort(void *a[], int left, int right)
 {
     int i,j, min;
     for(i = left; i<=right;i++){
          min = i;
          for(j= i+1; j <= right; j++){
               if (a[min] > a[j]){
                    min = j;
               }

          }
          if(min != i){
               swap(min, i);
          }

     }
 }
 
 void quick_sort(void *a[], int left, int right)
 { 
 // your code
 }
 
 void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) )
 { 
 // your code
 }
 