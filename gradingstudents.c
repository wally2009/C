/* This is a hackerrank solution to the following problem https://www.hackerrank.com/challenges/grading/problem*/ 

/*Problem Statement */ 

/*
  HackerLand University has the following grading policy:

  Every student receives a  in the inclusive range from  to .
  Any  less than  is a failing grade.
  Sam is a professor at the university and likes to round each student's  according to these rules:

  If the difference between the  and the next multiple of  is less than , round  up to the next multiple of .
  If the value of  is less than , no rounding occurs as the result will still be a failing grade.
  Examples

   round to  (85 - 84 is less than 3)
   do not round (result is less than 40)
   do not round (60 - 57 is 3 or higher)
  Given the initial value of  for each of Sam's  students, write code to automate the rounding process


*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>


int* gradingStudents(int grades_count, int* grades, int* result_count) {
    
   //grades = malloc(sizeof(int)* grades_count); 
    *(result_count)=0;
   // result_count = arr;
   
   int *a = malloc(sizeof(int)*grades_count);
    
   
    int r = 0; 
    int d = 0 ; 
    for(int i = 0; i < grades_count; i++){
        r = grades[i]/5 ;   
       /// printf("%r") 
        r++; 
        d = r*5; 
       // printf("\nd = %d\n", d);
    
        if( (d - grades[i] == 3) || (d - grades[i] > 3) || (grades[i] < 38)){    
            a[i]  = grades[i];
        }else {
           a[i]  = d; 
        }

        (*result_count)++; 
    }
    
    
    
        return a; //result_count  ; 

}

int main()
{
   
    int result_count;
    
    int grades[] = {10, 53, 75, 39}
    
    int* result = gradingStudents(grades_count, grades, &result_count);
    for(int = 0 ; i < result_count; i++){
    
      printf("%d", result[i]); 
    }

    return 0;
}

