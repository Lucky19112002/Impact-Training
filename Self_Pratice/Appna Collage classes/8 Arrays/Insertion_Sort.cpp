#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 1; i < n ; i++) {
        int current  = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = current;           
    }
}

int main(){
    int n;
    cout << "Enter Length: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
