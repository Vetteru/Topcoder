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
#include <cassert>
using namespace std;
class StrIIRec {
public:
  string recovstr(int n, int minInv, string minStr) {
    string s = "";
    for(int i = 0; i < n; i++) s += 'a'+i;
    return rec(s, minInv, minStr);
  }

  string rec(string rem, int inv, string minStr){
    if(rem == "") return "";

    //cout << rem << " " << inv << " " << minStr << endl;
    
    for(int i = 0; i < (int)rem.length(); i++){
      
      if(minStr.length() > 0 && minStr[0] > rem[i]) continue;
      
      int tmp = rem.length()-1;
      int nexInv = max(inv-i,0);
      if(tmp*(tmp-1)/2 < nexInv) continue;

      string nexStr = "";
      string nexRem = rem.substr(0,i)+rem.substr(i+1);
    
      if(minStr.length() > 0 && minStr[0] == rem[i]) nexStr = minStr.substr(1);
      return string(1,rem[i]) + rec(nexRem, nexInv, nexStr);
    }
    return "";
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	StrIIRec ___test;
	___test.run_test(-1);
}

// END CUT HERE
