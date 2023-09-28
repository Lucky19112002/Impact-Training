#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cout << "Enter Length: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int curr =0;
    for (int i = 0; i < n; i++){
        curr =0;
        cout<<"Subarray "<<i<<": "<<endl;
        for(int j=i;j<n;j++){
            curr += arr[j];
            cout<<curr<<endl;
        }
    }
    
    return 0;
}
