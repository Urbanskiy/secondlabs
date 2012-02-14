#include <stdio.h>
#include <string.h>
#define N 3

struct TBook{
    char author[15];
    char name[25];
    char editorial_office[25];
    int year;
};

void SortBooks(TBook * book, int count);        /* Using to sort books by year */
void PrintBooks(TBook * book, int count);       /* Using to print 1..count of book list */
int PrintCppBooks(TBook * book, int count);     /* Using to printf 1..count books where name LIKE "C\C++" */

int main(int argc, char** argv)
{
    TBook * book = new TBook[N];
    int i = 0;
    char clearBuff;     // using to clear input buffer, example after scanf

    puts("\n\nInsert information about books");

    //******** Input data about books ******
    for(i = 0 ; i < N ; i++)
    {
        printf("Author\t = ");
        gets(book[i].author);            //  gets Author name
        printf("Name\t = ");
        gets(book[i].name);              //  gets Name of book
        printf("edition\t = ");
        gets(book[i].editorial_office);  //  gets Edit Office
        printf("year\t = ");
        scanf("%d",&book[i].year);       //  gets Year of publish
        clearBuff = getchar();           // clear input buffer =)
        printf("__________________\n");
    }
    //**************************************

    SortBooks(book,N);
    PrintBooks(book,N);
    printf("\n There are %d books about C\\C++",PrintCppBooks(book,N));         // call PrintCppBooks and after
                                                                                // print count of those books
    delete[] book;
	return 0;
}
//-------------------------------------------------------
void SortBooks(TBook * book, int count)
{
    TBook temp;
    for(int i = count - 1; i > 0 ; i--)
    {
        for (int j = 0 ; j < i ; j++ )
        {
            if(book[j].year < book[j+1].year)
            {
                temp      = book[j];
                book[j]   = book[j+1];
                book[j+1] = temp;
            }
        }
    }
}
//--------------------------------------------------------
int PrintCppBooks(TBook * book, int count)
{
    int tempCounter = 0;        // count how many books names LIKE "C\C++"
    puts("\n\nBooks about C\\C++ :");
    printf(" \n %-10s %-15s %-20s %-15s", "Author","Name","Edition","Year");
    printf("\n----------------------------------------------------");
    for(int i = 0 ; i < N ; i++)
    {
        if(strstr(book[i].name,"C\\C++") != NULL)
        {
            printf(" \n %-10s %-15s %-20s %-10d", book[i].author,book[i].name,book[i].editorial_office,book[i].year);
            tempCounter++;
        }
    }
    printf("\n----------------------------------------------------");
    return tempCounter;

}
//--------------------------------------------------------
void PrintBooks(TBook * book, int count)
{
    printf(" \n %-10s %-15s %-20s %-15s", "Author","Name","Edition","Year");
    printf("\n----------------------------------------------------");
    for(int i = 0; i < count ; i++)
    {
        printf(" \n %-10s %-15s %-20s %-10d", book[i].author,book[i].name,book[i].editorial_office,book[i].year);
    }
    printf("\n----------------------------------------------------");
}
//------------------------------------------------------------------------------------
