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

int orthX[] = {0,1,0,-1};
int orthY[] = {1,0,-1,0};
int diagX[] = {1,1,-1,-1};
int diagY[] = {1,-1,1,-1};

class HappyCells {
public:
  vector<string> field;
  int H,W;
  vector <int> getHappy(vector <string> grid) {
    vector<int> ans(3,0);
    field = grid;
    H = grid.size();
    W = grid[0].size();

    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++){
	if(field[i][j] == 'X') continue;
	if(h1(i,j)) ans[0]++;
	if(h2(i,j)) ans[1]++;
	if(h3(i,j)) ans[2]++;
      }
    return ans;
  }


  bool isInside(int h, int w){return 0<=h&&h<H&&0<=w&&w<W;}

  int h1(int h, int w){
    for(int i = 0; i < 4; i++){
      int nx = w+orthX[i];
      int ny = h+orthY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return false;
    }

    for(int i = 0; i < 4; i++){
      int nx = w+diagX[i];
      int ny = h+diagY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return false;
    }
    return true;
  }

  int h2(int h, int w){
    for(int i = 0; i < 4; i++){
      int nx = w+orthX[i];
      int ny = h+orthY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return false;
    }
    
    for(int i = 0; i < 4; i++){
      int nx = w+diagX[i];
      int ny = h+diagY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return true;
    }
    return false;
  }

  int h3(int h, int w){
    for(int i = 0; i < 4; i++){
      int nx = w+diagX[i];
      int ny = h+diagY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return false;
    }
    
    for(int i = 0; i < 4; i++){
      int nx = w+orthX[i];
      int ny = h+orthY[i];
      if(!isInside(ny, nx)) continue;
      if(field[ny][nx] == '.') return true;
    }
    return false;
  }

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXX",
"X.X",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getHappy(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getHappy(Arg0)); }
	void test_case_2() { string Arr0[] = {
"XXXXXX",
"X.XXXX",
"XXX.XX",
"X..XXX",
"XXXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getHappy(Arg0)); }
	void test_case_3() { string Arr0[] = {"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getHappy(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	HappyCells ___test;
	___test.run_test(-1);
}

// END CUT HERE
