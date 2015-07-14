#include<bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

bool isPrime(int a){for(int i=2; i*i<=a; i++) if(a%i==0) return false; return a>1;}
string toStr(int a){ostringstream oss; oss<<a; return oss.str();}
int toInt(string s){return atoi(s.substr(0,s.size()).c_str());}

class Hexspeak {
public:
  string decode(long long ciphertext) {
    string res = "";
    while(ciphertext){
      res += getChar(ciphertext%16LL);
      ciphertext /= 16LL;
    }
    if(res.find("$") != string::npos) return "Error!";
    reverse(ALL(res));
    return res;
  }

  string getChar(long long n){
    if(n == 0) return "O";
    if(n == 1) return "I";
    if(n < 10) return "$";
    return string (1, 'A'+n-10);
  }
  
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 257LL; string Arg1 = "IOI"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { long long Arg0 = 258LL; string Arg1 = "Error!"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { long long Arg0 = 3405691582LL; string Arg1 = "CAFEBABE"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { long long Arg0 = 2882400001LL; string Arg1 = "ABCDEFOI"; verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { long long Arg0 = 999994830345994239LL; string Arg1 = "DEOBIFFFFFFFFFF"; verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000000000000LL; string Arg1 = "Error!"; verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE 

int main() {
	Hexspeak ___test;
	___test.run_test(-1);
}

// END CUT HERE
