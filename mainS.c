#include <stdio.h>
#include "isort.h"


int main()
{
  int i=0;
  int arr[SIZE_ARRAY]={0};
  int num=0;
  for ( i = 0; i < SIZE_ARRAY; i++)
  {
     printf("please enter a number, this number is %d/50 \n",i+1);
      scanf("%d",&num);
      *(arr+i)=num;
  }

  insertion_sort(arr,SIZE_ARRAY);

  for ( i = 0; i < SIZE_ARRAY; i++)
  {
   printf("%d,",*(arr+i));
  }
}