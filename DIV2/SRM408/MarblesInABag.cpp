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

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

const int MAX = 4001;
double dp[2][MAX];

class MarblesInABag {
public:
  double getProbability(int redCount, int blueCount) {

    for(int i = 0; i < MAX; i++) dp[0][i] = dp[1][i] = 0;
    dp[redCount%2][blueCount] = 1;

    for(int i = redCount; i >= 0; i--){
      int now = i%2;
      int nex = 1-now;
      for(int k = 0; k < MAX; k++) dp[nex][k] = 0;
	for(int j = blueCount; j > 0; j--){
	  double proR = (double)i/(double)(i+j);
	  double proB = (double)j/(double)(i+j);
	  if(i > 0 && j > 0) dp[nex][j-1] += dp[now][j]*proR;
	  if(j > 1) dp[now][j-2] += dp[now][j]*proB;
	}
    }
    return dp[0][1];
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 0.3333333333333333; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 0.13333333333333333; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 5; double Arg2 = 0.22857142857142856; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 6; double Arg2 = 0.0; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 11; double Arg2 = 0.12183372183372182; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	MarblesInABag ___test;
	___test.run_test(-1);
}

// END CUT HERE
