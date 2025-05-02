#include<iostream>
using namespace std;
int deletion(int arr[],int element,int size);
int main()
{
    int arr[]={1,4,5,78,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element;
    cout<<"element you want to delete";
    cin>>element;
    int k;
    k=deletion(arr,element,size);
    cout<<"New array is";
    for(int i=0;i<k;i++)
    {
        cout<<arr[i];
    }
}
int deletion(int arr[],int element,int size)
{
    int i;
    for( i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            break;
        }
    }
    if(i==size)
    {
        return size;
    }
    for(int j=i;j<size-1;j++)
    {
        arr[j]=arr[j+1];
    }
    return (size-1);
}
