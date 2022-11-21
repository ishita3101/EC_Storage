#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "file_operation.h"

int main(){

      while (1) {
      
      printf("ObjStorage >");
      
      // to read command line with arguments
      char cmd[20];
      scanf("%s", cmd);
      
      // getting unique_ID
      int unique_ID = 10000;
      
      if (strcmp(cmd,"put")==0){
          put(unique_ID);
          unique_ID++;
      	  break;
      }
      else if (strcmp(cmd,"get")==0){
          //get();
          break;
      }
      else if (strcmp(cmd,"list")==0){
          break;
      }
      else if (strcmp(cmd,"quit")==0){
          exit(0);
      }
      
      printf("\n");
      }     
      
      return 0;
}

