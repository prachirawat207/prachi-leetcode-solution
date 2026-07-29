class Solution {
public:
    static const long long CAP = 2000001; // > max k (1e6), safe sentinel

    // returns total!/(prod cnt[i]!) capped at CAP
    long long countPerm(array<int,26>& cnt) {
        long long result = 1;
        int n = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                n++;
                result = result * n / j;
                if (result > CAP) result = CAP;
            }
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        array<int,26> cnt{};
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] % 2) oddCount++;
        if (oddCount > 1) return ""; // not possible (won't happen since s is palindrome)

        char mid = 0;
        array<int,26> half{};
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) mid = 'a' + i;
            half[i] = cnt[i] / 2;
            halfLen += half[i];
        }

        long long total = countPerm(half);
        if ((long long)k > total) return "";

        long long kk = k;
        string leftHalf;
        array<int,26> cur = half;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (cur[c] == 0) continue;
                cur[c]--;
                long long permCnt = countPerm(cur);
                if (kk <= permCnt) {
                    leftHalf += char('a' + c);
                    break;
                } else {
                    kk -= permCnt;
                    cur[c]++;
                }
            }
        }

        string rightHalf(leftHalf.rbegin(), leftHalf.rend());
        string result = leftHalf;
        if (mid != 0) result += mid;
        result += rightHalf;
        return result;
    }
};