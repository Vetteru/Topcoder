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

typedef long long ll;

class DivisorsPower {
public:
  long long findArgument(long long n) {
    ll res = LLONG_MAX;
    for(int d = 2; d < 60; d++){
      ll p = (pow(n, 1.0/(double)d) + 1e-6);
      if(pow_i(p,d) == n && divisor(p) == d) res = min(res, p);
    }
    return (res==LLONG_MAX?-1:res);
  }

  ll divisor(ll n){
    ll res = 0;
    for(ll i = 1; i*i <= n; i++){
      if(n%i == 0){
        res++;
        if(i != n/i) res++;
      }
    }
    return res;
  }

  ll pow_i(ll a, ll e){
    ll res = 1;
    while(e){
      if(e&1){
        if(LLONG_MAX/a < res) return -1;
        res *= a;
      }
      a *= a;
      e >>= 1;
    }
    return res;
  }


  // BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	DivisorsPower ___test;
	___test.run_test(-1);
}

// END CUT HERE
