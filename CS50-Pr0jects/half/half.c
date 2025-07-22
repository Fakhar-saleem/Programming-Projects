// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float dec_tax=(tax*bill)/100;
    float bill_tax=bill+dec_tax;
    float dec_tip=(tip*bill_tax)/100;
    float total=bill+dec_tax+dec_tip;
    float each_bill=total/2;

    return each_bill;
}
