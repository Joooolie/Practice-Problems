#include <stdio.h>

int round_to_5(int cents);
void print_change(int cents);
int try_one_coin(int *cents, int coin);

int
main(int argc, char *argv[]) {
	int cents;
	
	printf("Enter amount of money (in cents): ");
	scanf("%d", &cents);
	cents = round_to_5(cents);
	printf("This rounds to %d cents. The change is:\n", cents);
	print_change(cents);
	
	return 0;
}

/* Takes an integer, cents, and returns it rounded to the nearest five */
int round_to_5(int cents) {
	int remainder;
	remainder = cents%5;
	
	if (remainder < 3 ) {
		cents = cents - remainder;
	}
	else if (remainder >= 3) {
		cents = cents + (5 - remainder);
	}
	return cents;
}

/* Prints change for given amount of cents */
void print_change(int cents) {
	int n;
	
	/*Tests how many 50 cent coins fit into the amount*/
	if (cents >= 50) {
		n = try_one_coin(&cents, 50);
		printf("%d x 50 cent coins\n", n);
	}
	
	if (cents >= 20) {
		n = try_one_coin(&cents, 20);
		printf("%d x 20 cent coins\n", n);
	}
	
	if (cents >= 10) {
		n = try_one_coin(&cents, 10);
		printf("%d x 10 cent coins\n", n);
	}
	
	if (cents >= 5) {
		n = try_one_coin(&cents, 5);
		printf("%d x 5 cent coins\n", n);
	}

}


/* Returns the highest number of times, n, the coin given fits into the amount 
   of cents given. Additionally, the function changes the value of cents to 
   reflect the remaining value that could not fit any more of the int coin.*/
int try_one_coin(int *cents, int coin) {
	int n = 0, i = 1;
	if (*cents == 0) {
		n = 0;
	}
	else {
		while ((coin*i) <= *cents) {
			n = i;
			i += 1 ;
		}
		*cents = (*cents - (coin*n));
	}
	return n;
}
