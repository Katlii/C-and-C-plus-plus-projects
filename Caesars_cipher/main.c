//In the first example, the text "HelloWorld" is encrypted. The offset here is about 42 letters.
// (16 places are between ' h ' and 'x'; 26 then between lowercase and uppercase letters).
// Thus, the encrypted text is "xubbemehbt".

//The eavesdropped text can be, for example,"??lloworld“,
// where the letters in place of the question mark are badly eavesdropped and we get another random letter, for example,”xylloworld".

//EXAMPLE 2:
//input:                  //output:
//10
//mnoXYhnJLJ              // studentPRP
//JCudvgtXRi

#include <stdio.h>
#include <stdlib.h>

int letters (char b, char *abc);
int strings (char *str, char *help, int l);
int check (char *str, char *abc, int len);
void fix (char *str);

void free_all(char *c, char *string1, char *string2, char *str);

int main (void)
{

    // string lenght
    int l;
#define LEN l+1
    scanf("%d%*[\n]", &l);
    if (l == 0)
    {
        fprintf(stderr, "Error: Chybny vstup!");

        return 100;
    }

    // arrays
    char *c, *string1, *string2, *str;
    c = malloc (l + 1);
    string1 = malloc (l + 1);
    string2 = malloc (l + 1);
    str = malloc (l + 1);

    if (c == NULL || string1 == NULL || string2 == NULL || str == NULL)
    {
        free_all(c,string1,string2,str);
        exit(1);
    }
    char abc[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // we get the first line
    fgets(c, LEN, stdin);   //scanf("%s", c);
    getchar();    //reading the newline character left after entering
    fix(c);

    // check
    int error = check(c, abc, l);
    if (error == 1)
    {
        fprintf(stderr, "Error: Chybny vstup!");
        free_all(c, string1, string2, str);
        return 100;
    }
    if (error == 2)
    {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        free_all(c, string1, string2, str);
        return 101;
    }
    if (error > 0)
    {
        free_all(c, string1, string2, str);
        return error;
    }

    // get 2 newline
    fgets(str, LEN, stdin); //scanf("%s", str);
    getchar();  //reading the newline character left after entering
    fix(str);

    // check
    error = check(str, abc, l);
    if (error == 1)
    {
        fprintf(stderr, "Error: Chybny vstup!");
        free_all(c, string1, string2, str);
        return 100;
    }
    if (error == 2)
    {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        free_all(c, string1, string2, str);
        return 101;
    }
    if (error > 0)
    {
        free_all(c, string1, string2, str);
        return error;
    }

    // decrypt
    int maxk = 0;
    for (int q = 0; abc[q]; q++)
    {
        for (int i = 0; c[i]; i++)
        { string1[i] = abc[(letters(c[i], abc) + q) % 52]; }

        int k = strings(string1, str, l);
        if (k >= maxk)
        {
            maxk = k;
            for (int g = 0; g < l; g++)
            { string2[g] = string1[g]; }
        }
    }


    for (int i = 0; i < l; i++)
    { printf("%c", string2[i]); }
    printf("\n");

    free_all(c, string1, string2, str);
    return 0;
}
// ------------------------------------------------------------
int letters (char b, char *abc)
{
    for (int i = 0; abc[i]; i++)
        if (b == abc[i]) { return i; }
    return -1;
}
// ------------------------------------------------------------
int strings (char *str, char *help, int l)
{
    int count = 0;
    for (int i = 0; i < l - 1; i++)
        if (str[i] == help[i])
        { count++; }
    return count;
}
// ------------------------------------------------------------
int check (char *str, char *abc, int len)
{
    int i;
    for (i = 0; str[i]; i++)
        if (letters(str[i], abc) < 0) { return 1; }
    if (i < len) { return 2; }
    return 0;
}
// ------------------------------------------------------------
void fix (char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n') { str[i] = '\0'; }
}

// ------------------------------------------------------------
void free_all(char *c, char *string1, char *string2, char *str)
{
    free(c);
    free(string1);
    free(string2);
    free(str);
}
