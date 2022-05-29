#include <stdio.h>

#define MAX_TITLE_SIZE 50
/*
void create_music_titles(FILE* stream){

}
 첫 번째 줄에 재생 목록에 추가할 노래의 개수 N이 주어진다. (1<=N<=10)

두 번째 줄부터 N 개의 노래명이 주어진다.

N+2 번째 줄에 명령어의 개수 M 이 주어진다. (1<=M<=50)

N+3 번째 줄부터 M 개의 명령어가 주어진다.
 */
int read_file(char* file_name){
    int n, m;
    char name[100];
    char command[100];

    FILE *fp = fopen("read.txt", "r");

    if(fp == NULL){
        return 0;
    }

    n = fgetc(fp);
    for(int i=0; i<n; i++){
        fgets(name, 100, fp);
    }

    m = fgetc(fp);
    for(int i=0; i<m; i++){
        fgets(command, 100, fp);
    }

    fclose(fp);
    return 0;
}

void write_file(char* file_name){
    FILE *fp = fopen("write.txt", "w");

    fclose(fp);
}
