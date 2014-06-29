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
class GeometricProgressions {
public:
  int count(int b1, int q1, int n1, int b2, int q2, int n2) {
    
    set<int> factor;
    factorize(factor, b1);
    factorize(factor, q1);
    factorize(factor, b2);
    factorize(factor, q2);
   
    vector<int> vb1, vq1, vb2, vq2;
    vb1 = make(factor,b1);
    vq1 = make(factor,q1);
    vb2 = make(factor,b2);
    vq2 = make(factor,q2);
  
    set<vector<int> > S;
    
    for(int i = 0; i < n1; i++){
      S.insert(vb1);
      if(b1 == 0 || q1 == 1) break;
      for(int j = 0; j < (int)vq1.size(); j++) vb1[j]+=vq1[j];
      if(q1 == 0) vb1 = vector<int>(factor.size(),0);
    }

    for(int i = 0; i < n2; i++){
      S.insert(vb2);
      if(b2 == 0 || q2 == 1) break;
      for(int j = 0; j < (int)vq2.size(); j++) vb2[j]+=vq2[j];
      if(q2 == 0) vb2 = vector<int>(factor.size(),0);
    }
    return S.size();
  }

  void factorize(set<int>& s, int N){
    vector<int> v = prime_factor(N);
    for(int i = 0; i < (int)v.size(); i++) s.insert(v[i]);
  }

  vector<int> make(const set<int>& s, int N){
    vector<int> p = prime_factor(N);
    vector<int> res(s.size(),0);
    set<int>::iterator ite = s.begin();
    int idx = 0;
    while(ite != s.end()){
      res[idx++] = upper_bound(p.begin(),p.end(),*ite)-
	lower_bound(p.begin(),p.end(),*ite);
      ite++;
    }
    return res;
  }

  vector<int> prime_factor(int n){
    if(n == 0) return vector<int>();
    if(n == 1) return vector<int>(1,1);
    vector<int> res;
    for(int i = 2; i*i <= n; i++)
      while(n%i==0){
	res.push_back(i);
	n/=i;
      }
    if(n!=1)res.push_back(n);
    return res;
  }

// BEGIN CUT HERE
	public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 6; int Arg4 = 2; int Arg5 = 5; int Arg6 = 6; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 5; int Arg6 = 9; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 100500; int Arg3 = 48; int Arg4 = 1024; int Arg5 = 1000; int Arg6 = 100500; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	GeometricProgressions ___test;
	___test.run_test(-1);
}

// END CUT HERE
