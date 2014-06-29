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

class FactoVisors {
public:


  int getNum(vector <int> divisors, vector <int> multiples) {
    set<int> S;
    vector<int>& div = divisors;
    vector<int>& mul = multiples;
    
    make(S, div);
    make(S, mul);
    vector<int> prime;
    for(set<int>::const_iterator ite = S.begin(); ite != S.end(); ite++) prime.push_back(*ite);

    int N = prime.size();
    vector<int> divP(N,-1), mulP(N,-1);
    
    find(divP, div, prime, true);
    find(mulP, mul, prime, false);

    for(int i = 0; i < N; i++){
      divP[i] = max(0, divP[i]);
      mulP[i] = max(0, mulP[i]);
    }

    long long ans = 1;
    for(int i = 0; i < N; i++){
      long long diff = max(0, mulP[i]-divP[i]+1);
      ans *= diff;
    }
    return ans;
  }


  void find(vector<int>& P, const vector<int>& v, const vector<int>& prime, bool isDiv){
    int N = prime.size();

    for(int i = 0; i < (int)v.size(); i++){
      vector<int> tmp = prime_factor(v[i]);
      sort(tmp.begin(),tmp.end());
      for(int j = 0; j < N; j++){
	int num = upper_bound(tmp.begin(),tmp.end(),prime[j])-lower_bound(tmp.begin(),tmp.end(),prime[j]);
	if(isDiv) P[j] = max(P[j], num);
	else P[j] = min(P[j], num);

	if(P[j] == -1) P[j] = num;
      }
    }
  }

  void make(set<int>& s, const vector<int>& v){
    for(int i = 0; i < (int)v.size(); i++){
      vector<int> tmp = prime_factor(v[i]);
      for(int j = 0; j < (int)tmp.size(); j++) s.insert(tmp[j]);
    }
  }

  vector<int> prime_factor(int n){
    vector<int> res;
    for(int i = 2; i*i <= n; i++)
      while(n%i==0){
	res.push_back(i);
	n/=i;
      }
    if(n!=1) res.push_back(n);
    return res;
  }
  
  // BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, getNum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getNum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {96,180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getNum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {256}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, getNum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000,10000,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(4, Arg2, getNum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	FactoVisors ___test;
	___test.run_test(-1);
}

// END CUT HERE
