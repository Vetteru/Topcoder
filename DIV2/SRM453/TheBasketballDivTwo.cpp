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

using namespace std;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class TheBasketballDivTwo {
public:

  static const int INF = (1<<28);
  vector<string> result;
  int N;
  int find(vector <string> table) {
    N = table.size();
    result = table;
    return rec(0);
  }

  int rec(int pos){
    int H = pos/N;
    int W = pos%N;
    int res = INF;

    if(pos >= N*N){
      int win[N];
      for(int i = 0; i < N; i++) win[i] = 0;
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++){
	  if(result[i][j] == 'W') win[i]++;
	  if(result[i][j] == 'L') win[j]++;
	}

      int maxWin = 0;
      for(int i = 0; i < N; i++) maxWin = max(maxWin, win[i]);
      return maxWin;
    }

    if(result[H][W] == '?'){
      result[H][W] = 'W';
      res = min(res, rec(pos+1));
      result[H][W] = 'L';
      res = min(res, rec(pos+1));
      result[H][W] = '?';
    }else return rec(pos+1);
    return res;
  }

  
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X?", "?X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"XW", "LX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"XWL", "?XW", "WLX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"XW?", "LX?", "??X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TheBasketballDivTwo ___test;
	___test.run_test(-1);
}

// END CUT HERE
