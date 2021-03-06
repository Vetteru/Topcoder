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

class Subway2 {
public:
  double minTime(int length, int maxAcceleration, int maxVelocity) {
    long double ma = maxAcceleration;
    long double mv = maxVelocity;
    long double x = length/2.0;
    long double xt = sqrt(2*x/ma);
    long double vt = mv/ma;

    if(xt <= vt){
      return 2.0*xt;
    }else{
      long double rem = x-0.5*ma*vt*vt;
      return 2.0*(vt+rem/ma/vt);
    }
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 10; double Arg3 = 1.4142135623730951; verify_case(0, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 2.0; verify_case(1, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; double Arg3 = 11.0; verify_case(2, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; double Arg3 = 1.1; verify_case(3, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 778; int Arg1 = 887; int Arg2 = 384; double Arg3 = 2.458961621570838; verify_case(4, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 336; int Arg1 = 794; int Arg2 = 916; double Arg3 = 1.301036207838119; verify_case(5, Arg3, minTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Subway2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
