#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream fin("in.txt");
  int N;
  fin>>N;
  cout<<"Size ="<<N<<'\n';
  int minDist[N][N];
//  int arr[N][N];

//  for(int i=0; i<N; i++)
//      for(int j=0; j<N; j++)
//          fin>>arr[i][j];


//  minDist[0][0]=arr[0][0];
//  fin>>minDist[0][0];

//  for(int i=1; i<N; i++)
//  {
//      int temp;
//      fin>>temp;
//      cout<<"readed temp="<<temp<<'\n';
//      minDist[i][0]=temp+minDist[i-1][0];
//      cout<<"Distance to arr["<<i<<"]["<<0<<"] ="<<minDist[i][0]<<'\n';
//  }

//  for(int j=1; j<N; j++)
//  {
//      int temp;
//      fin>>temp;
//      cout<<"readed temp="<<temp<<'\n';
//      minDist[0][j]=temp+minDist[0][j-1];
//      cout<<"Distance to arr["<<0<<"]["<<j<<"] ="<<minDist[0][j]<<'\n';
//  }

  for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
      {

          int temp;
          fin>>temp;
          cout<<"readed temp="<<temp<<'\n';
          if(i==0 && j==0)
              minDist[0][0]=temp;
          else if(i==0)
              minDist[0][j]=temp+minDist[0][j-1];
          else if(j==0)
              minDist[i][0]=temp+minDist[i-1][0];
          else
              minDist[i][j]=min(minDist[i][j-1], minDist[i-1][j]) + temp;

          cout<<"Distance to arr["<<i<<"]["<<j<<"] ="<<minDist[i][j]<<'\n';
      }

  fin.close();
  ofstream fout("out.txt");
  fout<<minDist[N-1][N-1];
  fout.close();
  system("pause");
    return 0;
}
