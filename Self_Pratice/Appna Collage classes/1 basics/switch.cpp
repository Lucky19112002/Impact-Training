#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    char a;
    int b,c;
    cout<<"Enter 2 number you wnat to operate on.";
    cin>>c>>b;
    cout<<"number are"<<b<<"\t"<<c;
    for (;;)
    {
        cout<<"\nEnter operation +-*/% .: ";
        cin>>a;
        /*switch (a)
        {
        case 1:
            cout<<"hellow";
            break;
        case 2:
            cout<<"hi";
            break;;
        case 3:
            cout<<"hola";
            break;    
        case 4:
            cout<<"haji namsata";
            break;
        case 5:
            cout<<"hi there meat";
            break;
        case 6:
            cout<<"Exiting...";
            return 0;
        default:
            cout<<"Enter from 1 to 6   please";
            break;
        }*/
        switch (a)
        {
        case '+':
            cout<< c+b;
            break;
        case '-':
            cout<<c-b;
            break;
        case '*':
            cout<<c*b;
            break;
        case '/':
            cout<<c/b;
            break;
        case '%':
            cout<<c%b;
            break;
        case '.':
            cout<<"Exiting...";
            return 0;
        default:
            cout<<"Enter a valid ";
            break;
        }
    }
}