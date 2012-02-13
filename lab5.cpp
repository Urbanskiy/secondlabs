#include <stdio.h>
#include <string.h>
#define N 3

struct PriceList{
    char Code[8];       // - code of product
    int Price;        // - price

};
struct ProductStream{
    char Code[8];       // - code of product , same as  in PriceList
    char Name[15];      // - name of thist product
    int Count;          // - count of this type of product
};

int SortStream(ProductStream * , int count = N); /* Using to sort by product.Code */
int FindEquals(ProductStream * , int count = N); /* Using to find more then one same products*/
int PrintStream(ProductStream * products, PriceList * Prices, int count = N, int countPr = 0); /* Using to print :) */

int main(int argc, char** argv)
{

    PriceList * priceList = new PriceList[N];
    ProductStream * Stream = new ProductStream[N];

//--------------------------------------------------------------------------------------
    FILE *loadfile;
    loadfile = fopen("PriceList.txt","rt");
    if(loadfile == NULL)
        puts("Cannot open file PriceList.txt");
    else
        puts("\n File PriceList.txt was loaded successful");

    char buff[255];
    int countPrices = 0;
    while (!feof(loadfile))
    {
        fgets(buff,255,loadfile);
        sscanf(buff,"%s%d",&priceList[countPrices].Code,&priceList[countPrices].Price);
        printf("\n%-10s %d",priceList[countPrices].Code,priceList[countPrices].Price);
        countPrices++;
    }                                                                                     //
//------------------------------------------------------------------------------------------

    puts("\n\nInsert information about products");
    for(int i = 0 ; i < 3 ; i++)
    {
        printf("Code \t = ");
        scanf("%s",&Stream[i].Code);
        printf("Name \t = ");
        scanf("%s",&Stream[i].Name);
        printf("Count \t = ");
        scanf("%d",&Stream[i].Count);
        printf("__________________\n");
    }
    SortStream(Stream,N);
    FindEquals(Stream,N);
    PrintStream(Stream,priceList,N,countPrices);

	return 0;
}
int SortStream(ProductStream * products, int count)
{
    ProductStream temp;
    for(int i = count - 1; i > 0 ; i--)
    {
        for (int j = 0 ; j < i ; j++ )
        {
            if(strcmp(products[j].Code, products[j+1].Code) > 0)
            {
                    temp = products[j];
                    products[j] = products[j+1];
                    products[j+1] = temp;
            }
        }
    }
    return 0;
}
//--------------------------------------------------------
int FindEquals(ProductStream * products, int count)
{
    for(int i = count - 1; i > 0 ; i--)
    {
        if(strcmp(products[i].Code, products[i-1].Code) == 0)
        {
            products[i-1].Count += products[i].Count;
        }

    }
    return 0;
}
//-----------------------------------------------------------------------------------
int PrintStream(ProductStream * products, PriceList * Prices, int count, int countPr)
{
    int totalPrice = 0;

    printf(" \n %-10s %-15s %-10s %-15s", "Code","Name","Count","Summary Price");
    printf("\n----------------------------------------------------");
    for(int i = 0; i < count ; i++)
    {
        if(strcmp(products[i].Code,products[i-1].Code) == 0)
            continue;
        for(int j = 0 ; j < countPr ; j++)
        {
            if(strcmp(products[i].Code,Prices[j].Code) == 0)
            {
                totalPrice = products[i].Count * Prices[j].Price;
                printf(" \n %-10s %-15s %-10d %-10d", products[i].Code,products[i].Name,products[i].Count,totalPrice);
                break;
            }
        }
    }
    printf("\n----------------------------------------------------");
    return 0;
}
//------------------------------------------------------------------------------------
