from cs50 import get_string


def main():
    """
    Coleman-Liau index is computed as
    0.0588 * L - 0.296 * S - 15.8
    where L is the average number of letters
    per 100 words in the text, and S is the
    average number of sentences per 100 words in the text.
    """

    text = get_string("Text: ")

    lettercount = count_letters(text)
    wordcount = len(text.split(" "))
    sentencecount = text.count(".") + text.count("!") + text.count("?")

    L = lettercount / wordcount * 100
    S = sentencecount / wordcount * 100

    gradescore = 0.0588 * L - 0.296 * S - 15.8

    gradescore = round(gradescore)

    if gradescore > 16:
        print("Grade 16+")
    elif gradescore < 1:
        print("Before grade 1")
    else:
        print(f"Grade {gradescore}")


def count_letters(text):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count += 1
    return count


main()
