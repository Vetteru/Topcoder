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
class ORSolitaire {
public:
  int getMinimum(vector <int> numbers, int goal) {
    vector<int> v = make(numbers, goal);

    int bit[50] = {0};

    for(int i = 0; i < (int)v.size(); i++){
      for(int j = 0; j < 31; j++)
	if(v[i] & (1<<j)) bit[j]++;
    }

    int ans = 1000;
    for(int i = 0; i < 31; i++)
      if(goal & (1<<i)) ans = min(ans, bit[i]);
    return ans;
  }

  vector<int> make(const vector<int> v, int g){
    vector<int> res;
    for(int i = 0; i < (int)v.size(); i++){
      bool f = true;
      for(int j = 0; j < 31; j++){
	if((1<<j)&v[i] && !((1<<j)&g)) f = false;
      }
      if(f) res.push_back(v[i]);
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 1; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 4, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 2; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12571295, 2174218, 2015120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,2,4,52,62,9,8,3,1,11,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 3; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 510; int Arg2 = 5; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	ORSolitaire ___test;
	___test.run_test(-1);
}

// END CUT HERE
