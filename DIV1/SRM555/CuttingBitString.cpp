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

#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

typedef long long ll;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

const ll INF = (1LL<<60);

class CuttingBitString {
public:
  static const int MAX = 51;
  ll dp[MAX][MAX];
  string str;
  
  int getmin(string S) {
    memset(dp, -1, sizeof(dp));
    str = S;
    ll ans = solve(0, S.length());
    if(ans == INF) return -1;
    return ans;
  }

  ll solve(int l, int r){
    
    if(dp[l][r] != -1) return dp[l][r];
    if(l+1 == r) return dp[l][r] = (isPowerOf(b2d(str.substr(l, r-l)), 5))?1:INF;
    if(isPowerOf(b2d(str.substr(l, r-l)), 5)) return dp[l][r] = 1;
     
    ll res = INF;
    for(int i = l+1; i < r; i++){
      ll a = solve(l,i);
      ll b = solve(i,r);
      if(a == INF || b == INF) continue;
      res = min(res, a+b);
    }
    
    return dp[l][r] = res;
  }

  ll b2d(const string& s){
    if(s[0] == '0') return 0;
    ll base = 1;
    ll res = 0;
    for(int i = s.length()-1; i >= 0; i--){
      if(s[i] == '1') res += base;
      base *= 2;
    }
    return res;
  }

  bool isPowerOf(ll N, ll p){
    ll now = 1;
    while(now < N) now *= p;
    return N == now;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	CuttingBitString ___test;
	___test.run_test(-1);
}

// END CUT HERE
