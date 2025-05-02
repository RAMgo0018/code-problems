#include<iostream>
using namespace std;
int largest(int arr[],int n);
int seclargest(int arr[],int n);
int main()
{
    int arr[]={1,6,7,4,5};
    int size=5;
    largest(arr,size);
}
int largest(int arr[],int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[res])
        {
            res=i;
        }
    }
    return res;
}
int seclargest(int arr[],int n)
{
    int large=largest(arr,n);
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[large]){
            if(res==-1)
            res=i;
            if(arr[i]>arr[res])
            res=i;

        }
    }
    
}