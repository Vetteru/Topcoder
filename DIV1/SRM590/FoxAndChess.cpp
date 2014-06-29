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
class FoxAndChess {
public:
  string ableToMove(string begin, string target) {
    string F = "Impossible";
    string T = "Possible";
    if(!hasSame(begin,target)) return F;
    if(!validOrder(begin,target)) return F;
    if(!possibleMove(begin,target)) return F;
    return T;
  }

  bool hasSame(const string& a, const string& b){
    int data[3] = {0};
    string s = ".RL";
    for(int i = 0; i < a.length(); i++)
      for(int j = 0; j < s.length(); j++) if(a[i] == s[j]) data[j]++;
    
    for(int i = 0; i < b.length(); i++)
      for(int j = 0; j < s.length(); j++) if(b[i] == s[j]) data[j]--;

    for(int i = 0; i < 3; i++) if(data[i] != 0) return false;
    return true;
  }


  bool validOrder(const string& a, const string& b){
    string sa = "";
    string sb = "";
    for(int i = 0; i < a.length(); i++) if(a[i] != '.') sa += a[i];
    for(int i = 0; i < b.length(); i++) if(b[i] != '.') sb += b[i];
    return sa == sb;
  }

  bool possibleMove(const string& a, const string& b){
    vector<int> A,B;
    for(int i = 0; i < a.length(); i++) if(a[i] != '.') A.push_back(i);
    for(int i = 0; i < b.length(); i++) if(b[i] != '.') B.push_back(i);

    for(int i = 0; i < A.size(); i++){
      int p = A[i];
      if(a[p] == 'R' && A[i] > B[i]) return false;
      if(a[p] == 'L' && A[i] < B[i]) return false;
    }
    return true;
  }
	
// BEGIN CUT HERE
	public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }
  void test_case_6() { string Arg0 = "................................R................."; string Arg1 = ".............................................R...."; string Arg2 = "Possible"; verify_case(6, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	FoxAndChess ___test;
	___test.run_test(-1);
}

// END CUT HERE
