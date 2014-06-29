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

typedef long long ll;
typedef pair<ll,ll> P;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class RobotHerb {
public:
  long long getdist(int T, vector <int> a) {
    int period = getPeriod(a);
    P pos = getMoveDist(a, period);
  
    pos.first*=(ll)(T/period);
    pos.second*=(ll)(T/period);
    int rem = T%period;
    int d = 0;
    while(rem--){
      for(int i = 0; i < (int)a.size(); i++){
	pos.first += a[i]*dx[d];
	pos.second += a[i]*dy[d];
	d = (d+a[i])%4;
      }
    }
    return llabs(pos.first)+llabs(pos.second);
  }

  int getPeriod(const vector<int>& v){
    int move = 0;
    for(int i = 0; i < (int)v.size(); i++) move = (move+v[i])%4;
    int res = 1;
    int d = move;
    while(d != 0){
      d = (d+move)%4;
      res++;
    }
    return res;
  }

  P getMoveDist(const vector<int>& v, int period){
    P p = P(0,0);
    int d = 0;
    while(period--){
      for(int i = 0; i < (int)v.size(); i++){
	p.first  += v[i]*dx[d];
	p.second += v[i]*dy[d];
	d = (d+v[i])%4;
      }
    }
    return p;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, getdist(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, getdist(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(2, Arg2, getdist(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000000; int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 100000000000LL; verify_case(3, Arg2, getdist(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 570; int Arr1[] = {2013,2,13,314,271,1414,1732}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4112LL; verify_case(4, Arg2, getdist(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	RobotHerb ___test;
	___test.run_test(-1);
}

// END CUT HERE
