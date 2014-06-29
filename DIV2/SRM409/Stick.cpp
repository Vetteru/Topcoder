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

class Stick {
public:
  int pieces(int x) {
    priority_queue<int, vector<int>, greater<int> > Q;
    int ans = 1;
    int len = 64;
    Q.push(len);
    
    while(x < len){
      int t = Q.top();
      Q.pop();
      if(len - t/2 >= x){
	len -= t/2;
	Q.push(t/2);
      }else{
	Q.push(t/2);
	Q.push(t/2);
	ans++;
      }
    }
    return ans;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 32; int Arg1 = 1; verify_case(0, Arg1, pieces(Arg0)); }
	void test_case_1() { int Arg0 = 48; int Arg1 = 2; verify_case(1, Arg1, pieces(Arg0)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 4; verify_case(2, Arg1, pieces(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Stick ___test;
	___test.run_test(-1);
}

// END CUT HERE
