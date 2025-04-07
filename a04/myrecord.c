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
 // your code
 }
 
 STATS process_data(RECORD *dataset, int count) {    
 // your code
 }
 
 
 int report_data(FILE *fp, RECORD *dataset, STATS stats) {
 // your code
 }
 