/*
 * file: myrecord_bst.c
 * author: Ramneet Kaur Pannu
 * date: 9/04/25
 */ 

 
 #include <stdio.h>
 #include <math.h>
 #include "bst.h"
 #include "myrecord_bst.h"
 
 void add_record(BSTDS *ds, RECORD record) {
    bst_insert(&ds->root, record);
    ds->count++;

    float oldmean = ds->mean;
    ds->mean = oldmean + (record.score - oldmean) / ds->count;
    if (ds->count > 1) {
        ds->stddev = sqrt(((ds->stddev * ds->stddev * (ds->count - 1)) +
                           (record.score - oldmean) * (record.score - ds->mean)) / ds->count);
    } else {
        ds->stddev = 0.0;
    }
 }
 
 void remove_record(BSTDS *ds, char *name) {
    BSTNODE *node = bst_search(ds->root, name);
    if (node){
        RECORD record = node->data;

        float oldmean = ds->mean;
        bst_delete(&ds->root, name);
        ds->count--;

        if (ds->count > 0){
            ds->mean = oldmean - (record.score - oldmean) / ds->count;
            if (ds->count > 1){
                ds->stddev = sqrt(((ds->stddev * ds->stddev * (ds->count - 1)) +
                (record.score - oldmean) * (record.score - ds->mean)) / ds->count);
            } else {
                ds->stddev = 0.0;
            }
        } else {
            ds->mean = 0.0;
            ds->stddev = 0.0;
        }
    }
  }
 
 void bstds_clean(BSTDS *ds) {
   bst_clean(&ds->root);
   ds->count = 0;
   ds->mean = 0;
   ds->stddev = 0;
 }