#include<bits/stdc++.h>
using namespace std;

int selectionSort(int arr [],int n){
    int temp=0;

    for(int i = 0; i<n;i++){
        for(int j = i; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<endl<<"After sort: ";
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter Length";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before: ";
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    selectionSort(arr,n);
    return 0;
}