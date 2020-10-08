#include<stdio.h>

void promptString(char* output){
  printf("Please enter a string: ");
  scanf("%s", output);
}

int stringLength(char* chr){
  char* p;
  unsigned int length=0;
  for(p=chr; *p!='\0'; p++){
    length++;
  }
  return (length-1);
}

void swapString(char* string){
  int endIdx = stringLength(string);
  int startIdx = 0;
  char* p = string;

  char hold = *(p+startIdx);
  *(p + startIdx) = *(p + endIdx);
  *(p + endIdx) = hold;
}

int main(void){
  printf("*** Welcome to Prelab 7 ***\n");

  char phrase[256];
  promptString(phrase);
  int length = stringLength(phrase);

  printf("You entered: %s\n", phrase);
  printf("The string is %d in length.\n", length);

  swapString(phrase);

  printf("The switched string is: %s\n", phrase);
  return 0;
}
