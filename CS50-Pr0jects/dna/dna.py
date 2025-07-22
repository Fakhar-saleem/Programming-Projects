import csv
import sys

def main():
    # Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database_filename = sys.argv[1]
    with open(database_filename, "r") as database_file:
        database_reader = csv.DictReader(database_file)
        database = list(database_reader)[0]  # Convert the CSV into a dictionary

    # Read DNA sequence file into a variable
    sequence_filename = sys.argv[2]
    with open(sequence_filename, "r") as sequence_file:
        dna_sequence = sequence_file.read()

    # Find the longest match of each STR in the DNA sequence
    str_matches = {}
    for str_name in database.keys():
        if str_name != "name":
            str_matches[str_name] = longest_match(dna_sequence, str_name)

    # Check the database for matching profiles
    with open(database_filename, "r") as database_file:
        database_reader = csv.DictReader(database_file)
        for row in database_reader:
            if all(int(row[str_name]) == int(str_matches[str_name]) for str_name in database.keys() if str_name != "name"):
                print(row["name"])
                return

    # If no match is found, print "No match"
    print("No match")

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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
