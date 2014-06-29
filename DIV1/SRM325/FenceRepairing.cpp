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


const int MAX = 2600;
const double INF = 1e100;
double dp[MAX];

class FenceRepairing {
public:
  double calculateCost(vector <string> boards) {

    for(int i = 0; i < MAX; i++) dp[i] = INF;
    string str = "";
    for(int i = 0; i < (int)boards.size(); i++) str += boards[i];
    int N = str.length();
    dp[0] = 0;
    for(int i = 0; i < N; i++){
      if(dp[i] == INF) continue;
      int len = 0, fixed = 0;
      for(int j = i; j < N; j++){
        if(str[j] == 'X'){
          len += fixed+1;
          fixed = 0;
        }else{
          fixed++;
        }
        dp[j+1] = min(dp[j+1], dp[i]+sqrt(len));
      }
    }
    return dp[N];
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X...X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(0, Arg1, calculateCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.X.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.732050807568877; verify_case(1, Arg1, calculateCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"X.......", "......XX", ".X......", ".X...X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(2, Arg1, calculateCost(Arg0)); }
	void test_case_3() { string Arr0[] = {".X.......X", "..........", "...X......", "...X..X...", "..........",
 "..........", "..X....XX.", ".........X", "XXX", ".XXX.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.591663046625438; verify_case(3, Arg1, calculateCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	FenceRepairing ___test;
	___test.run_test(-1);
}

// END CUT HERE
