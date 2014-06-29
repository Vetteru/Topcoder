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

struct Data{
  string name;
  int g,s,b;
  bool operator < (const Data& d) const {
    if(g != d.g) return g < d.g;
    if(s != d.s) return s < d.s;
    if(b != d.b) return b < d.b;
    return name > d.name;
  }
};

class MedalTable {
public:
  vector <string> generate(vector <string> results) {
    vector<Data> v;
    for(int i = 0; i < (int)results.size(); i++){
      stringstream ss(results[i]);
      for(int j = 0; j < 3; j++){
	string name;
	ss >> name;
	push(v, (Data){name, j==0, j==1, j==2});
      }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return convert(v);
  }

  void push(vector<Data>& v, const Data& d){
    for(int i = 0; i < (int)v.size(); i++){
      if(v[i].name == d.name){
	v[i].g += d.g;
	v[i].s += d.s;
	v[i].b += d.b;
	return;
      }
    }
    v.push_back(d);
  }

  vector<string> convert(const vector<Data>& d){
    vector<string> res;
    for(int i = 0; i < (int)d.size(); i++){
      string s = "";
      s += d[i].name + " ";
      s += toStr(d[i].g) + " ";
      s += toStr(d[i].s) + " ";
      s += toStr(d[i].b);
      res.push_back(s);
    }
    return res;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	MedalTable ___test;
	___test.run_test(-1);
}

// END CUT HERE
