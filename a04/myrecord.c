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

   char line[100];
   int i = 0; //records counter

   while(fgets(line,sizeof(line),fp) != NULL){
      // use sscanf() get name string to dataset[i].name, float score to dataset[i].score
      sscanf(line, "[^, ],%f", dataset[i].name, &dataset[i].score);
      i++;
   }
   return i;


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
      sum2 += (scores[i] - stats.mean)*(scores[i] - stats.mean); //variance
   }
   stats.stddev = sqrt(sum2 / count); // standard deviation
   free(scores);
   return stats;

}

static int cmp1(void *x, void *y) {
   float b = ((RECORD*) x)->score;
   float a = ((RECORD*) y)->score;
   if (a > b) return 1;
   else if (a < b) return -1;
   else return 0;
   }
 
 
 int report_data(FILE *fp, RECORD *dataset, STATS stats) {

   int n = stats.count;
   if (n<1) return 0;

   RECORD *p[n];
   for (int i=0; i<n; i++){
      p[i] = &dataset[i];
   }

   my_sort((void*)p, 0, n-1, cmp1);
   for (int i = 0; i < n; i++) {
      // write to file the record data by pointer p[i],
      fprintf(fp, "%s:%.1f,%s\n", 
         p[i]->name, 
         p[i]->score,
         grade(p[i]->score).letter_grade);
      }
   
   return 1;

  }
 