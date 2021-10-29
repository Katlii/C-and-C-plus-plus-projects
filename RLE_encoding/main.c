//Rle (run-length encoding) is a lossless compression that encodes input data by encoding sequences of the same values into pairs (sequence length, value). The compression efficiency is strongly dependent on the nature of the input data, which must contain longer sequences of the same characters, otherwise the compression efficiency decreases significantly.

//Example of rle encoder input data:
//WWWWWWWWWWWWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Rle encoding result (not the output of the HW04 solving program, only a demonstration):
//W12B1W12B3W24B1W14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
    int i;
    int z = 0;
    int k = 1;
    int size_str = strlen(str);
    char *compress_str = calloc(size_str + 1, sizeof(char));
    if (size_str < 2) {
        return str;
    }

    for ( i = 0; i < size_str; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            compress_str[z+1] = 0;
            return compress_str;
        }
        if (i == 0) {
            compress_str[z] = str[i];
        } else {
            if (str[i] == str[i-1]) {
                //compress_str[z] = str[i];
                if (  k >= 9 && k < 99) {
                    k++;
                    compress_str[z + 1] = (k / 10) + 48;
                    compress_str[z + 2] =  (k % 10) + 48;
                } else if (k >= 99) {
                    k++;
                    compress_str[z + 1] = (k / 100) + 48;
                    compress_str[z + 2] =  ((k / 10) % 10) + 48;
                    compress_str[z + 3] =  (k % 10) + 48;
                } else {
                    if (i == 1) {
                        if (str[i] != str[i + 1] && str[i] == str[i - 1]) {
                            z++;
                            compress_str[z] = str[i];
                        } else {
                            k++;
                            compress_str[z + 1] = k + 48;
                        }
                    }
                    if (i != 1) {
                        if (str[i] != str[i + 1] && str[i] != str[i - 2]) {
                            z++;
                            compress_str[z] = str[i];
                        } else {
                            k++;
                            compress_str[z + 1] = k + 48;
                        }
                    }
                }
            } else {
                if (k >= 10 && k < 100) {
                    z = z + 3;
                    k = 1;
                    compress_str[z] = str[i];
                } else if  (k >= 100) {
                    z = z + 4;
                    k = 1;
                    compress_str[z] = str[i];
                } else if (k > 1 && k <= 9) {
                    z = z + 2;
                    k = 1;
                    compress_str[z] = str[i];
                } else if (k == 1){
                    z++;
                    compress_str[z] = str[i];
                }
            }
        }
    }
    return compress_str;


}

int main() {
    char *res;
    char *str;
    int i = 0;
    str = (char *) malloc(10240 * sizeof(char));
    scanf("\n%[^\n]", str);
    res = compress(str);

    int count = 0;
    int s, r;
    s = strlen(str);
    r = strlen(res);

    for (i = 0; i < strlen(str); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            count++;

        }
    }
    if (count >= 1) {
        printf("%s", res);
        fprintf(stderr, "Error: Neplatny symbol!\n");
        free(str);
        free(res);
        return 100;
    } else {
        printf("%s\n", res);
        fprintf(stderr, "Pocet vstupnich symbolu: %i\n", s);
        fprintf(stderr, "Pocet zakodovanych symbolu: %i\n", r);
        fprintf(stderr, "Kompresni pomer: %.2f\n", r * 1.0 / s);
    }
    free(str);
    free(res);
    return 0;

}
