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

typedef pair<int,int> P;

class PairGame {
public:
  int maxSum(int a, int b, int c, int d) {
    set<P> A = find(a,b),B = find(c,d);
    int res = -1;
    for(set<P>::iterator ite = A.begin(); ite != A.end(); ite++){
      if(B.find(*ite) != B.end()) res = max(res, ite->first+ite->second);
    }
    return res;
  }
  
  set<P> find(int a, int b){
    set<P> res;
    queue<P> Q;
    Q.push(P(a,b));
    while(!Q.empty()){
      const P now = Q.front(); Q.pop();
      if(res.find(now) != res.end()) continue;
      res.insert(now);
      if(now.second-now.first >= 0)Q.push(P(now.first, now.second-now.first));
      if(now.first-now.second >= 0)Q.push(P(now.first-now.second, now.second));
    }
    return res;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arg4 = 7; verify_case(1, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; int Arg4 = -1; verify_case(2, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1001; int Arg2 = 2000; int Arg3 = 2001; int Arg4 = 1001; verify_case(3, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10944; int Arg1 = 17928; int Arg2 = 7704; int Arg3 = 21888; int Arg4 = 144; verify_case(4, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(5, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	PairGame ___test;
	___test.run_test(-1);
}

// END CUT HERE
