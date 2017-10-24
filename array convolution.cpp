#include <iostream>
#include <cstring>
using namespace std;
int sum(int a, int b)
{
    return a+b;
}
int mydiv(int a, int b)
{
	return a/b;
}
int mult(int a, int b)
{
	return a*b;
}
void justdoit(int* arr, unsigned size,int(*func)(int, int)) //функция свертки массива
{
    int result=func(arr[0], arr[1]);
    for(int i=2; i<size; i++)
          result=func(result, arr[i]);
    cout<<result;
}

int main()
{
    int N;
    string key;
    cout<<"size of array? ";
    cin>>N;
    int* a = new int[N];
    cout<<'\n'<<" elements of arrray? ";
    for(int i=0; i<N; i++)
        cin>>a[i];
    cout<<"operation? (sum, div, mult) ";
    cin>>key;
    if(key=="sum")
    justdoit(a, N, sum);
    else if (key=="div")
    justdoit(a, N, mydiv);
        else if (key=="mult")
    justdoit(a, N, mult);
    return 0;
}
