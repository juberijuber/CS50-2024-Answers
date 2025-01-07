import csv
import sys


def main():
    # Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames[1:]  # Get STR names (excluding 'name' column)
        for row in reader:
            # Convert STR counts from strings to integers
            for str_name in strs:
                row[str_name] = int(row[str_name])
            database.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read().strip()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_name in strs:
        str_counts[str_name] = longest_match(sequence, str_name)

    # Check database for matching profiles
    for person in database:
        match = True
        for str_name in strs:
            if person[str_name] != str_counts[str_name]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each position in sequence for a subsequence match
    for i in range(sequence_length):
        count = 0
        # Look for direct repeats of subsequence starting at position i
        while True:
            # Extract a substring of length subsequence_length starting from position i + (count * subsequence_length)
            start = i + (count * subsequence_length)
            end = start + subsequence_length

            # If we've reached the end of the sequence, break
            if end > sequence_length:
                break

            # If we find a match, increment count and keep looking
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        # Update longest_run if we found a longer run
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
