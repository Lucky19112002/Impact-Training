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
    int mx=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx= max(mx,arr[i]);
        //(arr[i]>mx)?mx = arr[i]:mx = mx;
    }
    
    cout<<"Max is "<<mx;
    return 0;
}
