#include<iostream>
#include <stack>
#include <string>
using namespace std;

bool cheaking(const string& user_input) {
    stack<char> mystack;

    for (char c : user_input) 
    {
        if (c == '(' || c == '{' || c == '[')
        {
            mystack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') 
        {
            if (mystack.empty())
                return false;
            char top = mystack.top();
            mystack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) 
            {
                return false;
            }
        }
    }
    return mystack.empty();
}

int main()
{
    string user_input;
    cout << "Enter: ";
    getline(cin, user_input);

    if (cheaking(user_input)) {
        cout << "Brackets are balanced." << endl;
    } else {
        cout << "Brackets are not balanced." << endl;
    }

    return 0;
}