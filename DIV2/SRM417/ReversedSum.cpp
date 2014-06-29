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

class ReversedSum {
public:
  int getReversedSum(int x, int y) {
    string X = toStr(x), Y = toStr(y);
    reverse(ALL(X));
    reverse(ALL(Y));
    string res = toStr(toInt(X)+toInt(Y));
    reverse(ALL(res));
    return toInt(res);
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 123; int Arg1 = 100; int Arg2 = 223; verify_case(0, Arg2, getReversedSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 111; int Arg1 = 111; int Arg2 = 222; verify_case(1, Arg2, getReversedSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 1; verify_case(2, Arg2, getReversedSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, getReversedSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 456; int Arg1 = 789; int Arg2 = 1461; verify_case(4, Arg2, getReversedSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ReversedSum ___test;
	___test.run_test(-1);
}

// END CUT HERE
