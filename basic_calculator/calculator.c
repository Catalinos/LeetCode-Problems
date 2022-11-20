#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int parenthesis_length = 0;

int **get_parenthesis_position(char *string_to_calculate)
{

    int columns_begin = 0;
    int columns_end = 0;
    int **parenthesis_positions = (int **)malloc(sizeof(2));

    int stackTop = 0;
    int *stack = (int *)malloc(sizeof(100));

    for (int i = 0; i < 2; ++i)
    {
        parenthesis_positions[i] = (int *)malloc(sizeof(100));
    }

    for (int i = 0; i < strlen(string_to_calculate); ++i)
    {
        if (string_to_calculate[i] == '(')
        {
            stack[stackTop] = i;
            parenthesis_positions[0][columns_begin] = i;
            stackTop++;
            columns_begin++;
            parenthesis_length++;
        }
        if (string_to_calculate[i] == ')')
        {
            stackTop--;
            parenthesis_positions[1][stack[stackTop]] = i;
        }
    }
    free(stack);
    return parenthesis_positions;
}

void printParenthesis(int **parenthesis_positions)
{

    printf("Parenthesis positions are: \n");
    for (int j = 0; j < parenthesis_length; j++)
    {
        printf("no #%d : %d - %d \n", j, parenthesis_positions[0][j], parenthesis_positions[1][j]);
    }
}

int calculate_expression(char *string_to_calculate)
{

    int returned_value = 0;
    int **parenthesis_position;
    parenthesis_position = get_parenthesis_position(string_to_calculate);

    printParenthesis(parenthesis_position);
    free(parenthesis_position);
    return returned_value;
}

int main()
{
    char *string_to_calculate = (char *)malloc(sizeof(100));
    printf("insert basic equation: ");
    scanf("%s", string_to_calculate);
    printf("\nstring to calculate is: %s", string_to_calculate);
    calculate_expression(string_to_calculate);
    free(string_to_calculate);
    return 0;
}