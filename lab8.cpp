#include <stdio.h>
#include <math.h>
#define N 3

struct TPoint{
    int x;
    int y;
    int z;
};

void Sort(TPoint * pts, int count = 0);         // - sort points by Z coordinate
void PrintList(TPoint * pts, int count = 0);    // - print points table
double Average(TPoint * p1, TPoint * p2);            // - find averages between points

int main(int argc, char** argv)
{
    TPoint * points = new TPoint[N];
    int i = 0;
    printf("Input points coordinates x, y, z:");
    for(i = 0; i < N ; i++)
    {
        printf("\n%d point: ",i+1);
        scanf("%d%d%d",&points[i].x,&points[i].y,&points[i].z);

    }
    Sort(points,N);
    PrintList(points,N);

// Find and print min averages between points and those coordinates
    TPoint *ptsMinAverage = new TPoint[2];
    double minAverage = Average(&points[0],&points[N-1]);
    ptsMinAverage[0] = points[0];
    ptsMinAverage[1] = points[N-1];
    int j;
    for(i = 0; i < N; i++)
    {
        for( j = i + 1; j < N ; j++)
        {
            if( Average(&points[i],&points[j]) < minAverage)
            {
                minAverage = Average(&points[i],&points[j]);
                ptsMinAverage[0] = points[i];
                ptsMinAverage[1] = points[j];
            }
        }
    }
    printf("\nThe min average = %8.3f between:",minAverage);
    printf("\n ( %d,%d,%d ) & ( %d,%d,%d )",ptsMinAverage[0].x,ptsMinAverage[0].y,ptsMinAverage[0].z,
                                            ptsMinAverage[1].x,ptsMinAverage[1].y, ptsMinAverage[1].z);
    delete[] points;
    delete[] ptsMinAverage;
	return 0;
}
//------------------------------------------------------------------------------------
void Sort(TPoint * pts, int count)
{
    TPoint temp;

    for(int i = count - 1; i > 0 ; i--)
    {
        for (int j = 0 ; j < i ; j++ )
        {
            if( pts[j].z > pts[j+1].z)
            {
                    temp = pts[j];
                    pts[j] = pts[j+1];
                    pts[j+1] = temp;
            }
        }
    }
}
//------------------------------------------------------------------------------------
void PrintList(TPoint * pts, int count )
{
    printf("\n %-3s %-3s %-3s", "X","Y","Z");
    printf("\n----------------------------------------------------");
    for(int i = 0; i < count ; i++)
    {
        printf("\n %-3d %-3d %-3d", pts[i].x,pts[i].y,pts[i].z);
    }
    printf("\n----------------------------------------------------");
}
//------------------------------------------------------------------------------------
double Average(TPoint * p1, TPoint * p2)
{
    return sqrt( pow(p2->x -p1->x,2.0) + pow(p2->y -p1->y,2.0) + pow(p2->z -p1->z,2.0));
}
//------------------------------------------------------------------------------------
