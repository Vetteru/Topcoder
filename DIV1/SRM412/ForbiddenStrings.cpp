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

const int KIND = 9;
const int MAX = 31;

class ForbiddenStrings {
	public:
	long long countNotForbidden(int n) {
	  if(n == 1) return 3;
	  
	  long long dp[MAX][KIND];
	  memset(dp,0,sizeof(dp));
	  
	  for(int i = 0; i < KIND; i++) dp[2][i] = 1;

	  for(int i = 2; i < n; i++)
	    for(int j = 0; j < KIND; j++){
	      int l=j/3,r=j%3;
	      if(l != r){
		dp[i+1][r*3+l] += dp[i][j];
		dp[i+1][r*3+r] += dp[i][j];
	      }else{
		for(int k = 0; k < 3; k++)
		  dp[i+1][r*3+k] += dp[i][j];
	      }
	    }
	    
	  long long ans = 0;

	  for(int i = 0; i < KIND; i++)
	    ans += dp[n][i];
	  return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ForbiddenStrings ___test;
	___test.run_test(-1);
}

// END CUT HERE
