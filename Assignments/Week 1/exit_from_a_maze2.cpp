#include <bits/stdc++.h>

using namespace std;

void Explore(const int start_node, const int find_node, int& ans, const vector <vector <int> > m_adj_list, vector <bool>& m_is_visited){
    m_is_visited[start_node] = true;
    for (int i = 0; i < (int)m_adj_list[start_node].size() && ans == 0; i++){
        int node = m_adj_list[start_node][i];
        if (node == find_node) {ans = 1; break;}
        if (m_is_visited[node] == false){
            Explore(node, find_node, ans, m_adj_list, m_is_visited);
        }
    }
}

int main(){
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    vector <vector <int> > m_adj_list(n + 1);
    vector <bool> m_is_visited(n + 1, false);
    int p, q;
    for (int i = 0; i < m; i++){
        cin >> p >> q;
        m_adj_list[p].push_back(q);
        m_adj_list[q].push_back(p);
    }
    cin >> u >> v;
    Explore(u, v, ans, m_adj_list, m_is_visited);
    cout << ans;
    return 0;
}
