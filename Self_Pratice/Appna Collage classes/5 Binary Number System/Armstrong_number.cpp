#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter value: ";
    cin>>n;
    int m=n;
    int cube=0;
    while (n>0){
        int lastdigit = n%10;
        cube+= pow(lastdigit,3);
        n=n/10;
    }
    if(cube == m){
        cout<<"Armstrong ";
    }
    else{
        cout<<"Not Armstrong ";
    }
    return 0;
}