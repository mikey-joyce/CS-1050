#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stringLength(char* chr){
  char* p;
  unsigned int length=0;
  for(p=chr; *p!='\0'; p++){
    length++;
  }
  return (length-1);
}


void toUpperWord(char* str, int n){
  int state = 0;
  int firstIndex=0, lastIndex=0;
  unsigned wordcount = 0;  // word count
  int i=0;

  // Scan all characters one by one
  while(*str)
  {
      // If next character is a separator, set the
      // state as OUT
      if (*str == ' ' || *str == '\n' || *str == '\t' || 0==isalpha(str)){
        state = 0;
        if(wordcount == n){
          lastIndex=i;
        }
      }
      // If next character is not a word separator and
      // state is OUT, then set the state as IN and
      // increment word count
      else if (state == 0)
      {
        state=1;
        ++wordcount;
        //printf("The word count is: %d\n", wordcount);
        if(wordcount == n){
          firstIndex=i;
        }
      }

      //Changes it to uppercase before initial loop is over
      if(lastIndex!=0){
        for(int j=0; j<stringLength(str); j++){
          if(j>=firstIndex && j<lastIndex){
            str[j]=toupper(str[j]);
          }
        }
      }
      ++str;
      ++i;
    }
}
