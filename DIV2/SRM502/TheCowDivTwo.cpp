// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class TheCowDivTwo {
public:
  static const int MAXN = 1001;
  static const int MAXK = 50;
  static const int MOD = 1e9+7;

  int dp[2][MAXN][MAXK];

  int find(int N, int K) {
    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 0; i < N; i++){
      
      for(int j = 0; j < N; j++) 
	for(int k = 0; k <= K; k++) dp[(i+1)%2][j][k] = 0;
      
      for(int j = 0; j < N; j++){
	for(int k = 0; k <= K; k++){
	  if(k+1<=K) dp[(i+1)%2][(j+i)%N][k+1] = (dp[(i+1)%2][(j+i)%N][k+1]+dp[i%2][j][k])%MOD;
	  dp[(i+1)%2][j][k] = (dp[(i+1)%2][j][k]+dp[i%2][j][k])%MOD;	  
	}
      }
    }
    return dp[N%2][0][K];
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 5; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 4; int Arg2 = 7322; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 502; int Arg1 = 7; int Arg2 = 704466492; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 47; int Arg2 = 219736903; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TheCowDivTwo ___test;
	___test.run_test(-1);
}

// END CUT HERE
