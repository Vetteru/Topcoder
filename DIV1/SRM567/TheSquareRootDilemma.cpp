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

const int MAX = 80000;
vector<int> v[MAX];

class TheSquareRootDilemma {
public:


  int countPairs(int N, int M) {
   
    for(int i = 0; i < MAX; i++) v[i].clear();
    for(int i = 1; i <= max(N,M); i++){
      vector<int> p = prime_factor(i);
      v[make(p)].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= min(N,M); i++){
      ans += find(i,N)*find(i,M);
    }
    return ans;
  }

  int find(int pos, int n){
    return upper_bound(v[pos].begin(), v[pos].end(), n)-v[pos].begin();
  }
  
  int make(const vector<int>& p){
    vector<bool> used(p.size(), false);

    for(int i = 0; i < (int)p.size(); i++){
      if(used[i]) continue;
      for(int j = 0; j < (int)p.size(); j++)
	if(!used[j] && i != j && p[i] == p[j]){
	  used[i] = used[j] = true;
	  break;
	}
    }

    int res = 1;
    for(int i = 0; i < (int)p.size(); i++)
      if(!used[i]) res*=p[i];
    return res;
  }

  vector<int> prime_factor(int n){
    vector<int> res;
    for(int i = 2; i*i <= n; i++)
      while(n%i==0){
	res.push_back(i);
	n/=i;
      }
    if(n!=1) res.push_back(n);
    return res;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TheSquareRootDilemma ___test;
	___test.run_test(-1);
}

// END CUT HERE
