#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        Solution(){}
        void init_arrays(){
            m_adj_list = vector <vector <int> >(n + 1);
            m_adj_list_reverse = vector <vector <int> >(n + 1);
            m_is_visited = vector <bool> (n + 1, false);
        }
        void Explore(const int start_node){
            m_is_visited[start_node] = true;
            for (int i = 0; i < (int)m_adj_list_reverse[start_node].size(); i++){
                int node = m_adj_list_reverse[start_node][i];
                if (m_is_visited[node] == false){
                    Explore(node);
                }
            }
            ans_arr.push_back(start_node);
        }
        void Explore_reverse(const int start_node){
            m_is_visited[start_node] = false;
            for (int i = 0; i < (int)m_adj_list[start_node].size(); i++){
                int node = m_adj_list[start_node][i];
                if (m_is_visited[node] == true){
                    Explore_reverse(node);
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
                m_adj_list_reverse[q].push_back(p);
            }
            for (int i = 1; i <= n; i++){
                if (m_is_visited[i] == false){
                    Explore(i);
                }
            }
            for (int i = n - 1; i >= 0; i--){
                if (m_is_visited[ans_arr[i]] == true){
                    ++ans;
                    Explore_reverse(ans_arr[i]);
                }
            }
            cout << ans;
        }

    private:
        int                     n, m, ans = 0;
        vector <vector <int> >  m_adj_list;
        vector <vector <int> >  m_adj_list_reverse;
        vector <bool>           m_is_visited;
        vector <int>            ans_arr;
};

int main(){
    Solution solution;
    solution.Solve();
    return 0;
}
