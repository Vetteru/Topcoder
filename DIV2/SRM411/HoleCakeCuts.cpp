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

class HoleCakeCuts {
public:
  static const int MAX = 205;
  bool come[MAX][MAX];
  bool cv[MAX], ch[MAX];
  int lim;
  int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts) {
    memset(come, false, sizeof(come));
    memset(cv, false, sizeof(cv));
    memset(ch, false, sizeof(ch));

    int origin = cakeLength;
    lim = 2 * cakeLength;

    for(int i = 0; i < (int)horizontalCuts.size(); i++) horizontalCuts[i] += origin;
    for(int i = 0; i < (int)verticalCuts.size(); i++) verticalCuts[i] += origin;
    
    for(int i = 0; i < (int)horizontalCuts.size(); i++) ch[horizontalCuts[i]] = true;
    for(int i = 0; i < (int)verticalCuts.size(); i++) cv[verticalCuts[i]] = true;

    int C = cakeLength;
    int H = holeLength;

    for(int i = C-H; i < C+H; i++)
      for(int j = C-H; j < C+H; j++) come[i][j] = true;

    int ans = 0;
    for(int i = 0; i < 2*C; i++)
      for(int j = 0; j < 2*C; j++)
	if(!come[i][j]){
	  ans++;
	  dfs(i,j);
	}
    return ans;
  }


  void dfs(int i, int j){
    if(come[i][j]) return;
    come[i][j] = true;
    if(i > 0 && !ch[i]) dfs(i-1,j);
    if(i < lim-1 && !ch[i+1]) dfs(i+1,j);
    if(j > 0 && !cv[j]) dfs(i, j-1);
    if(j < lim-1 && !cv[j+1]) dfs(i, j+1);
  }

// BEGIN CUT HERE

  void fail_case() {
    int Arg0 = 25;
    int Arg1 = 15;
    int Arr2[] = {-17, 12, 13, 14, 15};
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {20, 24, -1, -20, -22, -9};
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arg4 = 39;
    verify_case(4, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3));
  }
  
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, -4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(0, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-2, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(2, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 5; int Arr2[] = {40, -40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 0, -20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 12; verify_case(3, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	HoleCakeCuts ___test;
	___test.run_test(-1);
	___test.fail_case();
}

// END CUT HERE
