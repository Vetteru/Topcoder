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

bool isPrime(int a){ for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class LoadBalancing {
public:
  static const int MAX = 205000;

  int minTime(vector <int> chunkSizes) {
    int N = chunkSizes.size();
    for(int i = 0; i < N; i++) chunkSizes[i]/=1024;

    vector<bool> dp(MAX,false);
    dp[0] = true;
    for(int i = 0; i < N; i++)
      for(int j = MAX-1; j >= 0; j--)
	if(dp[j] && j+chunkSizes[i] < MAX) dp[j+chunkSizes[i]] = true;

    int total = 0;
    for(int i = 0; i < N; i++) total += chunkSizes[i];

    int ans = MAX;
    for(int i = 0; i < MAX; i++)
      if(dp[i]) ans = min(ans, max(i,total-i));

    return ans*1024;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3072, 3072, 7168, 3072, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9216; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = {2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2048; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = {2048, 1024, 1024, 2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3072; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = {4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 104857600; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	LoadBalancing ___test;
	___test.run_test(-1);
}

// END CUT HERE
