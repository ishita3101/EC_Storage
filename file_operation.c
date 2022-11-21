#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include<stdlib.h>
#include "helper.h"
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>



void put(long int file_ID){

    int segments, i, len, accum;
    char *file_ex;
    char *file_name;
    
    // Declaring Number of chunks
    int no_of_d_chunk = 4;
    int no_of_p_chunk = 3;
    
    // taking file path from user 
    char path[100];
    scanf("%s",path);
    
    // extracting name of file with extension
    file_name = getFileNameFromPath(s,'/');

    // extracting extension of file
    file_ex = getFileNameFromPath(s,'.');

    // extracting name of file without extension
    sscanf(file_name,"%[^.]",file_name);

    
    // calculating file size
    long int file_size = findSize(file_name);
    
    // checking if the file exist or not
    if (file_size != -1)
    {

	    // getting size of each chunk
	    segments = get_chunk_size(file_size/no_of_chunk);
	    
	    
	    int bytesreader;
	    char smallFileName[segments];
	    unsigned char buffer[segments];

	    // Opening the file in read mode
	    int fp1 = open(path, O_RDONLY);
	    if(fp1)
	    {
		for(i=1;i<=(no_of_chunk);i++)
		{
		    if(i==no_of_chunk){
		       segments = (file_size-(segments*(no_of_chunk-1)));
		    }
		    
		    DIR* dir = opendir("EC_Storage");
    
		    if(dir){
		       printf("Dir created");
		    }
		    else{
		       get_folder(int no_of_d_chunk,int no_of_p_chunk);
		    }
		    
		    
		    bytesreader = read(fp1,buffer,segments);
		    sprintf(smallFileName, "EC_Storage/data_chunk_%d/%d_%s_chunk_%d",i,file_ID,file_name,i);
		    
		    
		    // Opening the file in create and write mode
		    int fp2 = open(smallFileName, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
		    
		    write(fp2,buffer,bytesreader);
		    
		    
		    // Closing the file
		    close(fp2);
		    
		}
	    }
      }
      printf("%ld",file_ID);
}


/*void get(){
   char path[20];
   char file[20] = "/file3.txt";
   scanf("%s",path); 
   FILE *fp1 = fopen("/home/dell/ECObjectStorage/file1.txt", "r");
   FILE *fp2 = fopen("/home/dell/ECObjectStorage/file2.txt", "r");
   printf("%s",path);
   strcat(path,file);
   FILE *fp3 = fopen(path, "w");
   char c;
   if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
   {
        puts("Could not open files");
        exit(0);
   }
   while ((c = fgetc(fp1)) != EOF)
   {
    fputc(c, fp3);
   }
   while((c = fgetc(fp2)) != EOF)
   {
        fputc(c,fp3);
   }
   printf("Merged");
 
   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
}*/

