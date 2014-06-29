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

typedef pair<double, double> P;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

const double EPS = 1e-9;

class ArithmeticProgression {
public:

  double minCommonDifference(int a0, vector <int> seq) {
    P ans(0, 1e8);
    for(int i = 0; i < (int)seq.size(); i++){
      P p = getRange(a0, i+1, seq[i]);
      ans.first = max(ans.first, p.first);
      ans.second = min(ans.second, p.second);
    }
    if(ans.first >= ans.second) return -1;
    return ans.first;
  }

  P getRange(double a0, double i, double x){
    return P((x-a0)/i, (x-a0+1)/i);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {6, 13, 20, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.75; verify_case(0, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {3, 3, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.2; verify_case(3, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(4, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {6, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(5, Arg2, minCommonDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ArithmeticProgression ___test;
	___test.run_test(-1);
}

// END CUT HERE
