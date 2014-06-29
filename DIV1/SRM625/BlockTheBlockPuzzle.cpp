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

struct edge{int to, cap, rev;};

const int INF = (1<<23);
const int MAX = 1000;
vector<edge> G[MAX];
bool used[MAX];

class BlockTheBlockPuzzle {
public:
  int minimumHoles(vector <string> board) {
    init();
    int N = board.size();
    int gy = -1, gx = -1;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        if(board[i][j] == '$'){gy = i; gx = j;}
   
    int src = 0, dst = 1, cnt = 2;
    int in[N][N], out[N][N];

    for(int i = gy%3; i < N; i+=3)
      for(int j = gx%3; j < N; j+=3){
        if(board[i][j] == 'H') continue;
        in[i][j] = cnt++;
        out[i][j] = cnt++;
        add_edge(in[i][j], out[i][j], (board[i][j]=='.'?1:INF));
        if(board[i][j] == 'b') add_edge(out[i][j], dst, INF);
        if(board[i][j] == '$') add_edge(src, in[i][j], INF);
      }
    
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    for(int i = gy%3; i < N; i+=3)
      for(int j = gx%3; j < N; j+=3)
        for(int d = 0; d < 4; d++){
          int ny = i+3*dy[d], nx = j+3*dx[d];
          if(ny < 0 || ny >= N || nx < 0 || nx >= N || board[i][j] == 'H' || board[ny][nx] == 'H') continue;

          char c1 = board[i+2*dy[d]][j+2*dx[d]], c2 = board[i+dy[d]][j+dx[d]];
          int cap;
          if(c1 == 'b' || c2 == 'b') cap = INF;
          else cap = (c1=='.'?1:0) + (c2=='.'?1:0);
          add_edge(out[i][j], in[ny][nx], cap);
        }
    int cost = max_flow(src, dst);
    return (cost>=INF?-1:cost);
  }
  
  void init(){
    for(int i = 0; i < MAX; i++) G[i].clear();
  }
  
  void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
  }
  
  int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    for(int i = 0; i < (int)G[v].size(); i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0){
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  
  int max_flow(int s, int t){
    int flow = 0;
    while(1){
      memset(used, false, sizeof(used));
      int f = dfs(s, t, INF);
      if(f == 0) return flow;
      flow += f;
    }
    return flow;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"b..$",
 "....",
 "HHHH",
 "HHHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
	void test_case_1() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumHoles(Arg0)); }
	void test_case_2() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }
	void test_case_3() { string Arr0[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumHoles(Arg0)); }
	void test_case_4() { string Arr0[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minimumHoles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
	BlockTheBlockPuzzle ___test;
	___test.run_test(-1);
}

// END CUT HERE
