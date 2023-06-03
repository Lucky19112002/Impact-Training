#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contacts {
private:
    vector<string> contacts;

public:
    void addContact(string name) {
        contacts.push_back(name);
    }

    int findPartial(string partial) {
        int count = 1;
        for (const string& contact : contacts) {
            if (contact.find(partial) == 0) {
                count++;
            }
        }
        if( count == 1)
            count = 0;
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Contacts contactsApp;
    vector<int> counts;
    for (int i = 0; i < n; i++) {
        string operation, value;
        cin >> operation;
        cin >> value;

        if (operation == "add") {
            contactsApp.addContact(value);
        }
        else if (operation == "find") {
            int count = contactsApp.findPartial(value);
            counts.push_back(count);
        }
    }

    for (int count : counts) {
        cout << count << endl;
    }

    return 0;
}
/*
4
add jhon
add jose
find jose
find joy
*/