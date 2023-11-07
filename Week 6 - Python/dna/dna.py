import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = []
    fieldcount = 0
    with open(file=sys.argv[1], mode="r") as file:
        reader = csv.DictReader(file)
        fieldcount = len(reader.fieldnames) - 1  # get number of STR's in the input file
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    sequence = ""
    with open(file=sys.argv[2], mode="r") as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    STRs = [
        "AGATC",
        "TTTTTTCT",
        "AATG",
        "TCTAG",
        "GATA",
        "TATC",
        "GAAA",
        "TCTG",
    ]  # A list of valid STR's that we can check
    profile = (
        {  # A blank template that we can fill in and later cross-check against our DB
            "name": "",
            "AGATC": 0,
            "TTTTTTCT": 0,
            "AATG": 0,
            "TCTAG": 0,
            "GATA": 0,
            "TATC": 0,
            "GAAA": 0,
            "TCTG": 0,
        }
    )
    for i in STRs:
        profile[i] = longest_match(sequence, i)  # Fill in the blanks
    # Check database for matching profiles

    tempcount = 0  # We're setting a temporary counter to 0 as this will serve as our 'checklist'
    for i in database:  # for each person in the database
        tempcount = 0  # We must re-initialize it on every new person
        for j in STRs:  # For every key that is in our valid STR list
            if (
                j in i
            ):  # Check if the STR being iterated upon is in the database to prevent issues with smaller lists
                if int(i[j]) == int(
                    profile[j]
                ):  # If the STR in the DB and our list....
                    tempcount += 1  # Essentially check it off the list
                    if (
                        tempcount == fieldcount
                    ):  # If we've checked off the list as many STR's as in our DB
                        print(f"{i['name']}")  # Then we have a match
                        return  # Break out of the loop and end the function
    if (
        tempcount < fieldcount
    ):  # Otherwise,if we haven't ticked all the boxes, its not a match
        print("No Match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
