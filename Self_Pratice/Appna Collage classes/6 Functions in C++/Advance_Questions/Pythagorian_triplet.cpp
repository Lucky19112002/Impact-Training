#include<bits/stdc++.h>
using namespace std;
bool cheak(int a,int b,int c){
    int maxi= max(a,max(b,c));
    int x,y;
    if(maxi ==a){
        x =b;y=c;}
    else if(maxi == b){
        x =a;y=c;}
    else{x=a;y=b;}

    if(maxi*maxi == (x*x+y*y))
        return true;
    else    
        return false;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    if(cheak(a,b,c)){
        cout<<"yes";
    }
    else{cout<<"no";}
    return 0;
}