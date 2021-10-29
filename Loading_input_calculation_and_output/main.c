//From the standard input, load two integers in the range [-10,000; 10,000], including extreme values.
//If any input value is out of range, print " input is out of range!“to the standard output and exit the program with the return value”0".
//Write out the numbers in decadic and hexadecimal form to the standard output.
//Next, write out the integer sum, the difference and the product of both numbers.
//Write out the integer fraction of both numbers. In the case of division by zero, write " undefined result!”.
//Calculate the average value of both numbers and write it to the standard output with an accuracy of one decimal place.
//Observe the expected formatting, especially spaces and so-called white characters. At the end of the output, there is always the end of the line.
//For simplicity and clarity of the code, the expected return value of the program is always zero (even with incorrect/unexpected input).

#include<stdio.h>
int main() {
    int a, b;

    scanf("%i %i", &a, &b);
    if (a > 10000 || a < -10000 || b > 10000 || b < -10000)
    {
        printf("Vstup je mimo interval!\n");
        return 0;
    }
    printf("Desitkova soustava: %i %i\n", a, b);
    printf("Sestnactkova soustava: %x %x\n", a, b);
    printf("Soucet: %i + %i = %i\n", a, b, a + b);

    printf("Rozdil: %i - %i = %i\n", a, b, a - b);

    printf("Soucin: %i * %i = %i\n", a, b, a * b);
    if (b == 0) {
        printf("Nedefinovany vysledek!\n");
    } else
    {
        printf("Podil: %i / %i = %i\n", a, b, a / b);
    }
    printf("Prumer: %.1f\n", ((a * 1.0) + b) / 2);

    return 0;
}
