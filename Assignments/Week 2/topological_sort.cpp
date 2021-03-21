#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        Solution(){}
        void init_arrays(){
            m_adj_list = vector <vector <int> >(n + 1);
            m_is_visited = vector <bool> (n + 1, false);
        }
        void Explore(const int start_node){
            m_is_visited[start_node] = true;
            for (int i = 0; i < (int)m_adj_list[start_node].size(); i++){
                int node = m_adj_list[start_node][i];
                if (m_is_visited[node] == false){
                    Explore(node);
                }
            }
            ans_arr.push_back(start_node);
        }
        void Solve(){
            cin >> n >> m;
            init_arrays();
            int p, q;
            for (int i = 0; i < m; i++){
                cin >> p >> q;
                m_adj_list[p].push_back(q);
            }
            for (int i = 1; i <= n; i++){
                if (m_is_visited[i] == false){
                    Explore(i);
                }
            }
            for (int i = n - 1; i >= 0; i--){
                cout << ans_arr[i] << " ";
            }
        }

    private:
        int                     n, m;
        vector <vector <int> >  m_adj_list;
        vector <bool>           m_is_visited;
        vector <int>            ans_arr;
};

int main(){
    Solution solution;
    solution.Solve();
    return 0;
}
