#include<iostream>
using namespace std;
int insert(int arr[],int size,int position,int element,int capacity);
int main()
{
    int arr[5]={2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int capacity=5;
    int item;
    cout<<"element you want to insert";
    cin>>item;
    int position;
    cout<<"Enter position at which you want to insert";
    cin>>position;
    insert(arr,size,position,item,capacity);
}
int insert(int arr[],int size,int position,int element,int capacity)
{
    if(capacity==size)
    {
        return size;
    }
    int index;
    index=position-1;
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
}
