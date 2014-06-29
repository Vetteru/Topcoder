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

class MagicalStringDiv1 {
public:
  int getLongest(string S) {
    int R[55] = {0};
    int L[55] = {0};

    int cnt = 0;
    for(int i = 0; i <= (int)S.length(); i++){
      R[i] = cnt;
      if(i < (int)S.length() && S[i] == '<') cnt++;
    }

    cnt = 0;
    for(int i = 0; i <= (int)S.length(); i++){
      L[i] = cnt;
      if(i < (int)S.length() && S[i] == '>') cnt++;
    }

    int ans = 0;
    for(int i = 0; i <= (int)S.length(); i++){
      ans = max(ans, 2*min(L[i]-L[0], R[S.length()]-R[i]));
    }
    return ans;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<><><<>"; int Arg1 = 4; verify_case(0, Arg1, getLongest(Arg0)); }
	void test_case_1() { string Arg0 = ">>><<<"; int Arg1 = 6; verify_case(1, Arg1, getLongest(Arg0)); }
	void test_case_2() { string Arg0 = "<<<>>>"; int Arg1 = 0; verify_case(2, Arg1, getLongest(Arg0)); }
	void test_case_3() { string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"; int Arg1 = 24; verify_case(3, Arg1, getLongest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	MagicalStringDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
