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

class CatchTheBeat {
public:
  int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
    //SRM623 Div1 450
    vector< pair<ll,ll> > vec(n);
    vec[0].first = x0;
    for(int i = 1; i < n; i++) vec[i].first = (vec[i-1].first*a+b)%mod1;
    for(int i = 0; i < n; i++) vec[i].first -= offset;
    vec[0].second = y0;
    for(int i = 1; i < n; i++) vec[i].second = (vec[i-1].second*c+d)%mod2;

    vec = erase(vec);
    for(int i = 0; i < (int)vec.size(); i++) vec[i] = pair<ll,ll>(vec[i].first+vec[i].second, vec[i].second-vec[i].first);
    sort(ALL(vec));

    vector<int> v(vec.size());
    for(int i = 0; i < (int)vec.size(); i++) v[i] = vec[i].second;
    return LIS(v);
  }
  
  vector< pair<ll, ll> > erase(const vector< pair<ll,ll> >& vec){
    vector< pair<ll,ll> > res;
     for(int i = 0; i < (int)vec.size(); i++)
       if(abs(vec[i].first) <= vec[i].second) res.push_back(vec[i]);
     return res;
  }

  int LIS(const vector<int>& vec){
    int N = vec.size();
    int dp[N];
    fill(dp, dp+N, INT_MAX);
    for(int i = 0; i < N; i++) *upper_bound(dp, dp+N, vec[i]) = vec[i];
    return lower_bound(dp, dp+N, INT_MAX)-dp;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 100; int Arg8 = 100; int Arg9 = 1; int Arg10 = 2; verify_case(0, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1234; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 1; verify_case(1, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 999; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 0; verify_case(2, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 58585858; int Arg9 = 1; int Arg10 = 66; verify_case(3, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { int Arg0 = 500000; int Arg1 = 123456; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 0; int Arg10 = 376544; verify_case(4, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { int Arg0 = 500000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; int Arg9 = 0; int Arg10 = 500000; verify_case(5, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_6() { int Arg0 = 10; int Arg1 = 999999957; int Arg2 = 79; int Arg3 = 993948167; int Arg4 = 24597383; int Arg5 = 212151897; int Arg6 = 999940854; int Arg7 = 999999986; int Arg8 = 999940855; int Arg9 = 3404; int Arg10 = 3; verify_case(6, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	CatchTheBeat ___test;
	___test.run_test(-1);
}

// END CUT HERE
