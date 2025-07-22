from cs50 import get_string

def main():
    text = get_string("Text: ")

    # Count the number of letters, words, and sentences
    num_letters = count_letters(text)
    num_words = count_words(text)
    num_sentences = count_sentences(text)

    # Calculate the average number of letters and sentences per 100 words
    L = (num_letters / num_words) * 100
    S = (num_sentences / num_words) * 100

    # Calculate the Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Round the index to the nearest integer
    grade = round(index)

    # Print the grade level
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

def count_letters(text):
    return sum(1 for char in text if char.isalpha())

def count_words(text):
    return len(text.split())

def count_sentences(text):
    # Assume any period, exclamation point, or question mark indicates the end of a sentence
    return sum(1 for char in text if char in ['.', '!', '?'])

if __name__ == "__main__":
    main()
