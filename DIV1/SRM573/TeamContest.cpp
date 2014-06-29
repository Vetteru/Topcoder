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

class TeamContest {
public:
  int worstRank(vector <int> strength) {
    vector<int>& v = strength;
    int us = 0;
    int maxV, minV;
    maxV = minV = strength[0];

    for(int i = 0; i < 3; i++){
      maxV = max(maxV, v[i]);
      minV = min(minV, v[i]);
    }
    us = maxV+minV;
    
    vector<int> rem(v.size()-3);
    for(int i = 0; i < (int)rem.size(); i++) rem[i] = v[i+3];

    sort(rem.begin(),rem.end());
    return 1+find(rem, us);
  }

  int find(const vector<int>& v, int us){
    bool used[50] = {false};
    int cnt = 0;
    for(int i = (int)v.size()-1; i >= 0; i--){
      if(used[i]) continue;
      int x = i, y = -1, z = -1; 
      
      for(int j = 0; j < (int)v.size(); j++){
	if(used[j]) continue;
	if(v[x]+v[j] > us){
	  z = j;
	  break;
	}
      }

      
      y = z+1;
      if(!(x > y && y > z) || z == -1) break;
      used[x] = used[y] = used[z] = true;
      cnt++;
    }
    return cnt;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 7, 3, 5, 7, 3, 5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, worstRank(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 7, 3}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, worstRank(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, worstRank(Arg0)); }
	void test_case_3() { int Arr0[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, worstRank(Arg0)); }
	void test_case_4() { int Arr0[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, worstRank(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TeamContest ___test;
	___test.run_test(-1);
}

// END CUT HERE
