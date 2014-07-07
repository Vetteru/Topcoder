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

class LotteryPyaterochka {
public:
  double chanceToWin(int N) {
    double C[501][501] = {0};
    C[0][0] = 1;
    for(int i = 0; i < 501; i++)
      for(int j = 0; j < 501; j++){
        if(i-1 >= 0) C[i][j] += C[i-1][j];
        if(i-1 >= 0 && j-1 >= 0) C[i][j] += C[i-1][j-1];
      }
    return (double)N*(C[5][3]*C[5*N-5][2]+C[5][4]*C[5*N-5][1]+C[5][5]*C[5*N-5][0])/C[5*N][5];
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 1.0; verify_case(0, Arg1, chanceToWin(Arg0)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = 1.0; verify_case(1, Arg1, chanceToWin(Arg0)); }
	void test_case_2() { int Arg0 = 3; double Arg1 = 0.5004995004995004; verify_case(2, Arg1, chanceToWin(Arg0)); }
	void test_case_3() { int Arg0 = 6; double Arg1 = 0.13161551092585574; verify_case(3, Arg1, chanceToWin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	LotteryPyaterochka ___test;
	___test.run_test(-1);
}

// END CUT HERE
