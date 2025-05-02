#include<iostream>
using namespace std;
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
void remove(int arr[],int n)
{
    int freq=0;
    int size=n;
    int v;
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                freq++;
            }
        }
        if(freq>0){
        for(int k=0;k<freq;k++)
        {
             v=deletion(arr,arr[k],n);
        }
        break;
    }

    }
    for(int i=0;i<v;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    int n;
    cout<<"Enter Size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[n];
    }
    remove(arr,n);

}