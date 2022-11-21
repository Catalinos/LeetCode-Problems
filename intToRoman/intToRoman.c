#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertToRoman(int number)
{
    int i = 0;
    char *roman = (char *)malloc(sizeof(100));
    int num[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *sym[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    while (number > 0)
    {
        while (number >= num[i])
        {
            strcat(roman, sym[i]);
            number = number - num[i];
        }
        i++;
    }
    return roman;
}

int main()
{

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    char *final_value = (char *)malloc(sizeof(1000));
    final_value = convertToRoman(number);
    printf("number converted is: %s", final_value);
    return 0;
}