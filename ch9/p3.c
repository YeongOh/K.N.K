#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void) {
	srand((unsigned)time(NULL));
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	char map[N][N];
	generate_random_walk(map);
	int x = 0;
	int y = 0;
	map[0][0] = 'A';

	char curr = 'B';
	while (curr <= 'Z') {
		bool can_go = false;
		bool tried_dir[4] = {false};

		while (can_go == false) {
			int dir = rand() % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (tried_dir[0] && tried_dir[1] && tried_dir[2] && tried_dir[3]) {
				curr = 'Z' + 1;
				break;
			}
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] != '.') {
				tried_dir[dir] = true;
				continue;
			}
			map[ny][nx] = curr;
			y = ny;
			x = nx;
			curr++;
			can_go = true;
		}
	}

	print_array(map);

	return 0;
}

void generate_random_walk(char walk[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			walk[i][j] = '.';
		}
	}
}

void print_array(char walk[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
				printf("%2c", walk[i][j]);
		}
		printf("\n");
	}
}
