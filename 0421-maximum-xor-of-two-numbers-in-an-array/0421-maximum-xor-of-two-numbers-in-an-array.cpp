class Solution {
public:

    class Node {
    public:
        Node* links[2];

        Node() {
            links[0] = NULL;
            links[1] = NULL;
        }

        bool containsKey(int bit) {
            return links[bit] != NULL;
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }

        Node* get(int bit) {
            return links[bit];
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;

            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if(!node->containsKey(bit)) {
                    node->put(bit, new Node());
                }

                node = node->get(bit);
            }
        }

        int getMaxXor(int num) {
            Node* node = root;
            int ans = 0;

            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                int opposite = 1 - bit;

                if(node->containsKey(opposite)) {
                    ans = ans | (1 << i);
                    node = node->get(opposite);
                }
                else {
                    node = node->get(bit);
                }
            }

            return ans;
        }
    };

    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for(int i = 0; i < nums.size(); i++) {
            trie.insert(nums[i]);
        }

        int maximum = 0;

        for(int i = 0; i < nums.size(); i++) {
            maximum = max(maximum, trie.getMaxXor(nums[i]));
        }

        return maximum;
    }
};