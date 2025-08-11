#include<iostream>
using namespace std;
int largest(int arr[],int n);
int main()
{
    int arr[]={2,4,5,8,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    k=largest(arr,size);
    cout<<k;
    cout<<"Largest number is ";
    cout<<arr[k];
}
int largest(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
            flag=false;
            break;}
        }
        if(flag==true)
        {
            return i;
        }
    }return -1;
}