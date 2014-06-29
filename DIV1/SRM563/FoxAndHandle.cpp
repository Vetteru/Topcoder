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
#include <cassert>

using namespace std;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class FoxAndHandle {
public:
  static const int MAX = 55;
  string lexSmallestName(string S) {
    //SRM563
    map<char,int> M,need,can[MAX];
    int remain = 0;
    for(int i = 0; i < (int)S.length(); i++) M[S[i]]++;
    for(char c = 'a'; c <= 'z'; c++){
      need[c] = M[c]/2;
      remain += need[c];
    }

    map<char,int> now;
    for(int i = S.length()-1; i >= 0; i--){
      now[S[i]]++;
      can[i] = now;
    }

    string res = "";
    int cur = -1;

    while(remain--){
      int pos = -1;
      for(int i = cur+1; i < (int)S.size(); i++){
	if(canDo(can[i], need) && (pos == -1 || S[pos] > S[i]) && need[S[i]] > 0) pos = i;
      }

      need[S[pos]]--;
      res += S[pos];
      cur = pos;
    }
    return res;
  }

  bool canDo(map<char, int> state, map<char, int> req){
    for(char c = 'a'; c <= 'z'; c++){
      if(req[c] > state[c] && req[c] > 0) return false;
    }
    return true;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "foxfox"; string Arg1 = "fox"; verify_case(0, Arg1, lexSmallestName(Arg0)); }
	void test_case_1() { string Arg0 = "ccieliel"; string Arg1 = "ceil"; verify_case(1, Arg1, lexSmallestName(Arg0)); }
	void test_case_2() { string Arg0 = "abaabbab"; string Arg1 = "aabb"; verify_case(2, Arg1, lexSmallestName(Arg0)); }
	void test_case_3() { string Arg0 = "bbbbaaaa"; string Arg1 = "bbaa"; verify_case(3, Arg1, lexSmallestName(Arg0)); }
	void test_case_4() { string Arg0 = "fedcbafedcba"; string Arg1 = "afedcb"; verify_case(4, Arg1, lexSmallestName(Arg0)); }
	void test_case_5() { string Arg0 = "nodevillivedon"; string Arg1 = "deilvon"; verify_case(5, Arg1, lexSmallestName(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	FoxAndHandle ___test;
	___test.run_test(-1);
}

// END CUT HERE
