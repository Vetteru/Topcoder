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
class MovingAverages {
public:
  vector <int> calculate(vector <string> times, int n) {
    int T = times.size();
    vector<int> res;
    for(int i = 0; i < T-n+1; i++){
      int cnt = 0;
      for(int j = i; j < i+n; j++) cnt += Stoi(times[j]);
      cnt /= n;
      res.push_back(cnt);
    }
    return res;
  }

  int Stoi(const string& s){
    string hh = s.substr(0,2);
    string mm = s.substr(3,2);
    string ss = s.substr(6);

    // cout << hh << " " << mm << " " << ss << endl;
    
    stringstream sh(hh), sm(mm), sse(ss);

    int a,b,c;
    sh >> a;
    sm >> b;
    sse >> c;
    return a*3600+b*60+c;
  }
  
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = { 4731,  4695,  4684 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = { 4750,  4660,  4784,  4643,  4627 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = { 4692 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	MovingAverages ___test;
	___test.run_test(-1);
}

// END CUT HERE
