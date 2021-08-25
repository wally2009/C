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
   
for(int x = 0 ; x < strlen(t3); x++){
      
        if(x == 2 || x == 3){
        am[l] = t3[x];
         l = l + 1; 
        }
       
    }
   hour1 = atoi(t1)+ 12 ;
   minute = atoi(t2);
  // hour = atoi(t1); 
   
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
   else if((strcmp(am, "PM") != 0) && (atoi(t1) == 12)){
       hour1 = hour1 - 24; 
       printf("hour1 = %02d", hour1);
       sprintf(t1, "%02d", hour1);
       strcpy(result, t1);
       strcat(result, ":");
       strcat(result, t2);
       strcat(result, ":");
       strcat(result, second);
        
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
    
    else{
   sprintf(t1, "%02d", hour1);
   strcpy(result, t1);
   strcat(result, ":");
   strcat(result, t2);
   strcat(result, ":");
   strcat(result, second);

    } 
        
// 
  
    return result; 
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
