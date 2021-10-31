//TASK 1:      Load one number and "plot" to the standard output a square
//TASK 2:      Load two numbers and "plot" to the standard output the house.
//The first number indicates the width of the house, the second the height of the house.
//The first number representing the width must always be odd.
//    If this is not the case, write the following error message to the standard error output: "error: match neni liche numero!",
//    in this case, the return value of the program is 102.
//If the width and height are the same, the square is filled with the characters ' o 'and '*',
// while in the upper left corner there is always the character ' o ' and the characters form a chessboard.
//    If the width and height are not the same, a space is printed instead of a fill.
//TASK 3:      Plot the fence to the house.
//The size of the fence must be positive and sharply less than the height of the house.
// In the event that this is not the case, notify the user with a message to the standard error output in the wording: "error: Invalid fence size!"and end the program with a return value of 103.
//The horizontal sections of the fence are always on the first and last rows of the fence. The right part of the fence always ends with a vertical fence, so the first row of the fence looks like this for size 2:" -|”, for size 3: “|-|” and for size 4:“ -| -|”, etc.
//The height of the fence is the same as its width (- /are two characters)


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MIN_INPUT 3
#define MAX_INPUT 69
#define MIN_NUM_OF_INPUT 1

#define true 1
#define false 0
typedef int bool;

bool isNumber(char c[]);
int convertToInt(char c[]);


int main(){
    int width = -1;
    int height = -1;
    int wall = -1;
    int data_input = 0;
    _Bool isOne = false;
    int range[] = {3, 69};

    char str[100];
    char numbers[3][10];

    strcpy(numbers[0], "");
    strcpy(numbers[1], "");
    strcpy(numbers[2], "");

    fgets(str, sizeof(str), stdin);

    char * pch;
    pch = strtok (str," ");
    while (pch != NULL)
    {
        if (data_input > 2)
            break;

        if (*pch == '\n')
            break;

        strcpy(numbers[data_input], pch);
        data_input++;
        pch = strtok (NULL, " ");
    }

    if (strlen(numbers[0]) != 0) {
        if (isNumber(numbers[0]) == 1) {
            width = convertToInt(numbers[0]);
        } else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }

    if (strlen(numbers[1]) != 0) {
        if (isNumber(numbers[1]) == 1) {
            height = convertToInt(numbers[1]);
        } else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }

    if (strlen(numbers[2]) != 0) {
        if (isNumber(numbers[2]) == 1) {
            wall = convertToInt(numbers[2]);
            // printf("Wall: %d", wall);
        } else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }

    if (data_input < MIN_NUM_OF_INPUT){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    if (data_input == 1)
        if (width < range[0] || width > range[1]) {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }

    if (data_input == 2)
        if (height < range[0] || height > range[1]) {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }

    if (data_input == 3)
        if (wall < range[0] || wall > range[1]) {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }

    if (data_input == 1) {
        height = width;
        isOne = true;
    }

    if (width % 2 == 0 && data_input > 1) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }

    if (wall > height) {
        fprintf(stderr, "Error: Neplatna velikost plotu!\n");
        return 103;
    }

    // ROOF OF THE HOUSE
    if (!isOne) {
        int rows = width / 2;
        for (int i = 0; i < rows; i++) {
            for (int j = rows - i; j > 0; j--) {
                printf(" ");
            }
            for (int j = i * 2; j >= 0; j--) {
                if (j == i * 2 || j == 0)
                    printf("X");
                else
                    printf(" ");
            }
            // for (int j = rows - i; j > 0; j--) {
            //     printf(" ");
            // }
            printf("\n");
        }
    }

    //BODY OF THE HOUSE
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Края дома
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1) {

                // Заполняем внутренности дома
                if (!isOne && width == height) {
                    if ((i + j) % 2 == 0)
                        printf("o");
                    else
                        printf("*");
                } else {
                    printf(" ");
                }

            } else {
                printf("X");
            }

            // FANCE
            if (i >= height - wall && j >= width - 1) {
                for (int c = 0; c < wall; c++) {
                    if (wall % 2 == 0) {
                        if (c % 2 == 0) {
                            if (i == height - wall || i == height - 1) {
                                printf("-");
                            } else {
                                printf(" ");
                            }
                        } else {
                            printf("|");
                        }
                    } else {
                        if (c % 2 != 0) {
                            if (i == height - wall || i == height - 1) {
                                printf("-");
                            } else {
                                printf(" ");
                            }
                        } else {
                            printf("|");
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}

bool isNumber(char c[]) {
    int check = convertToInt(c);
    if (check == 0 && *c != '0') {
        return false;
    }

    return true;
}

int convertToInt(char c[]) {
    int n = atoi(c);
    return n;
}
