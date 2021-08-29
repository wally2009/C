/*
Solution for hackerrank time conversion problem. 
https://www.hackerrank.com/challenges/time-conversion/problem
Note that I took the longer way : It uses the maximum number of String Functions. I used such functions as strcpy, strnpy, strtok, strcmp to fix this problem.
There is an easy way to solve write this code. 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* timeConversion(char* s) {
   
    char* str ;
    char* tmp = strtok(s, ":");
    char *t1, *t2, *t3, *t0; 
    char am[4], second[4]; 
    char* result = malloc(sizeof(s)+ 1);
    int i = 0,  hour = 0, hour1 = 0,  hour2 = 0 , l = 0, minute = 0; 
     
    /*Allocating memory to the 3 holders : t1 for hour, t2 for minutes, and t3 for second*/ 
    
    t1 = malloc(8);
    t2 = malloc(8);
    t3 = malloc(8);
    t0 = malloc(8);  
   
   /*This part will give hours, the hour in t1, the minues in t2 and the second with PM/AM in t3*/
    while(tmp != NULL){
        if(i==0){
            strcpy(t1, tmp);
        }else if(i==1){
             strcpy(t2, tmp); 
        }else{
             strcpy(t3, tmp);          
        }
        
        tmp = strtok(NULL, ":");
        
        i++; 
    }
    strncpy(second, t3, 2);
 
/* Retrive AM or PM for the second*/
for(int x = 0 ; x < strlen(t3); x++){
      
        if(x == 2 || x == 3){
        am[l] = t3[x];
         l = l + 1; 
        }
       
    }
   
   /*Hours will be whatever hour is provided in the given time and add 12 to it. 
   hour1 = atoi(t1)+ 12 ;
  // hour = atoi(t1); 
   
   /* Check the different scenario*/ 
    /* First Scenario: from 0-to 11 AM */ 
    if((strcmp(am, "AM") == 0) && (atoi(t1) < 12)){
       int h =  atoi(t1);
      // h = h-12;
       printf("\nh = %d\n", h);
       sprintf(t0, "%02d", h);
       strcpy(result, t0);
       strcat(result, ":");
       strcat(result, t2);
       strcat(result, ":");
       strcat(result, second);
       
    }
      /*check time if it not PM and the given hour is 12*/
   else if((strcmp(am, "PM") != 0) && (atoi(t1) == 12)){
       hour1 = hour1 - 24; 
       printf("hour1 = %02d", hour1);
       sprintf(t1, "%02d", hour1);
       strcpy(result, t1);
       strcat(result, ":");
       strcat(result, t2);
       strcat(result, ":");
       strcat(result, second);
       
      /*Check if time is PM and hour is 12 */
    } else if((strcmp(am, "PM") == 0) && (atoi(t1)==12)){
       hour1 = hour1  - 12;
       printf("hour1 = %02d", hour1);
       sprintf(t1, "%02d", hour1);
       strcpy(result, t1);
       strcat(result, ":");
       strcat(result, t2);
       strcat(result, ":");
       strcat(result, second);
      
    }
    /*This consider the remaining sceneario*/ 
    else{
   sprintf(t1, "%02d", hour1);
   strcpy(result, t1);
   strcat(result, ":");
   strcat(result, t2);
   strcat(result, ":");
   strcat(result, second);

    } 
        

  
    return result; 
}

int main()
{
   char s[11] = "10:20:30PM";
   printf("\nTime to convert : %s\n", s);
   printf("\nConverted time : %s\n", timeConversion(s));
   // timeConversion(s);
    return 0;
}


