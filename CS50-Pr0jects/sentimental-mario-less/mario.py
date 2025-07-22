def main():
    while True:
        height = input("Enter the height of the half-pyramid (between 1 and 8): ")
        if height.isdigit():
            height = int(height)
            if height >= 1 and height <= 8:
                break
        print("Please enter a valid integer within the range of 1 and 8.")

    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)


if __name__ == "__main__":
    main()
