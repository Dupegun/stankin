#include <iostream>
#include <string>
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
int maxx(int a, int b)
 {
    return (a>b)? a: b;
 }
/*int justdoit(int* arr, int size,int(*func)(int, int)) //функция свертки массива (цикл)
 {
    int result=func(arr[0], arr[1]);
    for(int i=2; i<size; i++)
        result=func(result, arr[i]);
    return result;
    //cout<<"result ="<<result;
 }*/
int justdoit(int* arr, int size,int(*func)(int, int)) //функция свертки массива рекурсия)
 {
    if(size==1) return arr[0];
    else if(size>0)
    return func(justdoit(arr, size-1, func), arr[size-1]);
 }
int main()
{
    int N;
    string key;
    cout<<"size of array? ";
    cin>>N;
    if(N>1)
    {
        int* a = new int[N];
        cout<<'\n'<<"elements of arrray? ";
        for(int i=0; i<N; i++)
            cin>>a[i];
        cout<<'\n'<<"operation? (sum, div, mult, max) ";
        cin>>key;
            cout<<'\n';
        if(key=="sum")
            cout<<"result ="<<justdoit(a, N, sum);
        else if (key=="div")
            cout<<"result ="<<justdoit(a, N, mydiv);
        else if (key=="mult")
            cout<<"result ="<<justdoit(a, N, mult);
        else if (key=="max")
            cout<<"result ="<<justdoit(a, N, maxx);
    }
    else cout<<"incorrect size";
    return 0;
}
