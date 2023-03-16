#include <iostream>
using namespace std;


void merge(int *main_array,int start,int end){
 
 int mid = (start + end)/2;
 int len1  = mid - start + 1;
 int len2 =  end - mid;
 int *first = new int[len1];
 int *second = new int[len2];
 
 int main_array_index = start;
 for(int i=0;i<len1;i++){
    first[i] = main_array[main_array_index++];
 }
 main_array_index = mid+1;
 for(int i = 0;i<len2;i++){
    second[i] = main_array[main_array_index++];
 }

 //'merge 
 int index1=0,index2=0;
 main_array_index = start;
 while(index1 < len1 && index2 < len2){
     if(first[index1] > second[index2]){
        main_array[main_array_index++] = second[index2++];
     }
     else{
        main_array[main_array_index++] = first[index1++];
     }
 }

 while(index1 < len1)main_array[main_array_index++] = first[index1++];
 while(index2 < len2)main_array[main_array_index++] = second[index2++];
 delete []first;
 delete []second;
}
void mergeSort(int *arr,int start ,int end){
   if(start >= end){
    return;
   }
   int mid = start + ((end - start)/2);
   mergeSort(arr,start,mid);
   mergeSort(arr,mid+1,end);
   merge(arr,start,end);
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
    mergeSort(array,0,n-1);
    cout << "The array in the sorted order is:"<<endl;
     for(int i=0;i<n;i++){
       cout<<array[i]<<" ";
    }

}