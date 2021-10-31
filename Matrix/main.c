//sum, difference and multiplication of 2 matrices


#include <stdio.h>

int main()
{
    int m, n, p, q, c, d, k, sum = 0;
    //int  multiply[10][10];
    char znak;
    const char* fmt= "%i";
    //printf("Enter number of rows and columns of first matrix\n");

    scanf("%d%d", &m, &n);
    int first[m][n];
    //printf("Enter elements of first matrix\n");
    for (c = 0; c < m; c++) {
        for (d = 0; d < n; d++) {
            if (scanf("%d", &first[c][d]) == 0){
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
        }
    }

    scanf("%s", &znak);
    // printf("Enter number of rows and columns of second matrix\n");
    //printf("Enter elements of second matrix\n");

    scanf("%d%d", &p, &q);
    int second[p][q];
    for (c = 0; c < p; c++)
        for (d = 0; d < q; d++)
            if (scanf("%d", &second[c][d]) == 0){
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }

    switch (znak) {
        case '+' :
            if (m!=p || n!=q) {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            else {
                int multiply[m][n];
                for (c =0; c< m; c++) {
                    for (d=0; d< n; d++) {
                        multiply[c][d]=first[c][d]+second[c][d];
                    }
                }
                printf("%d %d\n", m, n);
                for (c = 0; c < m; c++) {
                    for (d = 0; d < q; d++) {

                        printf(fmt, multiply[c][d]);
                        fmt = " %i";
                    }
                    fmt= "%i";
                    printf("\n");
                }
            }
            break;

        case '-':
            if (m!=p || n!=q) {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            else {
                int multiply[m][n];
                for (c =0; c< m; c++) {
                    for (d=0; d< n; d++) {
                        multiply[c][d]=first[c][d]-second[c][d];

                    }
                }

                printf("%d %d\n", m, n);
                for (c = 0; c < m; c++) {
                    for (d = 0; d < q; d++) {
                        printf(fmt,  multiply[c][d]);
                        fmt = " %i";
                    }
                    fmt = "%i";
                    printf("\n");
                }
            }
            break;

        case '*':
            if (n != p) {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            else {
                int multiply[m][q];
                for (c = 0; c < m; c++) {
                    for (d = 0; d < q; d++) {
                        for (k = 0; k < p; k++) {
                            sum = sum + first[c][k] * second[k][d];
                        }

                        multiply[c][d] = sum;
                        sum = 0;
                    }
                }


                printf("%d %d\n", m, q);
                for (c = 0; c < m; c++) {
                    for (d = 0; d < q; d++) {
                        printf(fmt, multiply[c][d]);
                        fmt = " %i";
                    }
                    fmt = "%i";
                    printf("\n");
                }
            }
            break;
    }

    return 0;
}
