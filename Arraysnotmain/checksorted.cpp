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
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[j]<arr[i])
            return false;
        }
    }
    return true;
}
