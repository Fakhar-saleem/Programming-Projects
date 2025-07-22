from cs50 import get_float

def main():
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            break

    # Convert dollars to cents
    cents = round(dollars * 100)

    # Count the number of coins needed
    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = ((cents % 25) % 10) % 5

    # Calculate the total number of coins
    total_coins = quarters + dimes + nickels + pennies

    print(total_coins)

if __name__ == "__main__":
    main()
