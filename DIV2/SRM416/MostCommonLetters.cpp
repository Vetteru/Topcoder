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

class MostCommonLetters {
public:
  string listMostCommon(vector <string> text) {
    map<char, int> M;
    for(int i = 0; i < (int)text.size(); i++)
      for(int j = 0; j < (int)text[i].size(); j++) M[text[i][j]]++;

    string res = "";
    int num = -1;
    for(map<char, int>::iterator ite = M.begin(); ite != M.end(); ite++){
      if(ite->first == ' ') continue;
      if(num < ite->second){
	res = "";
	res += ite->first;
	num = ite->second;
      }else if(num == ite->second) res += ite->first;
    }
    return res;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abc a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a"; verify_case(0, Arg1, listMostCommon(Arg0)); }
	void test_case_1() { string Arr0[] = {"abc", "ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ab"; verify_case(1, Arg1, listMostCommon(Arg0)); }
	void test_case_2() { string Arr0[] = {"qwerty", "abc", "qwe", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aeqw"; verify_case(2, Arg1, listMostCommon(Arg0)); }
	void test_case_3() { string Arr0[] = {"english is a west germanic language originating",
 "in england and is the first language for most",
 "people in the united kingdom the united",
 "states canada australia new zealand ireland",
 "and the anglophone caribbean it is used",
 "extensively as a second language and as an",
 "official language throughout the world",
 "especially in commonwealth countries and in",
 "many international organizations"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a"; verify_case(3, Arg1, listMostCommon(Arg0)); }
	void test_case_4() { string Arr0[] = {"amanda forsaken bloomer meditated gauging knolls",
 "betas neurons integrative expender commonalities",
 "latins antidotes crutched bandwidths begetting",
 "prompting dog association athenians christian ires",
 "pompousness percolating figured bagatelles bursted",
 "ninth boyfriends longingly muddlers prudence puns",
 "groove deliberators charter collectively yorks",
 "daringly antithesis inaptness aerosol carolinas",
 "payoffs chumps chirps gentler inexpressive morales"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "e"; verify_case(4, Arg1, listMostCommon(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	MostCommonLetters ___test;
	___test.run_test(-1);
}

// END CUT HERE
