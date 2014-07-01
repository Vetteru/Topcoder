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

class ColorfulStrings {
public:

  string getKth(int n, int k) {
    if(n > 8) return "";
    vector<string> vec = make(n);
    int cnt = 0;
    for(int i = 0; i < (int)vec.size(); i++){
      if(is_colorful(vec[i])) cnt++;
      if(cnt == k) return vec[i];
    }
    return "";
  }

  vector<string> make(int n){
    vector<string> res;
    if(n == 1){
      for(int i = 0; i < 10; i++) res.push_back(toStr(i));
    }else{
      string s = "23456789";
      do res.push_back(s.substr(0,n)); while(next_permutation(s.begin(), s.end()));
    }
    res.erase(unique(ALL(res)), res.end());
    return res;
  }

  bool is_colorful(const string& s){
    set<int> S;
    for(int i = 0; i < (int)s.length(); i++)
      for(int j = 1; i+j <= (int)s.length(); j++){
        int tmp = 1;
        for(int k = 0; k < j; k++) tmp *= s[i+k]-'0';
        if(S.find(tmp) != S.end()) return false;
        S.insert(tmp);
      }
    return true;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "238"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2000; string Arg2 = ""; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "23457"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 22; string Arg2 = "52"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 464; string Arg2 = "257936"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ColorfulStrings ___test;
	___test.run_test(-1);
}

// END CUT HERE
