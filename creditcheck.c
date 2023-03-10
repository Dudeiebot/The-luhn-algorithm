#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    long long int user_input;
    int sum = 0, digit_count = 0;   //calling all the necessary function here
    char input[20];

    while (1) {
        printf("Give the required doubted credit card; ");    //checking for character "-" in the input
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        int i = 0;
        while (input[i]) {
            if (!isdigit(input[i])) {
                printf("Invalid input. Please enter a positive integer.\n");  //was not expecting the while loop to be long like these but damn still gonna find a way to relax it muscles
                break;
            }
            i++;
        }
        if (i == 0) {
            continue;
        }
        user_input = atoll(input);
        if (user_input > 0) {
            break;
        }
        else {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
                    //hans peter luhn algorithm for checking the credit card used 
    long long int temp_input = user_input; //OPENED A TEMPORary user_input here cause damn user_input is needed in our while loop first_digit
    while (temp_input > 0) {  
        digit_count++;          //digit_count is used to count the total number of digits in the user_input
        int digit = temp_input % 10;        //modulos needed to get the digit from user_input
        temp_input /= 10;   

        if (digit_count % 2 == 0) {     //the algorithm coming into effect here
            int product = digit * 2;    //digit * 2 is the product of the digits
            sum += (product / 10) + (product % 10); //reverse the digits in product and the sum of the digit of product i.e is why we have modulo of the product
        }
        else {
            sum += digit; //the recycle of the digit in the sum
        }
    }
        //these is another way of life let fvcking move again
    int first_digit = user_input; //practically here we need a better way of printing put the output of our use so these is us finding the first digit that start the nos
    while (first_digit >= 10) {
        first_digit /= 10;
    }

    int first_two_digits = user_input; // as time goes on we will the need the first 2 digit also, so these is us here finding the first two digit of the user input in our program and don't worry our program is memory safe cause we didnot assign out user_input to anything in the program all along
    while (first_two_digits >= 100) {
        first_two_digits /= 10; 
    }

    int second_digit = (sum / 10) % 10; //we need to know maybe our card is valid or not, so we are practically creating a new variable to checksum all our equation in temp_input with the algorithm to check if the ccreditcard is valid

     if (first_digit == 4 && second_digit == 0){
        printf("These credit card is valid and the card issuer is VISA.\n");
    } else if (first_two_digits >= 51 && first_two_digits <=55 && second_digit == 0) {
        printf("These credit card is valid and the card issuer is MASTERCARD.\n");
    } else if ((first_two_digits == 34 || first_two_digits == 37) && second_digit == 0) {               //all these says smae thing 
        printf("These credit card is valid and the card issuer is AMEX.\n");
    } else {
        printf("These credit card is invalid.\n");
    }

    return 0;
}
