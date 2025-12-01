#include<iostream>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partitionQ(int a[],int l,int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int p=partitionQ(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int main(){
    int n,choice;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) 
       cin>>a[i];
    cout << "\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n";
cout << "Enter choice: ";
cin >> choice;

switch(choice){
    case 1:
        selectionSort(a, n);
        break;

    case 2:
        insertionSort(a, n);
        break;

    case 3:
        bubbleSort(a, n);
        break;

    case 4:
        mergeSort(a, 0, n - 1);
        break;

    case 5:
        quickSort(a, 0, n - 1);
        break;

    default:
        cout << "Invalid\n";
        return 0;
}
   cout<<"Sorted Array: ";
    print(a,n);

    return 0;
}

    