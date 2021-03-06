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

class TrueSpace {
public:
  long long calculateSpace(vector <int> sizes, int clusterSize) {
    long long ans = 0;
    for(int i = 0; i < (int)sizes.size(); i++){
      long long n = sizes[i]/clusterSize;
      if(sizes[i]%clusterSize) n++;
      ans += n*clusterSize;
    }
    return ans;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 512; long long Arg2 = 1024LL; verify_case(0, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {16,32,128,128,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32768; long long Arg2 = 131072LL; verify_case(1, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4096, 33792, 76800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1024; long long Arg2 = 114688LL; verify_case(2, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1048576; long long Arg2 = 50017075200LL; verify_case(3, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; long long Arg2 = 0LL; verify_case(4, Arg2, calculateSpace(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TrueSpace ___test;
	___test.run_test(-1);
}

// END CUT HERE
