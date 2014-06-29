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

class InfiniteSequence {
public:
  map<long long, long long> M;
  long long P,Q;

  long long calc(long long n, int p, int q) {
    M.clear();
    M[0] = 1;
    P = p;
    Q = q;
    return find(n);
  }

  long long find(long long n){
    if(M.count(n)) return M[n];
    long long res = find(n/P)+find(n/Q);
    return M[n] = res;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 0LL; int Arg1 = 2; int Arg2 = 3; long long Arg3 = 1LL; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 7LL; int Arg1 = 2; int Arg2 = 3; long long Arg3 = 7LL; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 10000000LL; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 32768LL; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 256LL; int Arg1 = 2; int Arg2 = 4; long long Arg3 = 89LL; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1LL; int Arg1 = 1000000; int Arg2 = 1000000; long long Arg3 = 2LL; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	InfiniteSequence ___test;
	___test.run_test(-1);
}

// END CUT HERE
