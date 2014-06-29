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

typedef long long ll;
typedef pair<bool, ll> P;

#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class Suminator {
public:

  int findMissing(vector <int> program, int wantedResult) {
    int pos = -1;
    for(int i = 0; i < (int)program.size(); i++) if(program[i] == -1) pos = i;

    program[pos] = 0;
    if(simulate(program) == wantedResult) return 0;
    program[pos] = -1;
    ll tmp = simulate(program);
    bool used = check(program);
    if(!used && tmp == wantedResult) return 0;
    if(used && tmp+1 < wantedResult) return wantedResult-tmp-1;
    return -1;
  }

  bool check(const vector<int>& v){
    vector<bool> res(v.size(), false);
    for(int i = 0; i < (int)v.size(); i++) if(v[i] == -1) res[i] = true;
    stack<int> st;
    for(int i = 0; i < (int)v.size(); i++){
      if(v[i] == 0){
	bool a = false, b = false;
	if(!st.empty()){a = st.top(); st.pop();}
	if(!st.empty()){b = st.top(); st.pop();}
	st.push(a||b);
      }else{
	st.push(res[i]);
      }
    }
    return st.empty()?false:st.top();
  }

  ll simulate(const vector<int>& v){
    stack<ll> st;
      for(int i = 0; i < (int)v.size(); i++){
      if(v[i] == 0){
	ll a = 0, b = 0;
	if(!st.empty()) {a = st.top(); st.pop();}
	if(!st.empty()) {b = st.top(); st.pop();}
	st.push(a+b);
      }else{
	st.push(v[i]);
      }
    }
    return st.empty()?0:st.top();;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Suminator ___test;
	___test.run_test(-1);
}

// END CUT HERE
