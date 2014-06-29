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

class PalindromePermutations {
public:
  double palindromeProbability(string word) {
    if(!can(word)) return 0.0;
    return perm(get_half(word))/perm(word);
  }

  string get_half(const string& s){
    int cnt[30] = {0};
    for(int i = 0; i < (int)s.length(); i++) cnt[s[i]-'a']++;
    string res = "";
    for(int i = 0; i < 30; i++)
      for(int j = 0; j < cnt[i]/2; j++) res += (i+'a');
    return res;
  }

  bool can(const string& s){
    int cnt[30] = {0};
    for(int i = 0; i < (int)s.length(); i++) cnt[s[i]-'a']++;
    int odd = 0;
    for(int i = 0; i < 30; i++) if(cnt[i]%2) odd++;
    return odd<=1;
  }

  long double perm(string s){
    long double res = fact(s.length());
    int cnt[30] = {0};
    for(int i = 0; i < (int)s.length(); i++) cnt[s[i]-'a']++;
    sort(ALL(s));
    s.erase(unique(ALL(s)), s.end());
    for(int i = 0; i < (int)s.length(); i++) res /= fact(cnt[s[i]-'a']);
    return res;
  }
	
  long double fact(int n){return (n==0?1:(long double)n*fact(n-1));}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "haha"; double Arg1 = 0.3333333333333333; verify_case(0, Arg1, palindromeProbability(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxy"; double Arg1 = 0.2; verify_case(1, Arg1, palindromeProbability(Arg0)); }
	void test_case_2() { string Arg0 = "xxxx"; double Arg1 = 1.0; verify_case(2, Arg1, palindromeProbability(Arg0)); }
	void test_case_3() { string Arg0 = "abcde"; double Arg1 = 0.0; verify_case(3, Arg1, palindromeProbability(Arg0)); }
	void test_case_4() { string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; double Arg1 = 0.025641025641025637; verify_case(4, Arg1, palindromeProbability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	PalindromePermutations ___test;
	___test.run_test(-1);
}

// END CUT HERE
