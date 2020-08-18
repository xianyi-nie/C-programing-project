#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void)
{
  int array1[] = {1,3,110,5,90,5,9,10,11};  
  int array2[] = {0,0};
  int array3[] = {25,26,26,27,14};
  int array4[] = {-2,-1,0,1,4,5};
  int array5[] = {25,12,28};
  int array6[] = {};
  int array7[] = {5,4,-4,-3,-2,-1,1};      
  if (maxSeq(array1,9) != 4)
    return EXIT_FAILURE;     
  if (maxSeq(array2,2) != 1)
    return EXIT_FAILURE; 
  if (maxSeq(array3,5) != 2)
    return EXIT_FAILURE;    
  if (maxSeq(array4,6) != 6)
    return EXIT_FAILURE;
  if (maxSeq(array5,3) != 2)
    return EXIT_FAILURE;
  if (maxSeq(array6,0) != 0)
    return EXIT_FAILURE;    
  if (maxSeq(array7,7) != 5)
    return EXIT_FAILURE;    
  return EXIT_SUCCESS;
}
