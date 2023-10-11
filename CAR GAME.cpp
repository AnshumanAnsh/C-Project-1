#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

struct car {
    int x;
    int y;
};

struct car player;
struct car obstacles[5];
int score = 0;

void init() {
    player.x = WIDTH / 2;
    player.y = HEIGHT - 1;

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        obstacles[i].x = rand() % WIDTH;
        obstacles[i].y = -(rand() % HEIGHT);
    }
}

void draw() {
    system("cls"); // Clear the console

    // Draw top border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Draw game area
    for (int i = 0; i < HEIGHT; i++) {
        printf("#");
        for (int j = 0; j < WIDTH; j++) {
            if (i == player.y && j == player.x) {
                printf("A"); // Draw player car
            } else {
                int k;
                for (k = 0; k < 5; k++) {
                    if (i == obstacles[k].y && j == obstacles[k].x) {
                        printf("X"); // Draw obstacle car
                        break;
                    }
                }
                if (k == 5) {
                    printf(" "); // Draw empty space
                }
            }
        }
        printf("#\n");
    }

    // Draw bottom border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Draw score
    printf("Score: %d\n", score);
}

void update() {
    // Move the player car
    if (kbhit()) {
        switch (getch()) {
            case 'a':
                if (player.x > 0) player.x--;
                break;
            case 'd':
                if (player.x < WIDTH - 1) player.x++;
                break;
        }
    }

    // Move the obstacle cars
    for (int i = 0; i < 5; i++) {
        obstacles[i].y++;
        if (obstacles[i].y >= HEIGHT) {
            obstacles[i].x = rand() % WIDTH;
            obstacles[i].y = -(rand() % HEIGHT);
            score++;
        }
    }

    // Check for collision with obstacles
    for (int i = 0; i < 5; i++) {
        if (player.x == obstacles[i].x && player.y == obstacles[i].y) {
            printf("Game Over\n");
            exit(0);
        }
    }
}

int main() {
    init();

    while (1) {
        draw();
        update();
    }

    return 0;
}

