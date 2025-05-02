#include<iostream>
using namespace std;
int seclargest(int arr[],int n);
int main()
{
    int arr[]={4,5,7,2,3};
    int size=5;
    seclargest(arr,size);
}
int seclargest(int arr[],int n)
{
    int res=-1,largest=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            res=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(res==-1||arr[i]>arr[res])
            {
                res=i;
            }
        }
    }
    return res;
}
