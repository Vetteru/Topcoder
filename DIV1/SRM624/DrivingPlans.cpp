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

typedef long long ll;
typedef pair<ll,ll> P;
const int MAX = 2001;
const ll mod = 1000000009;
vector<P> E[MAX];
struct State{
  int pos, t;
  bool operator < (const State& st) const { return t > st.t; }
};

class DrivingPlans {
public:

  int count(int N, vector <int> A, vector <int> B, vector <int> C) {
    //SRM624 Div1 450
    for(int i = 0; i < MAX; i++) E[i].clear();
    for(int i = 0; i < (int)A.size(); i++){
      E[A[i]-1].push_back(P(B[i]-1, C[i]));
      E[B[i]-1].push_back(P(A[i]-1, C[i]));
    }

    vector<P> sp = dijkstra(0, N), rsp = dijkstra(N-1, N);
    for(int i = 0; i < N; i++){
      if(sp[i].first+rsp[i].first == sp[N-1].first && hasZero(i)) return -1;
    }
    return sp[N-1].second;
  }

  bool hasZero(int n){
    for(int i = 0; i < (int)E[n].size(); i++)
      if(E[n][i].second == 0) return true;
    return false;
  }

  vector<P> dijkstra(int src, int size){
    vector<P> res(size, P(INT_MAX,0));
    res[src] = P(0,1);
    priority_queue<State> Q;
    Q.push((State){src, 0});
    while(!Q.empty()){
      const State now = Q.top(); Q.pop();

      if(res[now.pos].first < now.t) continue;

      for(int i = 0; i < (int)E[now.pos].size(); i++){
        State nex = now;
        nex.pos = E[now.pos][i].first;
        nex.t += E[now.pos][i].second;
        
        if(res[nex.pos].first == nex.t){
          res[nex.pos].second = (res[nex.pos].second+res[now.pos].second)%mod;
        }else if(res[nex.pos].first > nex.t){
          res[nex.pos].first = nex.t;
          res[nex.pos].second = res[now.pos].second;
          Q.push(nex);
        }
      }
    }
    return res;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	DrivingPlans ___test;
	___test.run_test(-1);
}

// END CUT HERE
