#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "linkedlist.h"
#include "textfilewriter.h"

void create_music_titles(FILE* stream){
    char *song_num;

    fgets(song_num, MAX_TITLE_SIZE, stream);

    char title[MAX_TITLE_SIZE];
    for(int i=0; i<atoi(song_num); i++){
        char* music = (char*)malloc(sizeof(char));
        fgets(title, MAX_TITLE_SIZE, stream);
        if(i==atoi(song_num)-1)
            strcpy(music, title);
        else
            strncpy(music, title, strlen(title)-1);
        append_left(MAX_TITLE_SIZE, music);
/*
        while(fgets(title,sizeof(title), fp) != NULL){
            append(sizeof(title),title);
        }*/
    }
    return;
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
        print_file(fp);
    }
    fclose(fp);
    return;
}
