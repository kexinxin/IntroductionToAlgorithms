#include <iostream>
#include <pthread.h>
#include <time.h>
#include<stdlib.h>
using namespace std;

#define RANGE 10
struct Point{
    int x;
    int y;
};

int **a;
int **b;
int **c;

int asize_x=4;
int asize_y=4;
int bsize_x=4;
int bsize_y=4;
void* routine (void* point)
{
    int x = ((Point *)point)->x;
    int y = ((Point *)point)->y;
    c[x][y] = 0;
    for(int i = 0; i < asize_y; i++)
        c[x][y] += a[x][i] * b[i][y];
    return point;
}


void gene_matrix(int **matrix,int sizeX,int sizeY)
{
    int i,j;
    srand((unsigned)time(NULL));
    for(i=0;i<sizeX;i++)
    {
        for(j=0;j<sizeY;j++)
            matrix[i][j]=rand()%RANGE;
    }
}

void print(int** matrix,int sizeX,int sizeY){
    cout<<"_____________________________"<<endl;
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"______________________________"<<endl;
}


int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

    a = new int *[asize_x];
    for(i = 0; i < asize_x; i++)
    {
        a[i] = new int [asize_y];
    }
    b = new int *[bsize_x];
    for( i = 0; i < bsize_x; i++)
    {
        b[i] = new int [bsize_y];
    }
    gene_matrix(a,asize_x,asize_y);
    gene_matrix(b,bsize_x,bsize_y);
    c = new int *[asize_x];
    for( i = 0; i < asize_x; i++)
    {
        c[i] = new int [bsize_y];
    }

    pthread_t *thread = new pthread_t[asize_x * bsize_y];
    for(i = 0; i < asize_x; i++)
    {
        for(j = 0; j < bsize_y; j++)
        {
            Point *point = new Point();
            point->x = i;
            point->y = j;

            if(pthread_create(&thread[k++], NULL, routine, point))
            {
                cout << "create thread fail!\n";
                return 0;
            }
        }
    }

    for (i = 0; i < asize_x; i++)
    {
        for(j = 0; j < bsize_y; j++)
        {
            cout << c[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    for(i=0; i < asize_x; i++)
    {
        delete a[i];
        delete c[i];
    }
    for(i=0; i < bsize_x; i++)
    {
        delete b[i];
    }
    delete b;
    delete c;
    delete a;
    for(i = 0; i < asize_x * bsize_y; i++)
    {
        pthread_join(thread[i],NULL);
    }
    return 0;
}
