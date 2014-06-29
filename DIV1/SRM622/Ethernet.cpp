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

typedef pair<int,int> P;
const int MAX = 51;

class Ethernet {
public:
  vector<P> G[MAX];
  int dp[MAX][501], maxD;
  
  int connect(vector <int> parent, vector <int> dist, int maxDist) {
    for(int i = 0; i < MAX; i++) G[i].clear();
    for(int i = 0; i < (int)parent.size(); i++) G[parent[i]].push_back(P(i+1, dist[i]));
    maxD = maxDist;
    memset(dp, -1, sizeof(dp));
    return rec(0, maxDist);
  }

  int rec(int pos, int rem){
    if(dp[pos][rem] != -1) return dp[pos][rem];
    
    int res = 0;
    for(int i = 0; i < (int)G[pos].size(); i++) res += rec(G[pos][i].first, maxD);

    for(int i = 0; i < (int)G[pos].size(); i++){
      for(int m = G[pos][i].second; m <= rem; m++){
        int tmp = rec(G[pos][i].first, m-G[pos][i].second);
        for(int j = 0; j < (int)G[pos].size(); j++){
          if(i == j) continue;
          int remD = min(m, maxD-m);
          if(G[pos][j].second > remD) tmp += rec(G[pos][j].first, maxD);
          else tmp += min(rec(G[pos][j].first, remD-G[pos][j].second), rec(G[pos][j].first, maxD));
        }
        res = min(res, tmp);
      }
    }
    return dp[pos][rem] = res+(rem==maxD?1:0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 162; int Arg3 = 11; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Ethernet ___test;
	___test.run_test(-1);
}

// END CUT HERE
