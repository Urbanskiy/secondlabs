#include <stdio.h>
#include <string.h>
#define N 5
#define TOPKN_COUNT 3

struct TGroups{
    int Number;
    char Name[8];
    double AVG;
};

void Sort(TGroups * gr, int count = 0);         // - sort groupList by AVG
void PrintList(TGroups * gr, int count = 0);    // - print grouplist

int main(int argc, char** argv)
{
    TGroups * groups = new TGroups[N];
    int i = 0;

    printf("\nEnter info about groups :");
    for(i = 0; i < N ; i++)
    {
        printf("\n #%d -", i + 1);
        groups[i].Number = i + 1;
        printf(" name: ");
        scanf("%s",groups[i].Name);
        printf(" #%d - AVG: ",i+1);
        scanf("%lf",&groups[i].AVG);
    }

    Sort(groups,N);
    PrintList(groups,N);


    char *p = new char[3*8];
    int topCount = 0;

    puts("\nTop 3 KN groups:");
    for(i = 0; i < N ; i++)
    {
        if ( strstr(groups[i].Name,"KN") != NULL &&  ( strstr(p,groups[i].Name)== NULL))
        {
            printf("\n %s",groups[i].Name);
            strcpy(p,groups[i].Name );
            topCount++;
            if(topCount == TOPKN_COUNT) break;
        }
    }

	return 0;
}
void PrintList(TGroups * gr, int count )
{
    printf("\n %-7s %-8s %-6s", "Number","Name","AVG");
    printf("\n----------------------------------------------------");
    for(int i = 0; i < count ; i++)
    {
        printf("\n %-7d %-8s %8.3f", gr[i].Number,gr[i].Name,gr[i].AVG);
    }
    printf("\n----------------------------------------------------");
}
//------------------------------------------------------------------------------------
void Sort(TGroups * gr, int count )
{
    TGroups temp;

    for(int i = count - 1; i > 0 ; i--)
    {
        for (int j = 0 ; j < i ; j++ )
        {
            if( gr[j].AVG < gr[j+1].AVG)
            {
                    temp = gr[j];
                    gr[j] = gr[j+1];
                    gr[j+1] = temp;
            }
        }
    }
}
//------------------------------------------------------------------------------------
