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
using namespace std;
class Embassy {
	public:
	int visaApplication(vector <int> forms, int dayLength, int openTime) {
	  if(forms.size() == 1) return forms[0];

	  long long ans = (1LL<<50);


	  const int MAX = 1e6;

	  for(int X = 0; X <= MAX; X++){
	    long long res = 0;
	    long long now = X;
	    for(int i = 0; i < forms.size(); i++){
	      if(now+forms[i] <= openTime){
		res += forms[i];
		now += forms[i];
	      }else{
		res += forms[i];
		now += forms[i];
		if(now < dayLength){
		  res += dayLength-now;
		  now = 0;
		}else{
		  now %= dayLength;
		  if(now > openTime){
		    res += dayLength-now;
		    now = 0;
		  }
		}
	      }
	    }
	    ans = min(ans,res);
	  }
	  return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 12; verify_case(0, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 28; verify_case(1, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 1; int Arg3 = 73; verify_case(2, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1440; int Arg2 = 360; int Arg3 = 16945; verify_case(3, Arg3, visaApplication(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	Embassy ___test;
	___test.run_test(-1);
}

// END CUT HERE
