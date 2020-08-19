#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n)
{
  int maxSeq = 1;
  int curSeq = 1;
  if (n == 0)
    {
      maxSeq = 0;
      return maxSeq;
    }
  if (n == 1)
    {
      maxSeq = 1;
      return maxSeq;
    }
  for (int i=0; i<n; i++)
    {
      if (*(array + i) < *(array + i+1))
	{
	  curSeq = curSeq + 1;
	}
      else
	{
	  if (curSeq > maxSeq)
	    {
	      maxSeq = curSeq;
	    }
	  curSeq = 1;
	}
    }
  if (curSeq > maxSeq)
    {
      maxSeq = curSeq;
    }
  return maxSeq;
}
