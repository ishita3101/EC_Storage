#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

long int findSize(char file_name[])
{
	// opening the file in read mode
       int fp = open(file_name, O_RDONLY);

	// checking if the file exist or not
	if (fp == -1) {
		printf("File Not Found!\n");
		return -1;
	}

        // Calculating size of file
	long int size = lseek(fp, 0, SEEK_END);

	
	// closing the file
	close(fp);

	return size;
}

int get_chunk_size(float num){

       return num <0?num-0.5:num+0.5;
}

char* getFileNameFromPath(char* path, char c)
    {
       for(size_t i = strlen(path) - 1; i; i--)  
       {
            if (path[i] == c)
            {
                return &path[i+1];
            }
        }
        return path;
    }
    
    
void get_folder(int no_of_d_chunk,int no_of_p_chunk){
        
        char fn[50];
        mkdir("EC_Storage",0777);
        
        for(int i=0;i<no_of_d_chunk;i++){
      	    sprintf(fn, "EC_Storage/data_chunk_%d", i);
            mkdir(fn,0777);
        }
        
        for(int i=0;i<no_of_p_chunk;i++){
      	    sprintf(fn, "EC_Storage/parity_chunk_%d", i);
            mkdir(fn,0777);
        }
             
}
