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

bool isPrime(int a){ for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class TheLotteryBothDivs {
public:
  double find(vector <string> goodSuffixes) {
    vector<string> v = make(goodSuffixes);
    vector<int> cand = getCandidate(v);
    double den = 1e9, num = 0;
    for(int i = 0; i < (int)cand.size(); i++) num += den/(double)cand[i];
    return num/den;
  }

  vector<int> getCandidate(const vector<string>& v){
    vector<int> res;
    for(int i = 0; i < (int)v.size(); i++){
      int len = v[i].length();
      int num = 1;
      while(len--) num *= 10;
      res.push_back(num);
    }
    return res;
  }

  vector<string> make(const vector<string>& v){
    bool erase[51] = {false};

    for(int i = 0; i < (int)v.size(); i++){
      for(int j = 1; j < (int)v[i].length(); j++){
	string s = v[i].substr(j);
	for(int k = 0; k < (int)v.size(); k++)
	  if(s == v[k]){
	    erase[i] = true;
	    break;
	  }
	if(erase[i]) break;
      }
    }

    vector<string> res;
    for(int i = 0; i < (int)v.size(); i++)
      if(!erase[i]) res.push_back(v[i]);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()), res.end());
    return res;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	TheLotteryBothDivs ___test;
	___test.run_test(-1);
}

// END CUT HERE
