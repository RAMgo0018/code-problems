#include<iostream>
using namespace std;
int search(int arr[],int ele,int size);
int main()
{
    int arr[]={1,2,7,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element;
    cout<<"Enter element you want to find";
    cin>>element;
    int k;
    k=search(arr,element,size);
    cout<<k;
}
int search(int arr[],int ele,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
