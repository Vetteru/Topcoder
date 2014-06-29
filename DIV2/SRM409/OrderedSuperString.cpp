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

class OrderedSuperString {
public:
  int getLength(vector <string> words) {
    string ans = words[0];
    int pos = 0;
    
    for(int i = 1; i < (int)words.size(); i++){
      pos = getOverlap(ans, words[i], pos);
      ans += words[i].substr(min((int)ans.length()-pos, (int)words[i].length()));
    }
    return ans.length();
  }

  int getOverlap(const string& s, const string& w, int pos){
    for(int i = pos; i < (int)s.length(); i++){
      bool diff = false;
      int cnt = 0;
      for(int j = 0; j < (int)w.length() && i+j < (int)s.length(); j++){
	if(w[j] != s[i+j]) diff = true;
	cnt++;
      }
      if(!diff) return i;
    }
    return s.length();
  }
// BEGIN CUT HERE

  void test() {
    string Arr0[] = {"aa","a","a"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    verify_case(1, Arg1, getLength(Arg0));
  }

  void test2() {
    string Arr0[] = {"aaaaaaaaaaabaaaaaaaa", "bac", "aaaabacaaa", "ab", "ba", "a", "ca"};
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 33;
    verify_case(2, Arg1, getLength(Arg0));
  }
  
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abc","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","a","b","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcdef", "ab","bc", "de","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"ab","bc", "de","ef","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	OrderedSuperString ___test;
	___test.run_test(-1);
	___test.test();
	___test.test2();
}

// END CUT HERE
