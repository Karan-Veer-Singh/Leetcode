class Solution {
public:
  int count(vector<int> &x) {
    int l = 0, h = x.size() - 1;

    while (l <= h) {
      int mid = l + (h - l) / 2;
      if (x[mid] == 0)  h = mid - 1;
      else  l = mid + 1;
    }

    return l;
  }

  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> ans;
    set <pair<int, int>> s;

    for (int i = 0; i < mat.size(); i++) {
      int cnt = count(mat[i]);
      s.insert({cnt, i});
    }

    for (auto x : s) {
      ans.push_back(x.second);
      k--;
      if (k == 0) break;
    }

    return ans;
  }
};

// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/submissions/