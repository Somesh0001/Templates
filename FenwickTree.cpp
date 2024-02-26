struct Bit
{
    int n;
    vector<int> tree;
    Bit(int size)
    {
        n = size;
        tree.resize(n + 1);
        fill(tree.begin(), tree.end(), 0);
    }
    void updatebit(int idx, int val)
    {
        idx++;  //1 indexing
        while (idx <= n)
        {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    int getsum(int idx)
    {
        idx++;  //1 indexing
        int ans = 0;
        while (idx > 0)
        {
            ans += tree[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
};