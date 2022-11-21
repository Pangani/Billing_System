#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * generateBillHeader - function for header of a voucher
 * @name: name of the customer
 * @date: day voucher created
 * Return: nothing
*/
void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
        printf("\t ADV. Restaurant");
        printf("\n\t  -----------------------");
        printf("\nDate:%s", date);
        printf("\nInvoice To: %s", name);
        printf("\n");
        printf("\n--------------------------------------------------");
        printf("items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n--------------------------------------------------");
        printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
        printf("%d\t\t", qty);
        printf("%.2f\t\t", qty * price);
        printf("\n"); 
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1*total;
    float netTotal = total - dis;
    float cgst = 0.09*netTotal, grandTotal = netTotal + 2*cgst;
    printf("------------------------------------------------------\n");
    printf("Sub Total \t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t--------------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n----------------------------------------------------\n");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n----------------------------------------------------\n");
}