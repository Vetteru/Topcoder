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

const int MAX = 1001;
vector<int> G[MAX];
bool used[MAX];
BIT bit(1005);

class GraphInversions {
public:
  int ans;
  vector<int> vec;

  int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
    int N = A.size();
    for(int i = 0; i < MAX; i++) G[i].clear();
    for(int i = 0; i < N; i++){
      G[A[i]].push_back(B[i]);
      G[B[i]].push_back(A[i]);
    }
    vec = V;
    ans = INT_MAX;
    memset(used, false, sizeof(used));
    for(int i = 0; i < N; i++){
      bit.add(vec[i], 1);
      used[i] = true;
      rec(i, K-1, 0);
      used[i] = false;
      bit.add(vec[i], -1);
    }
    return (ans==INT_MAX?-1:ans);
  }

  void rec(int pos, int rem, int cost){
    if(rem <= 0) ans = min(ans,cost);
    for(int i = 0; i < (int)G[pos].size(); i++){
      if(used[G[pos][i]]) continue;

      int nex_cost = cost + bit.sum(1001)-bit.sum(vec[G[pos][i]]);

      bit.add(vec[G[pos][i]], 1);
      used[G[pos][i]] = true;
      rec(G[pos][i], rem-1, nex_cost);
      used[G[pos][i]] = false;
      bit.add(vec[G[pos][i]], -1);
    }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,50,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(0, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60,40,50,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,2,5,3,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = -1; verify_case(3, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5,7,7,5,5,7,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,2,0,1,4,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,10,5,30,22,10,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 3; verify_case(4, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	GraphInversions ___test;
	___test.run_test(-1);
}

// END CUT HERE
