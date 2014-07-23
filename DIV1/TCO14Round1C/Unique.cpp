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

class Unique {
public:
  string removeDuplicates(string S) {
    map<char, bool> M;
    string res = "";
    for(int i = 0; i < (int)S.length(); i++){
      if(!M.count(S[i])) res += S[i];
      M[S[i]] = true;
    }
    return res;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "banana"; string Arg1 = "ban"; verify_case(0, Arg1, removeDuplicates(Arg0)); }
	void test_case_1() { string Arg0 = "aardvark"; string Arg1 = "ardvk"; verify_case(1, Arg1, removeDuplicates(Arg0)); }
	void test_case_2() { string Arg0 = "xxxxx"; string Arg1 = "x"; verify_case(2, Arg1, removeDuplicates(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "topcder"; verify_case(3, Arg1, removeDuplicates(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Unique ___test;
	___test.run_test(-1);
}

// END CUT HERE
