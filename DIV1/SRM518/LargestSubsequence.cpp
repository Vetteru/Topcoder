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
using namespace std;
class LargestSubsequence {
	public:
	string getLargest(string s) {
	  string ans = "";
	  int pos = 0;
	 
	  while(pos < s.length()){
	    int tmp = pos;

	    for(int i = pos; i < s.length(); i++)
	      if(s[tmp] < s[i]) tmp = i;
	    
	    ans += s[tmp];
	    pos = tmp+1;
	  }
	  return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "test"; string Arg1 = "tt"; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "a"; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arg0 = "example"; string Arg1 = "xple"; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arg0 = "aquickbrownfoxjumpsoverthelazydog"; string Arg1 = "zyog"; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	LargestSubsequence ___test;
	___test.run_test(-1);
}

// END CUT HERE
