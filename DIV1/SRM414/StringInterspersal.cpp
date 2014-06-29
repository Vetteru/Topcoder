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

typedef pair<int,string> P;
const int MAX = 21;
int used[MAX];

class StringInterspersal {
	public:
	string minimum(vector <string> W) {
	  string ans = "";
	  memset(used,0,sizeof(used));

	  vector<P> V(W.size());
	  for(int i = 0; i < V.size(); i++) V[i] = P(i,W[i]);
	  while(1){
	    int minpos = findOptimalPosition(V);
	    if(minpos == -1) break;
	    ans += W[minpos][used[minpos]++];
	    // print(V);
	  }
	  return ans;
	}

  int findOptimalPosition(const vector<P>& v){
    // print(v);
    int res = -1;
    for(int i = 0; i < (int)v.size(); i++){
      if((int)v[i].second.length() <= used[v[i].first]) continue;
      if(res == -1 || v[res].second.substr(used[v[res].first]) > v[i].second.substr(used[v[i].first])) res = i;
    }
    if(res == -1) return -1;
    
    string s = v[res].second.substr(used[v[res].first]);
    vector<P> nex;
    for(int i = 0; i < (int)v.size(); i++){
      if(v[i].second.length() < used[v[i].first]+s.length()) continue;
      if(v[i].second.substr(used[v[i].first],s.length()) == s) nex.push_back(v[i]);
    }
    
    if(nex.size() == 1) return nex[0].first;
    //  if(nex.size() == 0) return v[0].first;
    for(int i = 0; i < nex.size(); i++) used[nex[i].first]++;
    res = findOptimalPosition(nex);
    for(int i = 0; i < nex.size(); i++) used[nex[i].first]--;
    if(res == -1)return nex[0].first;
    return res;
}

  void print(const vector<P>& v){
    cout << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << " " << used[v[i].first]<< endl;
    cout << endl;
  }


	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();  test_case_7(); }

	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DESIGN","ALGORITHM","MARATHON"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ADELGMAORARISIGNTHMTHON"; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH"; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"CCCA","CCCB","CCCD","CCCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCACCCBCCCCCCDE"; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX"; verify_case(3, Arg1, minimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"TOPCODER","BETFAIR","NSA","BT","LILLY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBELILLNSATFAIRTOPCODERTY"; verify_case(4, Arg1, minimum(Arg0)); }
	void test_case_5() { string Arr0[] = {"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC"; verify_case(5, Arg1, minimum(Arg0)); }
	void test_case_6() { string Arr0[] = {"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW"; verify_case(6, Arg1, minimum(Arg0)); }
  void test_case_7() { string Arr0[] = {"BA","B","BA","B","BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BABABABB"; verify_case(7, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	StringInterspersal ___test;
	___test.run_test(-1);
}

// END CUT HERE
