/*Solution for HackerRank Problem : https://www.hackerrank.com/challenges/apple-and-orange/problem?h_r=next-challenge&h_v=zen */ 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#incluede<stdbool.h>
#include<string.h>

void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    
    apples[apples_count] ; //= malloc(sizeof(int)*apples_count);
    oranges[oranges_count];// = malloc(sizeof(int)*oranges_count); 
     int ac = 0 ;  
     int oc = 0; 
    for(int i = 0; i < apples_count; i++){
        apples[i] = a + apples[i];  
        if((apples[i] >= s) && (apples[i] <= t)){
            ac++; 
        }
    }
    
    for(int j = 0; j < oranges_count; j++){
        oranges[j] = b + oranges[j];
        if((oranges[j] >= s) && (oranges[j] <= t)){  
            oc++; 
        }
    }
        printf("%d\n%d\n", ac, oc);
}
