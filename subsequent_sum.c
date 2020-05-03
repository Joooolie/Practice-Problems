#include <stdio.h>
#include <stdlib.h>

/* Given an integer n, you need to find how many ways 
we can add up two or more subsequent natural numbers 
leading up to n, that sum up to n. return HOW MANY ways.
Ex: n=5, 2+3,
*/

void print_seq(int i, int j);

int main(int argc, char const *argv[])
{
	int n = 100;
	int i=0, j=0;
	int curr_sum = 0;
	int num_ways = 0;
	int max = 0;

	if (n%2 == 0){
		max = n/2;
	} else {
		max = n/2 + 1;
	}

	for (i=1; i < max; i++) {
		j = i;
		while (curr_sum < n) {
			curr_sum += j;
			j++;
		}
		if (curr_sum == n) {
			num_ways +=1;
			print_seq(i, j);
		} 
		curr_sum = 0;
	}

	printf("There are %d ways to do %d\n", num_ways, n);

	return 0;
}

void print_seq(int i, int j) {
	int k=0;
	puts("The sequence is: ");

	for (k=i;k<j;k++){
		printf("%d, ", k);
	}
	puts("");
}
