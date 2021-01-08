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

int partition(int A[], int p, int r)
{
	int base;
	int i;
	int j;

	// 3つ要素を取り出して, その中央値を使う
	base = A[r];
	i = p - 1;
	j = p;
	while (j < r)
	{
		if (A[j] <= base){
		  i++;
		  swap(&A[i], &A[j]);
		}
		j++;
	}
	swap(&A[i+1], &A[r]);
	return (i + 1);
}

int main(){
	int A[MAX_A];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	// printf("\nbefore partition\n");
	// for (int i = 0; i < n; i++) printf ("%d ", A[i]);
	// printf("\n");

	int q = partition(A, 0, n-1);

	for (int i = 0; i < n; i++){
	  if (i == q){
		printf("[%d]", A[i]);
	  }else{
		printf("%d", A[i]);
	  }
	  if (i != n - 1)
		printf(" ");
	}
	printf("\n");
}
