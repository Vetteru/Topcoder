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

typedef pair<int,int> P;

#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class AlienAndHamburgers {
public:
  static const int MAX = 101;
  static const int INF = (1<<28);

  int getNumber(vector <int> type, vector <int> taste) {
    int N = type.size();
    map<int, int> M;

    for(int i = 0; i < N; i++)  if(taste[i] > 0) M[type[i]] += taste[i];
    for(int i = 0; i < N; i++){
      if(M.count(type[i]) == 0) M[type[i]] = taste[i];
      else if(M[type[i]] < 0) M[type[i]] = max(M[type[i]], taste[i]);
    }

    int dp[MAX];
    fill(dp, dp+MAX,-INF);
    dp[0] = 0;
    for(int i = 0; i < MAX; i++){
      if(M.count(i) == 0) continue;
      for(int j = MAX-2; j >= 0; j--){
	if(dp[j] == -INF) continue;
	dp[j+1] = max(dp[j+1], dp[j]+M[i]);
      }
    }

    int ans = 0;
    for(int i = 1; i < MAX; i++){
      if(dp[i] < 0) continue;
      ans = max(ans, i*dp[i]);
    }
    return ans;
  }

 

// BEGIN CUT HERE

  void fail_case() {
    int Arr0[] = {1, 6, 68, 27, 63, 51, 79, 12, 91, 89, 11, 53, 74, 54};
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] =  {-60720, -60881, -37279, -68765, -54138, 35290, -3032, -72892, -58124, 79503, -23294, 49853, -98832, 40201};
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1071126; verify_case(-1, Arg2, getNumber(Arg0, Arg1));
  }

	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 54; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {30, 20, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100000, -100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 400000; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	AlienAndHamburgers ___test;
	___test.run_test(-1);
	___test.fail_case();
}

// END CUT HERE
