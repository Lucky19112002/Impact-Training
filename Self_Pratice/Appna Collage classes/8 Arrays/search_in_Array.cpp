#include<bits/stdc++.h>
using namespace std;

int  linearSearch(int arr[],int n, int key){
    for(int i = 0; i<n;i++){
        if(arr[i]==key)
            cout<<"Found element on position ";
            return i+1;
    }
    return -1;
    /*
    Time complexity :- O(n);
    */
}

int binarySearch(int arr[],int n, int key){
    /*
    1. Array need to be shorted.
    2. Take mid of array comp with key.
        if mid<key >> repate form array mid+1 to array end
        if mid>key >> array start to array mid-!
    */

   int s=0,e=n;
   while (s<=e)
   {
        int mid = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid]>key){
            s=mid-1;
        }
        else{
            e=mid+1;
        }
    }
   return -1;
   //Time Complexcty: O(log n)
   //                      2
}



int main(){
    int n,key;
    cout<<"Enter length: ";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<"Enter search item: ";
    cin>>key;
    //linearSearch(arr,n,key);
    cout<<endl;
    cout<<binarySearch(arr,n,key);

    return 0;
    
}