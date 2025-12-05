#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n-1;i++){
        int temp=arr[i];
        int j=i;
        for(;j>0 && arr[j-1]>temp;){
            arr[j]=arr[j-1];
            j=j-1;
        }
        arr[j]=temp;
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}