#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
struct TDict
{
    char Term[15];
    char Difinition[255];
};
void PrintDictionary(TDict * dic, int count );
TDict GetTermFromKeyboard();
int IsInArr(int * arr,int quizCoun, int val);
double StartQuiz(TDict * dic, int count);

int main(int argc, char** argv)
{
    TDict * dictionary = new TDict[N];
    int i, quizQuestionsCount;

    for(i = 0; i < N ; i++)
    {
        dictionary[i] = GetTermFromKeyboard();
    }
    //clrscr();
    printf("\n How many questions do you want ?  - ");
    scanf("%d",&quizQuestionsCount);
    StartQuiz(dictionary,quizQuestionsCount);
    //PrintDictionary(dictionary,N);
    delete[] dictionary;
	return 0;
}
//---------------------------------------------------------------
double StartQuiz(TDict * dic, int count)
{
    //--------------------------------
    /* need to take off enter        */
    char temp;
    temp = getchar();
    //---------------------------------
    char buff[255];
    int * quizTerms = new int[count];
    int random;
    int trueCount = 0;

    srand(time(NULL));
    for(int i = 0 ; i < count ; i++)
    {
        while(!IsInArr(quizTerms,i,random = rand() % count));
        quizTerms[i] = random;
        printf("\n %s - ",dic[random].Term);
        gets(buff);
        if( strcmp(buff,dic[random].Difinition) == 0)
        {
            trueCount++;
        }
    }
    printf("\n\n The persent of correct answers is %.2f", trueCount / (double)count );
    return 0;

}
//---------------------------------------------------------------
int IsInArr(int * arr,int quizCoun, int val)
{
    for(int i = 0; i < quizCoun; i++)
    {
        if(arr[i] == val)
        {
            return 0;
        }
    }
    return 1;
}
//---------------------------------------------------------------
TDict GetTermFromKeyboard()
{
    static int i = 0;
    TDict temp;

    printf("\nTerm #%d - ",i  + 1);
    gets(temp.Term);
    printf("\nDifinition #%d - ",i + 1);
    gets(temp.Difinition);
    i++;

    return temp;
}
//---------------------------------------------------------------
void PrintDictionary(TDict * dic, int count )
{
    puts("");
    for(int i = 0 ; i < count ; i++ )
    {
        printf("\n %s - %s ", dic[i].Term, dic[i].Difinition);
    }
}
//---------------------------------------------------------------
