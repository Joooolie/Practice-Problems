#include <stdio.h>

int
main(int argc, char *argv[]) {
	int star, i =0;
	printf("Enter numbers, ctrl-D to end: ");
	while (scanf("%d", &star) == 1) {
		printf("\n%d |", star);
		while (i < (star)) {
			printf("*");
			i +=1;
		}
		printf("\n");
		i = 0;
	}
	
	return 0;
}