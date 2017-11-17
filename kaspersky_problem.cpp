#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int calcDist(int** a,int N)
{
    int** minDist=new int*[N];
    for(int i=0; i<N; i++)
    {
        minDist[i]=new int[N];
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==0 && j==0) {
                minDist[0][0]=a[i][j];
            }
            else if(i == 0) {
                minDist[0][j]=a[i][j]+minDist[0][j-1];
            }
            else if(j == 0) {
                minDist[i][0]=a[i][j]+minDist[i-1][0];
            }
            else {
                minDist[i][j]=min(minDist[i][j-1], minDist[i-1][j]) + a[i][j];
            }

        }

    int result=minDist[N-1][N-1];

    for(int i=0; i<N; i++)
    {
        delete[] minDist[i];
    }
    delete[] minDist;

    return result;

}

int main()
{
  ifstream fin("in.txt");
  
  int N;
  fin>>N;
  
  int **numbers= new int*[N];
  for(int i=0; i<N; i++)
  {
      numbers[i]=new int[N];
  }

  for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
      {
          fin>>numbers[i][j];
      }
  
  fin.close();

  ofstream fout("out.txt");
  fout<<calcDist(numbers, N);
  fout.close();

  for(int i=0; i<N; i++)
  {
      delete[] numbers[i];
  }
  delete[] numbers;

    return 0;
}
