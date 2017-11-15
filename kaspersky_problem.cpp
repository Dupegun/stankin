#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream fin("in.txt");
  int N;
  fin>>N;
  
  int **minDist=new int*[N];
  for(int i=0; i<N; i++) 
	  minDist[i]=new int[N];
  
  for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
      {
	  int temp;
          fin>>temp;
          if(i==0 && j==0)
              minDist[0][0]=temp;
          else if(i==0)
              minDist[0][j]=temp+minDist[0][j-1];
          else if(j==0)
              minDist[i][0]=temp+minDist[i-1][0];
          else
              minDist[i][j]=min(minDist[i][j-1], minDist[i-1][j]) + temp;
      }

  fin.close();
  
  ofstream fout("out.txt");
  fout<<minDist[N-1][N-1];
  fout.close();
  
  for(int i=0; i<N; i++) 
	  delete[] minDist[i];
  
  delete[] minDist;

    return 0;
}
