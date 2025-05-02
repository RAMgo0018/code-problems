#include<iostream>
using namespace std;
void removeduplicates(int arr[],int n)
{
    int temp[n],res=1;
    temp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        arr[i]=temp[i];
    }
    cout<<"Removed duplicated array is";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Entered array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    removeduplicates(arr, n);
    return 0;
}
