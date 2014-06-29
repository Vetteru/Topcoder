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

int acc[8][8];
bool vis[8][8];
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};

typedef pair<int,int> P;
struct info{
  int cnt,h,w;
  bool operator < (const info& in) const {
    if(cnt != in.cnt) return cnt < in.cnt;
    if(h != in.h) return h < in.h;
    return w < in.w;
  }
};

class KnightsTour {
public:
  int H,W;
  int visitedPositions(vector <string> board) {
    memset(vis, false, sizeof(vis));
    H = board.size();
    W = board[0].size();    
  
    P now = get_knight(board);
    int ans = 0;

    while(1){
      calc_acc(board);
      vis[now.first][now.second] = true;
      ans++;
      info nex = (info){100000,-1,-1};

      for(int i = 0; i < 8; i++){
        int nh = now.first+dy[i];
        int nw = now.second+dx[i];
        if(isOK(nh, nw, board) && !vis[nh][nw])  nex = min(nex, (info){acc[nh][nw], nh, nw});
      }

      if(nex.h == -1) break;
      now = P(nex.h, nex.w);
    }
    return ans;
  }

  void calc_acc(const vector<string>& board){
    memset(acc, 0, sizeof(acc));
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        for(int k = 0; k < 8; k++) acc[i][j] += (isOK(i+dy[k], j+dx[k], board)&&!vis[i+dy[k]][j+dx[k]]?1:0);
  }
  P get_knight(const vector<string>& vec){
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        if(vec[i][j] == 'K') return P(i,j);
    return P(-1,-1);
  }

  bool isOK(int h, int w, const vector<string>& board){
    if(h < 0 || h >= H) return false;
    if(w < 0 || w >= W) return false;
    return board[h][w]!='*';
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(0, Arg1, visitedPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, visitedPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, visitedPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, visitedPositions(Arg0)); }
	void test_case_4() { string Arr0[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(4, Arg1, visitedPositions(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	KnightsTour ___test;
	___test.run_test(-1);
}

// END CUT HERE
