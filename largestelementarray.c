#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
 {
 	int n, i, *arr, max = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
 
    // if memory cannot be allocated
    if(arr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

  printf("Enter the array elements: ");
  
  // taking input and storing it in an array
  for(i = 0; i < n; ++i)
  {
     scanf("%d",arr+i);
  }
   
   
	for (i = 1; i < n; ++i)
	 {
        if (*arr < *(arr + i))
            *arr = *(arr + i);
	}
   printf("\nLargest element=%d", *arr);
   free(arr);
  return 0;
}

