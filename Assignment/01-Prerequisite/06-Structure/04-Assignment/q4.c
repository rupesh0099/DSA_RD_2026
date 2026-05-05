/* 

   Create a structure "Item" which includes below member variables:
   - itemName, quantity, price, amount.
   calculate the amount by accessing the member variable with the help of structure pointer.

*/

#include<stdio.h>
#include<stdlib.h>
struct Item{
    char itemname[10];
    int quantity;
    float price;
    float amount;
};

int main(){
    struct Item *itm=NULL;
    itm=(struct Item*)malloc(sizeof(struct Item));
    printf("*****Enter the Item Details*****");
    printf("\nEnter the Item Name:\n");
    scanf("%s",itm->itemname);
    printf("\nEnter Quantity:\n");
    scanf("%d",&itm->quantity);
    printf("\nEnter the price:\n");
    scanf("%f",&itm->price);
    itm->amount=itm->quantity*itm->price;
    printf("\nCalculated Amount is:%f",itm->amount);
    free(itm);
    itm=NULL;
}
