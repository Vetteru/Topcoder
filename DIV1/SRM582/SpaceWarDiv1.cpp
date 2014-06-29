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
#include <climits>

#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return true;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class SpaceWarDiv1 {
public:
  long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
    vector<int>& mag = magicalGirlStrength;
    vector<int>& ene = enemyStrength;
    vector<long long>& enec = enemyCount;

    if(!canDefeatAll(mag,ene)) return -1LL;
    
    vector<P> v(ene.size());
    for(int i = 0; i < (int)v.size(); i++) v[i] = P(ene[i],enec[i]);
    sort(mag.begin(),mag.end());
    sort(v.begin(),v.end());
    
    return search(mag, v);
  }


  //binary search
  ll search(const vector<int>& mag, const vector<P>& ene){
    ll l = 0, r = 0;
    for(int i = 0; i < (int)ene.size(); i++) r += ene[i].S;

    while(l < r){
      ll c = (l+r)/2;
      if(canDo(mag, ene, c)) r = c;
      else l = c+1;
    }
    return r;
  }
  
  bool canDo(const vector<int>& mag, vector<P> ene, ll lim){

    //P -? F:strength S:number

    int Eidx = (int)ene.size()-1;

    for(int i = (int)mag.size()-1; i >= 0; i--){
      
      ll tmp = lim;
      while(Eidx >= 0){
	if(mag[i] < ene[Eidx].F) return false;
	
	if(tmp < ene[Eidx].S){ene[Eidx].S -= tmp; break;}
	else{tmp -= ene[Eidx--].S;}
      }
    }
    return Eidx<0;
  }
  

  bool canDefeatAll(const vector<int>& mag, const vector<int>& ene){
    int mmag = 0;
    int mene = 0;
    for(int i = 0; i < (int)mag.size(); i++) mmag = max(mmag,mag[i]);
    for(int i = 0; i < (int)ene.size(); i++) mene = max(mene,ene[i]);
    return mmag >= mene;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {14, 6, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {9, 1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 75030497287405LL; verify_case(3, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	SpaceWarDiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
