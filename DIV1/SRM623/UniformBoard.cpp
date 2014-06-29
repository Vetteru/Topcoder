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

class UniformBoard {
public:
  vector<string> grid;
  int getBoard(vector <string> board, int K) {
    //SRM 623 DIV1 300
    grid = board;
    int N = board.size();
    int apple = count(0,0,N,N,'A'), ans = 0;
    int space = count(0,0,N,N,'.');

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        for(int k = i+1; k <= N; k++)
          for(int l = j+1; l <= N; l++){
            int pear = count(i,j,k,l,'P');
            int dot = count(i,j,k,l,'.');
            if(2*pear+dot <= K && (space > 0 || pear == 0) && apple >= (k-i)*(l-j)) ans = max(ans, (k-i)*(l-j));
          }
    return ans;
  }

  int count(int x0, int y0, int x1, int y1, char c){
    int res = 0;
    for(int i = y0; i < y1; i++)
      for(int j = x0; j < x1; j++)
        if(grid[i][j]==c) res++;
    return res;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	UniformBoard ___test;
	___test.run_test(-1);
}

// END CUT HERE
