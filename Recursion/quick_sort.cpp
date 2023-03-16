#include <iostream>
using namespace std;

int partition(int *arr,int start,int end){
   int pivot = arr[start];
   int i = start+1;
   int j = end;
   int cnt = 0;
   for(;i<=j;i++){
     if(arr[i] <= pivot){
        cnt++;
     }
   }
   int pivot_index = start + cnt;
   swap(arr[pivot_index],arr[start]);
   i = start;
   j = end;
   while(i < pivot_index && j > pivot_index){
    while(arr[i] < pivot){
       i++;
    }
    while(arr[j] > pivot){
        j--;
    }
    if((i < pivot_index && j > pivot_index)){
        swap(arr[i++],arr[j--]);
    }
   }
   return pivot_index;
}

void quickSort(int arr[],int start,int end){
    if(start >= end){
        return;
    }
    int  p = partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}

int main(){
   int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int *array = new int[n];
    cout<<"Enter the elements in the array:";
    for(int i=0;i<n;i++){
       int k;
       cin>>k;
       array[i] = k;
    }
    quickSort(array,0,n-1);
     for(int i=0;i<n;i++){
       cout<<array[i]<<" ";
    }
    delete [] array;
}