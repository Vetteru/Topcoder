// BEGIN CUT HERE
// END CUT HERE
#include <algorithm>
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

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class KnightCircuit2 {
public:
  int maxSize(int w, int h) {
    if(min(w,h) == 1) return 1;
    else if(min(w,h) == 2) return (max(w,h)-1)/2+1;
    else if(max(w,h) == 3) return 8;
    else return w*h;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, maxSize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, maxSize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 10000; verify_case(2, Arg2, maxSize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	KnightCircuit2 ___test;
	___test.run_test(-1);
}

// END CUT HERE