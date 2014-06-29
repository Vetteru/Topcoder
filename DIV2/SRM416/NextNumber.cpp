// BEGIN CUT HERE
// END CUT HERE
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class NextNumber {
public:
  int getNextNumber(int N) {
    string s = bitset<32>(N).to_string();
    next_permutation(s.begin(), s.end());
    return bitset<32>(s).to_ulong();
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1717; int Arg1 = 1718; verify_case(0, Arg1, getNextNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 8; verify_case(1, Arg1, getNextNumber(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 11; verify_case(2, Arg1, getNextNumber(Arg0)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 17; verify_case(3, Arg1, getNextNumber(Arg0)); }
	void test_case_4() { int Arg0 = 555555; int Arg1 = 555557; verify_case(4, Arg1, getNextNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	NextNumber ___test;
	___test.run_test(-1);
}

// END CUT HERE
