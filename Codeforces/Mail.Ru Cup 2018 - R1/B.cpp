#include <iostream>
using namespace std;

int main() {
    int n;
    int curr = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < curr) {
        }
        else if (a == curr) {
            curr++;
        }
        else {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
