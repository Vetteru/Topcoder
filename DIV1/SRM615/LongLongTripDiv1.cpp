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
static const int MAX = 20001;
static const ll INF = LLONG_MAX;

class LongLongTripDiv1 {
public:
  ll dist[MAX][51];

  string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T) {
    vector<Edge> E[51];
    for(int i = 0; i < 51; i++) E[i].clear();

    for(int i = 0; i < (int)A.size(); i++){
      E[A[i]].push_back((Edge){B[i], D[i]});
      E[B[i]].push_back((Edge){A[i], D[i]});
    }

    ll M = MAX;
    for(int i = 0; i < (int)A.size(); i++)
      if(A[i] == 0 || B[i] == 0) M = min(M, 2LL*(ll)D[i]);

    if(M == MAX) return "Impossible";
    
    fill(dist[0], dist[0]+MAX*51LL, INF);
    priority_queue<State> Q;
    Q.push((State){0, 0});
    dist[0][0] = 0;

    while(!Q.empty()){
      const State now = Q.top();
      Q.pop();
      
      if(dist[now.t%M][now.pos] < now.t) continue;

      for(int i = 0; i < (int)E[now.pos].size(); i++){
        State nex = now;
        nex.pos = E[now.pos][i].to;
        nex.t += E[now.pos][i].cost;
        if(dist[nex.t%M][nex.pos] > nex.t){
          dist[nex.t%M][nex.pos] = nex.t;
          Q.push(nex);
        }
      }
    }
    return (dist[T%M][N-1]<=T?"Possible":"Impossible");
  }
	
  struct State{
    ll t, pos;
    bool operator < (const State& st) const {
      return t > st.t;
    }
  };

  struct Edge{ll to, cost;};
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7,6,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 11LL; string Arg5 = "Possible"; verify_case(0, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7,6,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 25LL; string Arg5 = "Possible"; verify_case(1, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 9LL; string Arg5 = "Possible"; verify_case(2, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1000000000000000000LL; string Arg5 = "Impossible"; verify_case(3, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 4; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,10,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1000LL; string Arg5 = "Impossible"; verify_case(4, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 9; int Arr1[] = {4,8,5,8,3,6,2,6,7,6,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,7,1,5,1,3,1,1,5,4,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 937186357646035002LL; string Arg5 = "Impossible"; verify_case(5, Arg5, isAble(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	LongLongTripDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
