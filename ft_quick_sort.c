#include "libft.h"
#include <stdio.h>

#define MAX_A 100000

static void	swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int	get_median(int A[], int begin, int end)
{
	int		left = A[begin];
	int		mid = A[(end - 1 - begin) / 2];
	int		right = A[end-1];

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

int			partition(int A[], int begin, int end)
{
	int base;
	int i;
	int j;

	// 3つ要素を取り出して, その中央値を使う
	base = (end - begin - 1) >= 3 ? get_median(A, begin, end) : A[end-1];
	printf("base: %d\n", base);
	i = begin;
	j = begin;
	while (j < end)
	{
		if (A[j] <= base){
			swap(&A[i], &A[j]);
			i++;
		}
		j++;
	}
	return (i);
}

void quick_sort(int A[], int begin, int end)
{
	int mid;

	if (begin < end)
	{
		sleep(1);
		printf("begin: %d, end: %d\n", begin, end);
		mid = partition(A, begin, end);
		printf("mid: %d\n", mid);
		for (int i = 0; i < 12; i++) printf("%d ", A[i]); printf("\n\n");
		quick_sort(A, begin, mid);
		quick_sort(A, mid + 1, end);
	}
}

int main(){
	int A[MAX_A];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	printf("\nbefore partition\n");
	for (int i = 0; i < n; i++) printf ("%d ", A[i]);
	printf("\n");

	/*
	int mid = partition(A, 0, n);

	printf("\nafter partition\n");
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
	*/

	quick_sort(A, 0, n);

	printf("\nafter quick_sort\n");
	for (int i = 0; i < n; i++) printf ("%d ", A[i]);
}
