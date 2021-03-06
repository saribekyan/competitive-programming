#include <iostream>
#include <vector>
using namespace std;

int main() {
    int b;
    cin >> b;
    vector< int > v(b);
    for (int i = 0; i < b; ++i) {
        cin >> v[i];
    }
    int farms;
    cin >> farms;
    vector< int > farm_mask(farms, 0);
    for (int f = 0; f < farms; ++f) {
        int types;
        cin >> types;
        for (int t = 0; t < types; ++t) {
            int i;
            cin >> i;
            farm_mask[f] = farm_mask[f] | (1 << (i - 1));
        }
    }

    int ans_cows = 0;
    for (int adv_mask = 0; adv_mask < (1 << b); ++adv_mask) {
        bool is_adv = true;
        for (int f = 0; f < farms; ++f) {
            if ((farm_mask[f] & adv_mask) == 0 && farm_mask[f] != 0) {
                is_adv = false;
                break;
            }
        }
        if (is_adv) {
            int cows = 0;
            for (int t = 0; t < b; ++t) {
                if (((adv_mask >> t) & 1) == 0) {
                    cows += v[t];
                }
            }
            if (ans_cows < cows) {
                ans_cows = cows;
            }
        }
    }

    cout << ans_cows << '\n';
    return 0;
}
