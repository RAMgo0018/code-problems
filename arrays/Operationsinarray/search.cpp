#include<iostream>
using namespace std;
int search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter length of array";
  
    cout<<"Enter array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array elements are"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Enter Element to be searched";
    int x,find;
    cin>>x;
    find=search(arr,n,x);
    if(find==-1)
    {
        cout<<"Element Not found";
    }
    else
    {
        cout<<"Element found at Index"<<find;
    }
    return 0;

}