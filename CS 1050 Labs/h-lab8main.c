#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"h-lab8-stringfunc.h"

#define TEST1 "Jim Ries....Is1234Cool"
#define TEST2 "cs1050is great"
#define TEST3 ""
#define TEST4 "!!!#123Once\tThere_was a way\nto^get((back))homeward.123\n"


int main(void){
  char str1[]=TEST1;
  char str2[]=TEST2;
  char str3[]=TEST3;
  char str4[]=TEST4;

  //Print first string
  printf("***Original test string #1: '%s'\n", str1);

  //Test the first string
  toUpperWord(str1, 0);
  printf("After trying word 0: '%s'\n", str1);
  toUpperWord(str1, 3);
  printf("After trying word 3: '%s'\n", str1);
  toUpperWord(str1, 5);
  printf("After trying word 5: '%s'\n", str1);
  toUpperWord(str1, 7);
  printf("After trying word 7: '%s'\n", str1);

  //Get second string
  printf("***Original test string #2: '%s'\n", str2);

  //Test the second string
  toUpperWord(str2, 0);
  printf("After trying word 0: '%s'\n", str2);
  toUpperWord(str2, 3);
  printf("After trying word 3: '%s'\n", str2);
  toUpperWord(str2, 5);
  printf("After trying word 5: '%s'\n", str2);
  toUpperWord(str2, 7);
  printf("After trying word 7: '%s'\n", str2);

  //Get third string
  printf("***Original test string #3: '%s'\n", str3);

  //Test the third string
  toUpperWord(str3, 0);
  printf("After trying word 0: '%s'\n", str3);
  toUpperWord(str3, 3);
  printf("After trying word 3: '%s'\n", str3);
  toUpperWord(str3, 5);
  printf("After trying word 5: '%s'\n", str3);
  toUpperWord(str3, 7);
  printf("After trying word 7: '%s'\n", str3);

  //Get fourth string
  printf("***Original test string #4: '%s'\n", str4);

  //Test the fourth string
  toUpperWord(str4, 0);
  printf("After trying word 0: '%s'\n", str4);
  toUpperWord(str4, 3);
  printf("After trying word 3: '%s'\n", str4);
  toUpperWord(str4, 5);
  printf("After trying word 5: '%s'\n", str4);
  toUpperWord(str4, 7);
  printf("After trying word 7: '%s'\n", str4);
}
