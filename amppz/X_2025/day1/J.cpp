#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
struct ST {
  vector<int> tree;
  int size;
  int N;
  ST(int n, vector<int>& B) {
    N = n;
    size = 1;
    while (size <= N) size *= 2;

    tree.assign(2 * size + 5, 0);
    for (int i = size, j = 0; i < size + N && j < N; i++, j++) {
      tree[i] = B[j];
    }

    for (int i = size - 1; i >= 0; i--) {
      tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    }
  }

  int query(int l, int r) { return query(1, l, r, 1, size); }

  void update(int x, int k) { return update(1, 1, size, k, x); }

  void update(int node, int start, int end, int pos, int dx) {
    if (pos < start || pos > end) {
      return;
    }

    if (start == end) {
      tree[node] += dx;
      return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, pos, dx);
    update(2 * node + 1, mid + 1, end, pos, dx);
    tree[node] = tree[2 * node] ^ tree[2 * node + 1];
  }

  int query(int node, int l, int r, int start, int end) {
    if (start > r || end < l) {
      return -1;
    }

    if (l <= start && end <= r) {
      return tree[node];
    }

    const int mid = (start + end) / 2;
    int left_query = query(2 * node, l, r, start, mid);
    int right_query = query(2 * node + 1, l, r, mid + 1, end);
    if (left_query == -1) return right_query;
    if (right_query == -1) return left_query;
    return left_query ^ right_query;
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> B[i];
  ST st(N, B);

  for (int i = 0; i < Q; i++) {
    char event;
    cin >> event;
    if (event == 'P') {
      int l, r;
      cin >> l >> r;
      int xd = st.query(l, r);

      // debug(xd);
      //   return;

      if (xd) {
        cout << "FRANK\n";
      } else
        cout << "JUAN\n";
    } else if (event == 'R') {
      int x, k;
      cin >> x >> k;
      swap(x, k);
      st.update(x, k);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
