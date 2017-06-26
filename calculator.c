
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_LEN 256

int main(void){
    char input[BUFFER_LEN]; // input expression
    char number_string[30];  //store a number string from input
    char op = 0;             // stores an operator
    
    unsigned int index = 0; //  index of the current character in input
    unsigned int to = 0;    // index for copying input to itself
    size_t input_length = 0; // length of the string in input
    unsigned int number_length = 0;  //length of the string in number_string
    double result = 0.0;     // the result of an operation
    double number = 0.0;      // stores the value of number_string
    
    printf("\nTo use this calculator, enter any expression with or without spaces");
    printf("\nAn expression may include the operators:");
    printf("\n +, -, *, /, %% , or ^(raise to a power).");
    printf("\nUse = at the beginning of a line to operate on ");
    printf("\nthe result of the previous calculator.");
    printf("\nUse quit by itself to stop the calculator.\n\n");
    
    /* The main calculator loop */
    while (strcmp(fgets(input, BUFFER_LEN, stdin), "quit\n") != 0) {
        
        input_length = strlen(input);   //Get the input string length
        input[--input_length] = '\0';  // remove newline at the end
        
        /* Remove all spaces from the input by copy the string to itself */
        /* including the string terminating character */
        for (to = 0, index = 0; index <= input_length; index++)
        if (*(input + index) != ' ') {
            *(input + to++) = *(input + index);  //if it is not a space copy it
        }
        
        input_length = strlen(input);   // Get the new string length
        index = 0;                      // Start at the first character
        
        if (input[index] == '=') {      // Is there =?
            index++;                    // Yes so skip over it
        }
        else{                           // No -- look for the left operand
            /* Look for a number that is the left operate for the first operate*/
            /* Check for sign and copy it*/
            number_length = 0;      //Initialize length
            if (input[index] == '+' || input[index] == '-') {          //is it a +-
                *(number_string + number_length++) = *(input+index++); //copy it
            }
            
            /* Copy all following digits*/
            for ( ; isdigit(*(input+index)); index++) {                 //is it a digit
                *(number_string + number_length++) = *(input + index);//copy it
            }
            
            /* Copy any fractional part*/
            if (*(input+ index) == '.') {                   //is it a decimal point?
                *(number_string + number_length++) = *(input + index++); // copy it
                
                for ( ; isdigit(*(input+index)); index++) {  //for each digit
                    *(number_string + number_length++) = *(input + index);//copy it
                }
            }
            *(number_string + number_length) = '\0';  // append string terminator
            
            /* If we have a left operand, the length of number_string will be > 0. */
            /* In this case convert to a double so we can use it in the calculator */
            if (number_length > 0) {
                result = atof(number_string);  // Store first number as result
            }
        }
            
        /* Now look for 'op number' combinations */
        for ( ; index < input_length; ) {
            op = *(input + index++);     // Get the operator
            /* copy the next operand and store it in number */
            number_length = 0;
                
            /* Check for sign and copy it */
            if (input[index] == '+' || input[index] == '-') {
                *(number_string + number_length++) = *(input + index++);
            }
            for ( ; isdigit(*(input+index)); index++) {
                *(number_string + number_length++) = *(input + index);
            }
            /* Copy any fractional part */
            if (*(input + index) == '.') {
                *(number_string + number_length++) = *(input + index++);
                for ( ; isdigit(*(input+index)); index++) {
                    *(number_string + number_length++) = *(input + index);
                }
            }
            *(number_string + number_length) = '\0';
            
            number = atof(number_string);
                
            /* Execute operation, as 'result op = number' */
            switch (op) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    if(number == 0)
                        printf("\n\n\aDivision by zero error!\n");
                    result /=number;
                    break;
                case '%':
                    if ((long)number == 0) {
                        printf("\n\n\aDivision by zero error!\n");
                    }
                    else
                        result = (double)((long)result % (long)number);
                    break;
                case '^':
                    result = pow(result, number);
                    break;
                default:
                    printf("\n\n\aIllegal operation!\n");
                    break;
            }
        }
            
            
        /* Code to analyze the operator and right operand */
            
        
        printf("= %f\n", result);
        /* Code to implement the calculator*/
    }
    
    return 0;
}
