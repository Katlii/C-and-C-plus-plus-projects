//From the standard input, use scanf() to load integers in the range [-10,000; 10,000], including extreme values, as long as there is data on it, or until the reading ends with an error.
//Write out all the loaded numbers for yourself, separated by a comma (there is no comma or space after the last number).
//If the loaded number is outside the specified interval, write to the standard output on a new line: "error: the input is outside the interval!"and end the program with a return value of 100. Don't give me any more numbers. Always insert a new line symbol before listing the error.
//Write out the statistics of numbers:
//Number of numbers loaded;
//Number of positive numbers;
//Number of negative numbers;
//Percentage of positive and negative numbers from the input values read, written (rounded by printf ()) to two decimal places;
//Frequency of occurrence of even and odd numbers;
//Percentage of even and odd numbers from the retrieved input values, written to two decimal places;
//Average of loaded numbers;
//Maximum and minimum value.

#include <stdio.h>
#include <limits.h>
int main()
{
    int buff;
    size_t positive = 0, negative = 0, total = 0, sudy=0, lichy=0;
    int maxValue = INT_MIN;
    int minValue = INT_MAX;
    int summ=0, m=0, n=0;
    const char* fmt= "%d";
    while (scanf(" %d", &buff) == 1) {
        ++total;
        buff > 0 ? ++positive : m++; //null is not  positive
        buff < 0 ? ++negative: n++;
        buff %2 ==0 ? ++sudy : ++lichy;
        maxValue = buff > maxValue ? buff : maxValue;
        minValue = buff < minValue ? buff : minValue;
        summ=summ+buff;
        if (buff > 10000 || buff < -10000)
        {
            printf("\n");
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }
        printf(fmt, buff);
        fmt=", %d";
    }
    printf("\n");
    printf("Pocet cisel: %zu\n", total);
    printf("Pocet kladnych: %zu\n", positive);
    printf("Pocet zapornych: %zu\n", negative);
    printf("Procento kladnych: %.2f\n", (float)positive*100 / total);
    printf("Procento zapornych: %.2f\n", (float)negative*100 / total);
    printf("Pocet sudych: %zu\n", sudy);
    printf("Pocet lichych: %zu\n", lichy);
    printf("Procento sudych: %.2f\n", (float)sudy*100 / total);
    printf("Procento lichych: %.2f\n", (float)lichy*100 / total);
    printf("Prumer: %.2f\n", summ*1.0/total);
    printf("Maximum: %d\n", maxValue);
    printf("Minimum: %d\n", minValue);

    return 0;
}
