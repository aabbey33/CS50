from cs50 import get_string
import re


def main():
    input_from_user = get_string("Card Number: ")
    user_input = input_from_user[::-1]

    total_mult = int(0)  # Establish a container for our multiplied numbers
    total_unmult = int(0)  # establish a container for our unmultiplied numbers

    if (
        re.match(r"^[0-9]{13}$", user_input)
        or re.match(r"^[0-9]{15}$", user_input)
        or re.match(r"^[0-9]{16}$", user_input)
    ):  # Super long regex to check if the lengths conform and are digits
        for i in range(1, len(user_input), 2):
            to_process = int(user_input[i]) * 2
            if to_process > 9:
                for j in range(2):
                    separated = int(str(to_process)[j])
                    total_mult = total_mult + separated
            else:
                total_mult = total_mult + to_process

        for i in range(0, len(user_input), 2):
            total_unmult = total_unmult + (int(user_input[i]))

        if str((total_mult + total_unmult))[1] == "0":
            print(card_type(str(input_from_user)))
        else:
            print("INVALID")
    else:
        print("INVALID")


def card_type(card):
    mastercard = ["51", "52", "53", "54", "55"]
    amex = ["34", "37"]

    if card[0] == "4":
        return "VISA"
    elif card[:2] in mastercard:
        return "MASTERCARD"
    elif card[:2] in amex:
        return "AMEX"
    else:
        return "INVALID"


main()
