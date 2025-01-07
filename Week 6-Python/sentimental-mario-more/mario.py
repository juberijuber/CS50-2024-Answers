# mario.py
def main():
    # Prompt user for the height of the pyramid
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                break
        except ValueError:
            continue

    # Generate the pyramid
    for i in range(1, height + 1):
        # Print spaces on the left
        print(" " * (height - i), end="")
        # Print the left hashes
        print("#" * i, end="")
        # Print the gap
        print("  ", end="")
        # Print the right hashes
        print("#" * i)


if __name__ == "__main__":
    main()
