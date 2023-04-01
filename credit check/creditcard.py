'''
So here we practically trying to figure out a fraud credit card or maybe a program used to check  your credit card at an automatic teller machine 
These particular algorithm uses the algorithm invented by Hans Peter Luhn of IBM and have proof to be efficient.
* so for the beginning if your credit card does not have 2fa then i will tell you to be careful in inputtiny your credit card number on the program but another thing you should be aware of is that i am not storing your credit card number in any DB and these is open source also.
* so i will not be able to know your credit card number when inputted or being checked for validation on the code and as a developer you can tweak anything you want on these but these is not for everyone 
also as time goes on i will probably to get a frontend on it but fot now just the algorithm is available.
'''
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

def calculate_luhn(card_number):      #calaculate_luhn here is used for calculating the luhn algorithm, and you can make more research regarding the algorithm, the algorithm haves a lot of mathematics attached to it also with selecting of the credit card number digit individually and performing a certain operation on it and returning a certain results.
    digit_count = 0
    luhn_sum = 0
    while card_number > 0:
        digit_count += 1
        digit = card_number % 10
        card_number //= 10

        if digit_count % 2 == 0:
            product = digit * 2
            luhn_sum += (product // 10) + (product % 10)
        else:
            luhn_sum += digit   
       
    return luhn_sum

def get_card_issuer(card_number):       #so i am practically not ending it here but i am going to try to figure out the issuer of the credit card also, it can be more easy or more complicated depending on if our card issuer amend their defaults starting number or second number defaults
                                        #but you can also make your own tweak any new changes you want on the code and see how it works.
    first_digit = card_number
    while first_digit >= 10:
        first_digit //= 10

    first_two_digits = card_number
    while first_two_digits >= 100:
        first_two_digits //= 10
    
    second_digit = calculate_luhn(card_number)
    if len(str(second_digit)) > 1 and str(second_digit)[1] == "0":
        print("The card is valid", end = " ")
    else:
        print("The card is invalid", end = " ")
    

    if first_digit == 4:
        return "VISA"
    elif first_two_digits >= 51 and first_two_digits <= 55:
        return "MASTERCARD"
    elif first_two_digits in [34, 37]:
        return "AMEX"


credit_card_number = get_credit_card_number()
issuer = get_card_issuer(credit_card_number)
print(f"and issued by {issuer}", end="")
