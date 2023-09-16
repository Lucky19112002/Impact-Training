#include<bits/stdc++.h>
using namespace std;

int main() {
    int money = 0;
    cout<<"Enter money:";
    cin>>money;            
    int cost = 1; 
    int wrapper_chocolate = 3; 

    int chocolates = money / cost; 
    int wrappers = chocolates;
    while (wrappers >= wrapper_chocolate) {
        int additional = wrappers / wrapper_chocolate;
        chocolates += additional;
        wrappers = additional + (wrappers % wrapper_chocolate); 
    }

    cout << "Maximum amount of chocolate you can get: " << chocolates << " chocolates." << endl;

    return 0;
}
