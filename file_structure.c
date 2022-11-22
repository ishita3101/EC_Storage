#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

struct fileinfo
{
    long int unique_id;
    char file_name[20];
    char extension[20];
    int file_size;
    

};

void insert_data(long int unique_id,char *file_name,char *extension,int file_size,struct fileinfo st[],int ind){
    
    st[ind].unique_id = unique_id;
    strcpy(st[ind].file_name,file_name);
    strcpy(st[ind].extension,extension);
    st[ind].file_size = file_size;
    
    
   
}

void clear_struct(struct fileinfo st[]){
     int len = sizeof(struct fileinfo);
     
     for(int i=0;i<len;i++){
            st[i].unique_id = 0;
	    
     }
}

void get_data(struct fileinfo st[]){

    printf("unique_id      file name     extension     filesize\n\n");
    
    int i=0;
    while(st[i].unique_id!=0){
    
       printf("%ld\t\t",st[i].unique_id);
       printf("%s\t\t",st[i].file_name);
       printf("%s\t\t",st[i].extension);
       printf("%d\n",st[i].file_size);
       
       i++;
    }   
}
int main(){
    
    struct fileinfo st[50];
    clear_struct(st);
    
    int i=0;
    while(st[i].unique_id!=0){
       i++;
    }
    insert_data(10001,"sub",".txt",450,st,i);
    
    get_data(st);
    
   
    
    //insert_data(10001,"sub",".txt",450,st);
    //get_data(st[0]);
    
    return 0;
}

