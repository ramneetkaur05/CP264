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
     for(i = left; i<=right;++i){
          min = i;
          for(j= i+1; j <= right; ++j){
               if (cmp(a[j], a[min]) < 0){ // if j < min
                    min = j;
               }

          }
          if(i != min){ // swap min with i (what the flip is i?? Pointer??)
               swap(&a[i], &a[min]);
          }

     }
 }
 
 void quick_sort(void *a[], int left, int right){
     
     if(left < right){
          int i = left +1;
          int j = right;

          while(i<=j){
               while (i<= right && cmp(a[i], a[left]) <= 0) i++;
               while (j >= left && cmp(a[j], a[left]) > 0) j--;
               if (i < j){
                    swap(&a[i], &a[j]);
               }
          }
          swap(&a[left], &a[j]);
          quick_sort(a, left, j-1);
          quick_sort(a, j+1, right);
     }

 }
 
 void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) )
 { 
     if(left < right){
          int i = left +1;
          int j = right;

          while(i<=j){
               while (i<= right && cmp(a[i], a[left]) <= 0) i++;
               while (j >= left && cmp(a[j], a[left]) > 0) j--;
               if (i < j){
                    swap(&a[i], &a[j]);
               }
          }
          swap(&a[left], &a[j]);
          quick_sort(a, left, j-1);
          quick_sort(a, j+1, right);
     }
 }
 