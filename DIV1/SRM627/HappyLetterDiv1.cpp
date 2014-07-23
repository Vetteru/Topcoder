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

class HappyLetterDiv1 {
public:
  string getHappyLetters(string letters) {
    map<char, int> M;
    for(int i = 0; i < (int)letters.length(); i++) M[letters[i]]++;
    string str = letters;
    sort(ALL(str));
    str.erase(unique(ALL(str)), str.end());
    string res = "";
    for(int i = 0; i < (int)str.length(); i++) if(possible(str[i], M)) res += str[i];
    return res;
  }

  bool possible(char c, map<char,int> M){
    while(1){
      char a = '?', b = '?';
      for(char i = 'a'; i <= 'z'; i++){
        if(i == c) continue;
        if(M[a] <= M[i] && M[i] > 0){
          b = a;
          a = i;
        }else if(M[b] < M[i] && M[i] > 0){
          b = i;
        }
      }
      if(a == '?' || b == '?') break;
      M[a]--; M[b]--;
    }
    
    int cnt = 0;
    for(char i = 'a'; i <= 'z'; i++) if(i != c) cnt += M[i];
    return cnt < M[c];
  }

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	HappyLetterDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
