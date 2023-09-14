#include<bits/stdc++.h>
using namespace std;
void fact(int num){
    int fact=1;
    for (int i = 2; i <=num; i++)
    {
        fact*=i;
        
    }
    cout<<fact;
}

int main(){
    cout<<"Enter number";
    int a;
    cin>>a;
    fact(a);

}