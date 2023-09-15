#include<bits/stdc++.h>
using namespace std;

int BinaryToDecimal(int n){
    int ans = 0;
    int x = 1;
    while (n>0)
    {
        int y= n%10; // Last digite of number
        ans+= x*y;
        x*=2;
        n /= 10; // remove Last  number
    }
    return ans;
}

int DecimalToBinary(int n){
    int ans = 0;
    int x = 1;
    while (x<=n)
        x*=2;
    x/=2;
    while(x>0){
        int lastdig = n/x;
        n -= lastdig*x;
        x/=2;
        ans = ans*10 + lastdig;    
    }
    return ans;
}

int DecimalToOctal(int n){
    int ans = 0;
    int x = 1;
    while (x<=n)
        x*=8;
    x/=8;
    while(x>0){
        int lastdig = n/x;
        n -= lastdig*x;
        x/=8;
        ans = ans*10 + lastdig;    
    }
    return ans;
}

string DecimalToHexadecimal(int n){
    string ans = "";
    int x = 1;
    while (x<=n)
        x*=16;
    x/=16;

    while(x>0){
        int lastdig = n/x;
        n -= lastdig*x;
        x/=16;
        if(lastdig<= 9)
            ans = ans+to_string(lastdig);
        else{
            char c = 'A' + lastdig -10;
            ans.push_back(c);
        }

    }
    return ans;
    
}

int OctalToDecimal(int n){
    int ans = 0;
    int x = 1;
    while (n>0)
    {
        int y= n%10; // Last digite of number
        ans+= x*y;
        x*=8;
        n /= 10; // remove Last  number
    }
    return ans;
}

int  HexadecimalToDecimal(string n){
    int ans=0;
    int x=1;
    int s = n.size();
    for(int i=s-1;i>=0;i--){
        if(n[i]>= '0' && n[i]<='9'){
            ans+= x*(n[i]-'0');
        }
        else if (n[i] >= 'A' && n[i]<= 'F')
        {
            ans+= x*(n[i]-'A' +10);
        }
        x*=16;
    }
    return ans;
}

int main(){
    int n; string str;
    //cout<<"enter binary: ";
    //cin>>n;
    //cout<< BinaryToDecimal(n)<<endl;
    //cout<<"enter octan: ";
    //cin>>n;
    //cout<< OctalToDecimal(n)<<endl;
    //cout<<"enter hexadecimal: ";
    //cin>>str;
    //cout<< HexadecimalToDecimal(str)<<endl;
    cout<<"enter Decimal: ";
    cin>>n;
    cout<<"Binary: "<< DecimalToBinary(n)<<endl;
    cout<<"Octal: "<< DecimalToOctal(n)<<endl;
    cout<<"Hexadecimal: "<< DecimalToHexadecimal(n);
    return 0;
}