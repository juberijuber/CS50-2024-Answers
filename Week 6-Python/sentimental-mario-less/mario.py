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

    # Generate the half-pyramid
    for i in range(1, height + 1):
        # Print spaces followed by hashes
        print(" " * (height - i) + "#" * i)


if __name__ == "__main__":
    main()
