#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXIMUM 1000 //Array size 1000

typedef struct{
    int RANDOMID;
    float RANDOM_PRICE;
}RANDOM_STUFF;

int main(void) {
    int i;
    int num;
    //declare an array of type RANDOM_STUFF.below declaration creates the array on stack.
    RANDOM_STUFF ARRAY_RAND[MAXIMUM];
    //declare pointer to array of struct to create array on heap
    RANDOM_STUFF *ARRAY_POINTER;
    //populating 10 elements with some random numbers
    srand((unsigned)time(NULL));
    for(i = 0; i <10; i++){
           ARRAY_RAND[i].RANDOMID = rand()%600+30;
           num = rand()%5+3;
           if(num < 5)
               ARRAY_RAND[i].RANDOM_PRICE = num+(num)/1000.0;
           else
               ARRAY_RAND[i].RANDOM_PRICE = num;
    }
    //print the array on stack
    printf("**********************************************\n");
    printf("CONTENT OF ARRAY ON STACK: \n");
    for(i = 0; i <10; i++){
           printf("RANDOM_PRODUCTS:%d , RANDOM_QUALITY:%.2f\n",ARRAY_RAND[i].RANDOMID,ARRAY_RAND[i].RANDOM_PRICE);
       } printf("\n");
    //allocate array on heap using malloc
    ARRAY_POINTER = (RANDOM_STUFF*)malloc(1000*sizeof(RANDOM_STUFF));
    //copy from ARRAY_RAND to ARRAY_POINTER
    for(i = 0; i < 10; i++){
           ARRAY_POINTER[i]=ARRAY_RAND[i];
       }//display the ARRAY_POINTER
    printf("**********************************************\n");
    printf("CONTENT OF ARRAY ON HEAP: \n");
    for(i = 0; i <10; i++){
           printf("RANDOMID:%d , RANDOM_PRICE:%.2f\n",ARRAY_POINTER[i].RANDOMID,ARRAY_POINTER[i].RANDOM_PRICE);
       }printf("\n");

    return 0;
}