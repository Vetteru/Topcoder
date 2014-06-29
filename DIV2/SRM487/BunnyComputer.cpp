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
using namespace std;

class BunnyComputer {
public:
  vector<int> pre;
  long long diff;
  
  int rec(int score, long long used, long long now){
    if(now >= (int)pre.size()) return score;
    
    int res = 0;
    long long nex = (1LL<<now)|(1LL<<(now+diff+1));
        
    if(!(used&nex) && now+diff+1 < (int)pre.size()) res = rec(score+pre[now]+pre[now+diff+1], used|nex, now+1);
    
    if(now-diff-1 >= 0){
      long long pre = (1LL<<(now-diff-1));
      if(!(used&pre)) return res;
    }
    return max(res,rec(score,used,now+1));
  }

  int getMaximum(vector <int> preference, int k) {
    pre = preference;
    diff = k;
    return rec(0,0,0);
  }
	
// BEGIN CUT HERE
	public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 28; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 31; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 14; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 487, 2010 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	BunnyComputer ___test;
	___test.run_test(-1);
}

// END CUT HERE
