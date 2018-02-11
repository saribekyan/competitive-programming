#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

// BEGIN CUT HERE
#pragma warning(disable:4018)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#include <ctime>
#include <iostream>
#include <sstream>
// END CUT HERE

class MagicNumberThree {
public:
    int countSubsequences(string s) {
        long long d[55][3] = { 0 };
        long long M = 1000000007;
        d[0][(s[0] - '0') % 3] = 1;
        for (int i = 1; i < s.size(); ++i) {
            int c = s[i] - '0';
            d[i][c % 3] = 1;
            for (int j = 0; j < 3; ++j) {
                d[i][(j * 10 + c) % 3] = (d[i][(j * 10 + c) % 3] + d[i - 1][j]) % M;
                d[i][j] = (d[i][j] + d[i - 1][j]) % M;
            }
        }
        return d[s.size() - 1][0];
    }

///////////////////////////

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "132"; int Arg1 = 3; verify_case(0, Arg1, countSubsequences(Arg0)); }
	void test_case_1() { string Arg0 = "9"; int Arg1 = 1; verify_case(1, Arg1, countSubsequences(Arg0)); }
	void test_case_2() { string Arg0 = "333"; int Arg1 = 7; verify_case(2, Arg1, countSubsequences(Arg0)); }
	void test_case_3() { string Arg0 = "123456"; int Arg1 = 23; verify_case(3, Arg1, countSubsequences(Arg0)); }
	void test_case_4() { string Arg0 = "00"; int Arg1 = 3; verify_case(4, Arg1, countSubsequences(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    MagicNumberThree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
