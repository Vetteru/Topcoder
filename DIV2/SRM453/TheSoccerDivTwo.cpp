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

class TheSoccerDivTwo {
public:
  int find(vector <int> points) {
    //SRM453
    int we = points[0]+3;
    int win = 0, lose = 0, draw = 0, unknown = 0;
    int N = points.size();

    for(int i = 1; i < N; i++){
      if(we < points[i]) win++;
      else if(we >= points[i]+3) lose++;
      else if(points[i]+1 <= we && we < points[i]+3) draw++;
      else unknown++;
    }

    draw = draw%2;

    int tmp = 0;
    if(unknown > 0) unknown--;
    else if(draw > 0) draw--;
    else if(win > 0){tmp++; win--;}
    else lose--;
    
    int remain = max(0,win+lose-unknown);
    unknown = max(0, unknown - win - lose);
    draw = max(0, draw-remain);
    return win+unknown/2+draw+1+tmp;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 7, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {5, 9, 11, 9, 10, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TheSoccerDivTwo ___test;
	___test.run_test(-1);
}

// END CUT HERE
