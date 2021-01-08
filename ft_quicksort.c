#include "libft.h"
#include <stdio.h>

#define MAX_A 100000

static void swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int get_median(int A[], int begin, int end)
{
	int left = A[begin];
	int mid = A[(end - 1 - begin) / 2];
	int right = A[end-1];

	printf("left: %d, mid: %d, right: %d\n", left, mid, right);

	if (left < mid){
	  if (left > right){
		return left;
	  }
	  else if (right > mid){
		return mid;
	  }
	  return right;
	}else{
	  if (left < right){
		return left;
	  }
	  else if (right < mid){
		return mid;
	  }
	  return right;
	}
}

int partition(int A[], int begin, int end)
{
	int base;
	int i;
	int j;

	// 3つ要素を取り出して, その中央値を使う
	base = get_median(A, begin, end);
	printf("base: %d\n", base);
	i = begin - 1;
	j = begin;
	while (j < end)
	{
		if (A[j] <= base){
		  i++;
		  swap(&A[i], &A[j]);
		}
		j++;
	}
	return (i);
}

int main(){
	int A[MAX_A];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	printf("\nbefore partition\n");
	for (int i = 0; i < n; i++) printf ("%d ", A[i]);
	printf("\n");

	int mid = partition(A, 0, n);

	for (int i = 0; i < n; i++){
	  if (i == mid){
		printf("[%d]", A[i]);
	  }else{
		printf("%d", A[i]);
	  }
	  if (i != n - 1)
		printf(" ");
	}
	printf("\n");
}
