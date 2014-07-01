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

const int MAX = 3000;

class FixedDiceGameDiv1 {
public:
  double getExpectation(int a, int b, int c, int d) {
    vector<double> va = calc(a,b), vb = calc(c,d);
    double sum = 0, cnt = 0;
    for(int i = a; i <= a*b; i++)
      for(int j = c; j <= c*d; j++)
        if(i > j){
          sum += i*va[i]*vb[j];
          cnt += va[i]*vb[j];
        }
     
    if(sum == 0) return -1.0;
    return sum/cnt;
  }

  vector<double> calc(int a, int b){
    vector<double> dp(MAX, 0);
    dp[0] = 1;
    for(int x = 0; x < a; x++){
      vector<double> tmp(MAX, 0);
      for(int i = MAX-1; i >= 0; i--)
        for(int j = 1; j <= b; j++) if(i+j < MAX) tmp[i+j] += dp[i];
      dp = tmp;
    }
    return dp;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	FixedDiceGameDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
