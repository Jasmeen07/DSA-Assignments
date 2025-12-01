#include<iostream>
using namespace std;

void improvedSelectionSort(int a[],int n){
    int left=0,right=n-1;

    while(left<right){
        int minIndex=left,maxIndex=right;

        if(a[minIndex]>a[maxIndex]) swap(minIndex,maxIndex);

        for(int i=left+1;i<=right-1;i++){
            if(a[i]<a[minIndex]) minIndex=i;
            if(a[i]>a[maxIndex]) maxIndex=i;
        }

        swap(a[left],a[minIndex]);

        if(maxIndex==left) maxIndex=minIndex;

        swap(a[right],a[maxIndex]);

        left++;
        right--;
    }
}

void print(int a[],int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    improvedSelectionSort(a,n);

    cout<<"Sorted array: ";
    print(a,n);

    return 0;
}
