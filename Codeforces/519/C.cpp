#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = s + "b";

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        if (s[i] != s[i + 1]) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << '\n';
    return 0;
}
