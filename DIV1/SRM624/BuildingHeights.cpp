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

class BIT{
public:
  int size;
  int* bit;

  BIT(int _size = 0){
    size = _size;
    bit = new int[size];
    for(int i = 0; i < size; i++) bit[i] = 0;
  }

  ~BIT(){delete[] bit;}

  int sum(int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i&-i;
    }
    return s;
  }

  void add(int i, int x){
    while(i<size){
      bit[i] += x;
      i += i&-i;
    }
  }
};

class BuildingHeights {
public:
  int minimum(vector <int> heights) {
    sort(ALL(heights));
    BIT bit(heights.size()+1);
    for(int i = 0; i < (int)heights.size(); i++) bit.add(i+1, heights[i]);
    int ans = 0;
    for(int i = 2; i <= (int)heights.size(); i++){
      int v = INT_MAX;
      for(int j = i; j <= (int)heights.size(); j++) v = min(v, i*heights[j-1] - (bit.sum(j)-bit.sum(j-i)));
      ans ^= v;
    }
    return ans;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 5, 4, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 1, 6, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { int Arr0[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56068; verify_case(3, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	BuildingHeights ___test;
	___test.run_test(-1);
}

// END CUT HERE
