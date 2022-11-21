#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    float total;
    int opt, n;
    struct orders ord;

    // dashboard
    printf("\n\nPlease select your preferred operation");

    printf("\t=================MILRO RESTAURANT======================");
    printf("\n\n1. Generate Invoice");
    printf("\n2. Show all Invoices");
    printf("\n3. Search Invoice");
    printf("\n4. Exit");

    printf("\nYour choice: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("\n Please enter the name of the customer:\t ");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer) -1] = 0;
        strcpy(ord.date, __DATE__);
        printf("\nPlease enter the number of Items: \t");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d\t", i+1);
            fgets(ord.itm[i].item, 20, stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("please enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            printf("please enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
        }
        generateBillHeader(ord.customer, ord.date);
        for (int i = 0; i < ord.numOfItems; i++)
        {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);
        
        
        break;
    
    default:
        break;
    }

    return (0);
}