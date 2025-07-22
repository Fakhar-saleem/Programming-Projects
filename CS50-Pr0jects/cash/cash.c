#include <stdio.h>

void makeChange(int amount) {
    int quarters, dimes, nickels, pennies, total;

    quarters = amount / 25;
    amount = amount % 25;

    dimes = amount / 10;
    amount = amount % 10;

    nickels = amount / 5;
    amount = amount % 5;

    pennies = amount;

    total = quarters + dimes + nickels + pennies;

    printf("%d\n", total);
}

int main() {
    int amount;

    printf("Enter the amount of change in cents: ");
    while (scanf("%d", &amount) != 1 || amount < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        while (getchar() != '\n'); // Clear input buffer
        printf("Enter the amount of change in cents: ");
    }

    makeChange(amount);

    return 0;
}