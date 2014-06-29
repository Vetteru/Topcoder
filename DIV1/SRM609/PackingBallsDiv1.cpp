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

typedef long long ll;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class PackingBallsDiv1 {
public:
  int minPacks(int K, int A, int B, int C, int D) {
    //SRM609
    vector<ll> v(K);
    v[0] = A;
    for(int i = 1; i < K; i++) v[i] = (v[i-1]*(ll)B+(ll)C)%(ll)D+1LL;
    long long tmp = 0;
    for(int i = 0; i < K; i++) tmp+=v[i]/K, v[i]%=K;

    sort(ALL(v));
    long long ans = tmp+K;
    for(int i = 0; i < K; i++) ans = min(ans, tmp+v[i]+K-(i+1));
    return ans;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 6; int Arg5 = 4; verify_case(0, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 23; int Arg3 = 39; int Arg4 = 93; int Arg5 = 58; verify_case(1, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 10988; int Arg2 = 5573; int Arg3 = 4384; int Arg4 = 100007; int Arg5 = 47743; verify_case(2, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 123456789; int Arg2 = 234567890; int Arg3 = 345678901; int Arg4 = 1000000000; int Arg5 = 331988732; verify_case(3, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	PackingBallsDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
