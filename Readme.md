

# Luhn Algorithm for Credit Card Validation
This is a Python & C implementation of the Luhn Algorithm, a simple checksum formula used to validate credit card numbers.

# Requirements

To run this code, you will need:
* Python 3.x

# Usage
To use the Luhn Algorithm, simply call the get_credit_card_number() function and pass in the credit card number as a string:

```python
def get_credit_card_number():
    while True:
        input_str = input("Enter the credit card number: ")  #
        if not input_str.isdigit():
            print("Invalid input. Please enter a positive integer.")               
            continue
        user_input = int(input_str)
        if user_input <= 0:
            print("Invalid input. Please enter a positive integer.")
            continue
        return user_input 
```

# How it works
The Luhn Algorithm works by summing up the digits of the credit card number, starting from the rightmost digit and working backwards. For every other digit, starting with the second-to-last digit, the digit is doubled and the sum of the digits of the resulting number is added to the total sum. Finally, the total sum is divided by 10, and the credit card number is valid if the remainder is 0.
For example, consider the credit card number 4111 1111 1111 1111. Starting from the rightmost digit (which is 1), we add it to the total sum (which is currently 0). Moving to the next digit (which is 1 again), we double it to get 2, and then add the digits of the resulting number (2) to the total sum (which is now 2). Continuing in this manner, we eventually get a total sum of 16. Since 16 is not divisible by 10, the credit card number is not valid.

# Testing

To run the unit tests, simply run the following command:

`python creditcard.py`

This will run a series of tests to verify that the get_credit_card_number() function correctly identifies valid and invalid credit card numbers.

# Contributing

If you find a bug or have a suggestion for how to improve this code, please feel free to open an issue or submit a pull request.

