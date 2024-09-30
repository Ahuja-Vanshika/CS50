from cs50 import get_string
import math


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    in_word = False
    for char in text:
        if char.isspace():
            if in_word:
                count += 1
                in_word = False
        else:
            in_word = True
    if in_word:
        count += 1
    return count


def count_sentences(text):
    count = 0
    for char in text:
        if char in '.!?':
            count += 1
    return count


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    l = (letters / words) * 100
    s = (sentences / words) * 100

    index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)

    if index < 1:
        print("Before Grade 1")
    elif 1 <= index < 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


if __name__ == "__main__":
    main()
