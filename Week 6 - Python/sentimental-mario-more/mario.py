from cs50 import get_int


def main():
    height = get_int("Height: ")

    if height <= 0 or height >= 9:
        main()

    # prints in the order of
    #    # #
    #   ## ##
    #  ### ###
    # #### ####
    for i in range(height):
        count = i + 1
        # build the first structure
        for j in range(height):
            if j < (height - count):
                print(" ", end="")
            else:
                print("#", end="")

        # build the second structure
        print("  ", end="")  # add a whitespace
        for j in range(height):
            if j >= (height - count):
                print("#", end="")

        print()


main()
