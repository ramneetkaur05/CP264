/*
 * file: myrecord.c
 * author: Ramneet Kaur Pannu
 * date: 7/04/25
 */ 
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "myrecord.h"
 #include "mysort.h"
 
 GRADE grade(float score){
    GRADE r = {"F"}; 
    if (score > 90) strcpy(r.letter_grade, "A+");
    else if (score > 85 && score <= 90) strcpy(r.letter_grade, "A");
    else if (score > 80 && score <= 85) strcpy(r.letter_grade, "A-");
    else if (score > 77 && score <= 80) strcpy(r.letter_grade, "B+");
    else if (score > 73 && score <= 77) strcpy(r.letter_grade, "B");
    else if (score > 70 && score <= 73) strcpy(r.letter_grade, "B-");
    else if (score > 67 && score <= 70) strcpy(r.letter_grade, "C+");
    else if (score > 63 && score <= 67) strcpy(r.letter_grade, "C");
    else if (score > 60 && score <= 63) strcpy(r.letter_grade, "C-");
    else if (score > 57 && score <= 60) strcpy(r.letter_grade, "D+");
    else if (score > 53 && score <= 57) strcpy(r.letter_grade, "D");
    else if (score > 50 && score <= 53) strcpy(r.letter_grade, "D-");
    else if (score > 0 && score <= 50) strcpy(r.letter_grade, "F");
    return r;   
 }
 
 int import_data(FILE *fp, RECORD *dataset) {

   int count = 0;
   while (fscanf(fp, "%s %f", &dataset[count].name && &dataset[count].score == 2 )){
      count ++;

   }
   return count;
 }
 
 STATS process_data(RECORD *dataset, int count) {    

   float total = 0;
   STATS stats; //initialize stats
   stats.count = count;
   stats.mean = 0;
   stats.median = 0;
   stats.stddev = 0;

   float *scores = (float*)malloc(count * sizeof(float));

   for(int i = 0; i < count; i++){
      total += dataset[i].score; // add up all the scores
      scores[i] = dataset[i].score;
   }

   stats.mean = total /count; // calc. the mean
   
   select_sort((void*)scores, 0,count-1);
   if(count % 2 == 0){
      stats.median = (scores[count/2-1] + scores[count/2])/2; //mean if theres an even number of scores
   } else {
      stats.median = scores[count/2]; // mena if theres an odd number of scores
   }

   float sum2 = 0;
   for(int i = 0; i < count; i++){
      sum2 += pow(scores[i] - stats.mean, 2); //standard deviation^2
   }
   stats.stddev = sqrt(sum2/count); // standard deviation
   free(scores);
   return stats;

}
 
 
 int report_data(FILE *fp, RECORD *dataset, STATS stats) {
 // your code
 }
 