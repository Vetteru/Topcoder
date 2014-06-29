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
class SurveillanceSystem {
public:
  string getContainerInfo(string containers, vector <int> reports, int L) {
    int N = containers.size();
    vector<int> watch(N-L+1,0); // i-th camera watches watch[i] containers. 
    vector<int> cnt(L+1,0); // cnt[i] cameras watches i containers.
  
    for(int i = 0; i < (int)reports.size(); i++) cnt[reports[i]]++;

    for(int i = 0; i < N-L+1; i++)
      for(int j = 0; j < L; j++) 
	if(containers[i+j] == 'X') watch[i]++;
    
    string ans(N, '?');

    for(int i = 0; i < N; i++){
      vector<int> can(L+1,0);
      
      for(int j = 0; j < N-L+1; j++) if(!(j <= i && i < j+L)) can[watch[j]]++;
      
      bool removable = isValid(can, cnt);
      
      if(!removable){
	ans[i] = '+';
      }else{
	bool see = false;
	for(int j = 0; j < N-L+1; j++){
	  if(j <= i && i < j+L) see |= (cnt[watch[j]] > 0);	
	  ans[i] = (see?'?':'-');
	}
      }
    }
    return ans;
  }
  
  
  bool isValid(const vector<int>& can, const vector<int>& need){
    for(int i = 0; i < (int)can.size(); i++)
      if(can[i] < need[i]) return false;
    return true;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	SurveillanceSystem ___test;
	___test.run_test(-1);
}

// END CUT HERE
