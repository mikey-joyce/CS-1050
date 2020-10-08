#include<stdio.h>

void InitArrayCubed(int array[], int size){
  int temp=0;
  for(int i=0; i<size; i++){
    //cubes all elements of array
    temp = (array[i]*array[i]*array[i]);
    array[i]=temp;
  }
}

void InitArrayTripled(int array[], int size){
  int temp=0;
  for(int i=0; i<size; i++){
    //multiplies all elements of array by 3
    temp = (array[i]*3);
    array[i]=temp;
  }
}

void PrintArray(int array[], int size){
  for(int i=0; i<size; i++){
    //Prints all elements of array
    printf("\t%d\n", array[i]);
  }
}

void SumArrays(int arrayIn1[], int arrayIn2[], int arrayOut[], int size){
  for(int i=0; i<size; i++){
    //adds array1 + array2 elements to end array
    arrayOut[i] = (arrayIn1[i] + arrayIn2[i]);
  }
}

void MultArrays(int array1[], int array2[], int arrayOut[], int size){
  for(int i=0; i<size; i++){
    //multiplies array1 * array2 elements to end array
    arrayOut[i] = (array1[i]*array2[i]);
  }
}

int main(void){
  //Declare my starting arrays and constant
  int LIMIT = 6;
  int array1[LIMIT];
  int array2[LIMIT];
  int arrayOut[LIMIT];
  for(int i=0; i<LIMIT; i++){
    array1[i]=i;
    array2[i]=i;
    arrayOut[i]=0;
  }

  //Change my first array and print it out
  InitArrayCubed(array1, LIMIT);
  printf("Array 1:\n");
  PrintArray(array1, LIMIT);

  //Change my second array and print it out
  InitArrayTripled(array2, LIMIT);
  printf("Array 2:\n");
  PrintArray(array2, LIMIT);

  //Add array 1 and 2
  SumArrays(array1, array2, arrayOut, LIMIT);
  printf("Sum of array1 and array2:\n");
  PrintArray(arrayOut, LIMIT);

  //Multiply array1 and array2
  MultArrays(array1, array2, arrayOut, LIMIT);
  printf("Product of array1 and array2:\n");
  PrintArray(arrayOut, LIMIT);
}
