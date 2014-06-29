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

typedef long long ll;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class ElectionFraudDiv1 {
public:
  static const int MAX = 2000;
  int MinimumVoters(vector <int> percentages) {
    int N = percentages.size();
    for(int x = 1; x <= MAX; x++){
      int minv = 0, maxv = 0;
      bool valid = true;

      for(int i = 0; i < N; i++){
	ll a = getMin(x, percentages[i]);
	ll b = getMin(x, percentages[i]+1)-1;
	if(a > b) valid = false;
	minv += a;
	maxv += b;
      }
      if(valid && minv <= x && x <= maxv) return x;
    }
    return -1;
  }
  
  ll getMin(ll t, ll p){
    if(p*t - t/2 < 0) return 0;
    return (p*t - t/2)/100 + ((p*t - t/2)%100==0?0:1);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {33, 33, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, MinimumVoters(Arg0)); }
	void test_case_1() { int Arr0[] = {29, 29, 43}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, MinimumVoters(Arg0)); }
	void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, MinimumVoters(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, MinimumVoters(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; verify_case(4, Arg1, MinimumVoters(Arg0)); }
	void test_case_5() { int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 97; verify_case(5, Arg1, MinimumVoters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ElectionFraudDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
