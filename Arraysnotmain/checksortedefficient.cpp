#include<iostream>
using namespace std;
bool check(int arr[],int n);
int main()
{
    int arr[]={2,4,1,5,7};
    int size=5;
    check(arr,size);
}
bool check(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
    if(arr[i]<arr[i-1])
    {
        return false;
    }
    }
    return true;
}