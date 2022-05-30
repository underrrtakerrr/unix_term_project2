#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "textfilewriter.h"

void create_music_titles(FILE* stream){
    int num=0;

    fscanf(fp, "%d", &num);

    for(int i=0; i<num; i++){
        char title[MAX_TITLE_SIZE];

        while(fgets(title,sizeof(title), fp) != NULL){
            append(sizeof(title),title);
        }
    }

}

void read_file(char* file_name){
    FILE *fp = fopen(file_name, "r");

    if(fp == NULL){
        printf("File does not exist");
        return;
    }

    else{
        create_music_titles(fp);
    }

}

void write_file(char* file_name){
    FILE *fp = fopen(file_name, "w");

    if(fp == NULL){
        printf("File does not exist");
        return;
    }

    else{
        //linkedlist.c 참고해서 작성
    }

    fclose(fp);
}
