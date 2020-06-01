#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utf8.h"

#define FILE_NAME "Blocks.txt"

#define LINE_SIZE 10000
#define UTF8_SIZE 7
#define NAME_SIZE 50

typedef struct {
    long count;
    char begin[UTF8_SIZE];
    int begin_d;
    char end  [UTF8_SIZE];
    int end_d;
    char name [NAME_SIZE];

}Language;

static Language ls[300];
int i=0;

int binary_search(unsigned int state){
    int min=0,max=i-1,mid;
    while(max>=min){
        mid=(min+max)/2;
        if(state>ls[mid].begin_d){
            min=mid+1;
        }
        else if(state<ls[mid].begin_d){
            max=mid-1;
        }
        else{
            ls[mid].count++;
            return 0;
        }
    }
    if(state>ls[mid].begin_d){
        ls[mid].count++;
        return 0;
    }
    else
        ls[mid-1].count++;
    return 0;
}

int main() {
    char line[LINE_SIZE];

    FILE *fp=fopen(FILE_NAME,"r");
    if(!fp){
        printf("file \"Blocks.txt\" open failed\n");
        exit(1);
    }
    char *p=NULL;
    char *q=NULL;

    while(!feof(fp)){
        fgets(line,LINE_SIZE,fp);
        if(line[0]=='#'||line[0]==' '||line[0]=='\n')
            continue;
        else{
            if((p=strchr(line,'.'))!=NULL) {
                *p++ = '\0';
                *p++ = '\0';
                strncpy(ls[i].begin, line, UTF8_SIZE);
                q = p;
                if((p = strchr(q, ';'))!=NULL) {
                    *p++ = '\0';
                    while(*p==' ')
                        p++;
                    strncpy(ls[i].end, q, UTF8_SIZE);
                    strncpy(ls[i].name, p, NAME_SIZE);
                    p=ls[i].name;
                    while(*p!='\n')
                        p++;
                    *p='\0';
                    sscanf((char *)&ls[i].begin,"%X",&ls[i].begin_d);
                    sscanf((char *)&ls[i].end,"%X",&ls[i].end_d);
                    ls[i].count=0;
                    i++;
                } else
                    continue;
            }
            else
                continue;
        }
    }
    fclose(fp);
    int state,len;
    int blocks_bl_index=0;
    FILE *fp_2 = stdin;
    if(fp_2){
        while(!feof(fp_2)){
            fgets(line,LINE_SIZE,fp_2);
            p=line;
            while(*p != '\0') {
                state = utf8_to_codepoint((unsigned char*)p, &len);
                if(len) {
                    p += len;
                    binary_search((unsigned int) state);
                }
                else {
                    p++;
                    break;
                }
            }
        }
        for (int j = 1; j <i ; ++j) {
            if(ls[j].count>ls[blocks_bl_index].count){
                blocks_bl_index=j;
            }
        }
        printf("%s\n",ls[blocks_bl_index].name);
    }else{
        printf("failed to open sample file!\n");
        exit(1);
    }
    return 0;
}

