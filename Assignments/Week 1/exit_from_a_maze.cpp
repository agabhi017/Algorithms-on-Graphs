#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        Solution(){}
        void init_arrays(){
            m_adj_list = vector <vector <int> >(n + 1);
            m_is_visited = vector <bool>(n + 1, false);
        }
        void Explore(const int start_node){
            m_is_visited[start_node] = true;
            for (int i = 0; i < (int)m_adj_list[start_node].size() && ans == 0; i++){
                int node = m_adj_list[start_node][i];
                if (node == v) {ans = 1; break;}
                if (m_is_visited[node] == false){
                    Explore(node);
                }
            }
        }
        void Solve(){
            cin >> n >> m;
            init_arrays();
            int p, q;
            for (int i = 0; i < m; i++){
                cin >> p >> q;
                m_adj_list[p].push_back(q);
                m_adj_list[q].push_back(p);
            }
            cin >> u >> v;
            Explore(u);
            cout << ans;
        }

    private:
        int n, m, u, v, ans = 0;
        vector <vector <int> > m_adj_list;
        vector <bool> m_is_visited;

};

int main(){
    Solution solution;
    solution.Solve();
    return 0;
}
