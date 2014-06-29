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

class UndoHistory {
public:
  int minPresses(vector <string> lines) {
    set<string> history;
    int res = 0;
    string txt_buff = "";
    
    for(int i = 0; i < (int)lines.size(); i++){
      int tbuf = useTxtBuff(txt_buff, lines[i]);
      string hist = useHistory(history, lines[i]);
      
      if(tbuf != -1 && (int)txt_buff.length() > (int)hist.length()-2){
	// not use history
	for(int j = tbuf; j < (int)lines[i].length(); j++){
	  txt_buff += lines[i][j];
	  history.insert(txt_buff);
	  res++;
	}
      }else{
	// use history
	txt_buff = hist;
	if(i != 0) res += 2;

	for(int j = txt_buff.length(); j < (int)lines[i].size(); j++){
	  txt_buff += lines[i][j];
	  history.insert(txt_buff);
	  res++;
	}
      }
      res++;
    }
    return res;
  }
  
 int useTxtBuff(const string& s, const string& line){
   for(int i = (int)line.length(); i > 0; i--)
     if(line.substr(0,i) == s) return i;
   return -1;
  }

  string useHistory(const set<string>& history, const string& s){
    for(int i = (int)s.length(); i > 0; i--){
      if(history.find(s.substr(0,i)) != history.end()) return s.substr(0,i);
    }
    return "";
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
	void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
	void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	UndoHistory ___test;
	___test.run_test(-1);
}

// END CUT HERE
