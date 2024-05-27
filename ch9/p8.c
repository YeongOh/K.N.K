#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
	srand((unsigned)time(NULL));

	int wins = 0;
	int losses = 0;
	char response;

	while (1) {
		if (play_game()) {
			printf("You win!\n");
			wins++;
		} else {
			printf("You lose!\n");
			losses++;
		}
		printf("Play again (y/n)?");
		
		while ((response = getchar()) != '\n') {
			if (response == 'y') {
				continue;
			}
			if (response == 'n') {
				printf("Wins: %3d Losses: %3d\n", wins, losses);
				return 0;
			}
		}

	}

	return 0;
}

int roll_dice(void) {
	int dice1 = rand() % 5 + 1;
	int dice2 = rand() % 5 + 1;
	return dice1 + dice2;
}

bool play_game(void) {
	int point = 0;
	while (1) {
		int rolled = roll_dice();
		printf("You rolled: %d\n", rolled);
		if (rolled == 7 || rolled == 11 || rolled == point) {
			return true;
		}
		if (point == 0) {
			point = rolled;
			printf("Your point is %d\n", point);
		}
		if (rolled == 2 || rolled == 3 || rolled == 12) {
			return false;
		}
	}
}
