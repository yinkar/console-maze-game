#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <ctype.h>
#include <time.h>
#define H 50
#define V 15

int main() {
	srand(time(NULL));
	
	int x = 2, y = 3;
	int i, j;
	int z = 0;
	int tx = 40, ty = 5, txn, tyn;
	int crash = 0;
	
	char yon, player = '#', target = '@';
	
	int move(int xd, int yd) {
		char bolum[V][H] = {
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333",
		"\333  \333                         \333       \333\333          \333",
		"\333  \333           \333\333\333\333\333\333\333\333\333\333\333               \333  \333    \333",
		"\333  \333\333\333\333\333\333\333\333\333   \333               \333\333\333\333      \333  \333    \333",
		"\333          \333   \333    \333  \333       \333         \333  \333\333\333\333 \333",
		"\333    \333\333\333\333  \333   \333    \333  \333       \333   \333     \333  \333  \333 \333",
		"\333    \333         \333  \333\333\333  \333       \333\333\333\333\333        \333    \333",
		"\333    \333\333\333\333\333\333\333\333\333\333\333  \333         \333                    \333",
		"\333    \333            \333 \333\333\333\333               \333\333\333   \333   \333",
		"\333    \333\333\333\333\333\333\333\333\333\333\333       \333\333\333\333\333   \333\333\333\333\333\333\333\333\333         \333",
		"\333                 \333\333\333      \333           \333     \333   \333",
		"\333   \333\333\333\333\333\333\333\333\333\333\333        \333\333\333 \333       \333   \333\333\333\333\333     \333",
		"\333             \333   \333\333\333\333\333\333      \333    \333       \333     \333",
		"\333                         \333            \333 \333 \333     \333",
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333"		};
		
		if(bolum[yd][xd] != '\333') {
			system("color 03");
			bolum[yd][xd] = ' ';
			system("CLS");
			bolum[yd][xd] = player;
			bolum[ty][tx] = target;
			
			tyn = (rand() % 10);
			if(tyn < 2) tyn = -1; else if(tyn > 8) tyn = 1; else tyn = 0;
			txn = (rand() % 10);
			if(txn < 2) txn = -1; else if(txn > 8) txn = 1; else txn = 0;
			if(bolum[ty + tyn][tx + txn] != '\333') {
				bolum[ty][tx] = ' ';
				bolum[ty + tyn][tx + txn] = target;					
			}
			
			for(i = 0; i < V; i++) {
				for(j = 0; j < H; j++) {
					printf("%c", bolum[i][j]);
				}
				printf("\n");
			}
			printf("\nx: %d, y: -%d, moves: %d, crashes: %d", xd, yd, z, crash);
				
			if(bolum[yd][xd] == '@') {
				system("CLS");
				return -1;
			}
			return 1;
		}
		else {
			system("color 0c");
			printf("\a");
			move(x, y);
			crash++;
			return 0;
		}
	}
	
	printf("Loading...");

	move(x, y);
	
	while(1) {
		
		if(move(x, y) == -1) {
			break;
		}
		
		yon = _getch();
		yon = tolower(yon);
		
		if(yon == 'a') {
			if(move(x-1, y)) {
				x--;
				z++;
			}
		}
		else if(yon == 'd') {
			if(move(x+1, y)) {
				x++;
				z++;
			}
		}
		else if(yon == 'w') {
			if(move(x, y-1)) {
				y--;
				z++;
			}
		}
		else if(yon == 's') {
			if(move(x, y+1)) {
				y++;
				z++;
			}
		}
		else if(yon == 27) {
			return 0;
		}
	}
	
	system("color 0f");
	printf("You win. Game over. Your moves: %d, Your crashes: %d\n\n", z, crash);
	
	getchar();
}
