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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  int query(int node, int l, int r, int start, int end) {
    if (start > r || end < l) {
      return 0; // element neutralny
    }

    if (l <= start && end <= r) {
      return tree[node];
    }

    const int mid = (start + end) / 2;
    int left_query = query(2 * node, l, r, start, mid);
    int right_query = query(2 * node + 1, l, r, mid + 1, end);
    return left_query + right_query;
  }
};
