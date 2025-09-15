/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int size, element;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    
    int arr[size];
    printf("\nEnter %d elements of the array: ",size);
    
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
         if(arr[j]>arr[j+1]){
          temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }
    }
    }
    
    printf("The sorted array is: ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element to be found:");
    scanf("%d",&element);
    
    int start, end, middle;
    start=0;
    end=size-1;
   
    
    while(start<=end){
         middle=(start+end)/2;
    if(arr[middle]==element){
        break;
    }
    else if(arr[middle]<element){
        start=middle+1;
    }
    
    else if(arr[middle]>element){
        end=middle-1;
    }
    }
    printf("the element is found at index %d",middle);

    return 0;
}