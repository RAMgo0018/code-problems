#include<iostream>
using namespace std;
int largest(int arr[],int n);
int main()
{
    int arr[]={1,4,5,7,8};
    int size=5;
    int k;
    k=largest(arr,size);
    cout<<k;
}
int largest(int arr[],int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[res]<arr[i])
        res=i;
    }
    return res;
}