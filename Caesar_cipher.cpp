#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    string cyp = s; 
    string plain = s; 

    // Encryption
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cyp[i] = 'a' + (s[i] - 'a' + k) % 26;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            cyp[i] = 'A' + (s[i] - 'A' + k) % 26;
        } else if (s[i] >= '0' && s[i] <= '9') {
            cyp[i] = '0' + (s[i] - '0' + k) % 10;
        } else {
            cyp[i] = s[i]; 
        }
    }

    cout << "Cipher Text: " << cyp << endl;

    // Decryption
    for (int i = 0; i < cyp.size(); i++) {
        if (cyp[i] >= 'a' && cyp[i] <= 'z') {
            plain[i] = 'a' + (cyp[i] - 'a' - k + 26) % 26;
        } else if (cyp[i] >= 'A' && cyp[i] <= 'Z') {
            plain[i] = 'A' + (cyp[i] - 'A' - k + 26) % 26;
        } else if (cyp[i] >= '0' && cyp[i] <= '9') {
            plain[i] = '0' + (cyp[i] - '0' - k + 10) % 10;
        } else {
            plain[i] = cyp[i]; 
        }
    }

    cout << "Plain Text: " << plain << endl;

    // Case Change
    cout << "Case Change: ";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            char c = s[i] - 32;
            cout << c;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            char c = s[i] + 32;
            cout << c;
        } else {
            cout << s[i]; 
        }
    }
    cout << endl;

    return 0;
}
