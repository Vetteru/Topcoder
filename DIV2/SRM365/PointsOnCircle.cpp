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

bool isPrime(int a){ for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

typedef long long ll;

class PointsOnCircle {
public:
  long long count(int r) {
    vector<ll> v = divisor(r);
    set<ll> S;

    for(int i = 0; i < (int)v.size(); i++)
      for(int j = 0; j < (int)v.size(); j++)
	S.insert(v[i]*v[j]);

    ll A = 0, B = 0;

    set<ll>::iterator ite = S.begin();
    while(ite != S.end()){
      if(*ite%4 == 1) A++;
      if(*ite%4 == 3) B++;
      ite++;
    }
    return 4LL*(A-B);
  }

  
  vector<ll> divisor(int n){
    vector<ll> res;
    for(int i = 1; i*i <= n; i++){
      if(n%i == 0){
	res.push_back(i);
	if(i != n/i) res.push_back(n/i);
      }
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2000000000; long long Arg1 = 76LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 1053; long long Arg1 = 12LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	PointsOnCircle ___test;
	___test.run_test(-1);
}

// END CUT HERE
