class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (emailToAccount.find(mail) == emailToAccount.end()) {
                    emailToAccount[mail] = i;
                } else {
                    ds.unionBySize(i, emailToAccount[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> merged;

        for (auto &it : emailToAccount) {
            string mail = it.first;
            int node = it.second;

            int parent = ds.findUPar(node);

            merged[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (auto &it : merged) {

            int node = it.first;

            vector<string> mails = it.second;

            sort(mails.begin(), mails.end());

            vector<string> temp;

            temp.push_back(accounts[node][0]);

            for (auto &mail : mails)
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};