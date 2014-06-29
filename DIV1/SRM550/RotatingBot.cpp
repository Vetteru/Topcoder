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

typedef pair<int,int> P;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class RotatingBot {
public:
  static const int MAX = 205;
  bool used[MAX][MAX];

  int minArea(vector <int> moves) {
    memset(used,false,sizeof(used));
    int N = moves.size();
    int x = 100, y = 100;
    int lx,ty,rx,by;
    lx = ty = rx = by = 100;
    used[x][y] = true;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < moves[i]; j++){
	x += dx[i%4];
	y += dy[i%4];

	if(used[x][y]) return -1;
	used[x][y] = true;

	lx = min(lx, x);
	by = min(by, y);
	rx = max(rx, x);
	ty = max(ty, y);
      }
    }

    //    cout << lx << " " << rx << " " << ty << " " << by << endl;
    
    memset(used,false,sizeof(used));
    x = y = 100;
    used[x][y] = true;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < moves[i]; j++){
	x += dx[i%4];
	y += dy[i%4];
	used[x][y] = true;
      }
      if(i % 2 && (y == ty || y == by)) continue;
      if(!(i % 2) && (x == rx || x == lx)) continue;
      if(i == N-1) continue;
      int nx = x + dx[i%4];
      int ny = y + dy[i%4];
      if(used[nx][ny]) continue;
      return -1;
    }
    return (rx-lx+1)*(ty-by+1);
  }
	
// BEGIN CUT HERE

  void test() {
    int Arr0[] = {4,3,5,4,6,1};
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = -1;
    verify_case(8, Arg1, minArea(Arg0));
  }

	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
	void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
	void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
	void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	RotatingBot ___test;
	___test.run_test(-1);
	___test.test();
}

// END CUT HERE
