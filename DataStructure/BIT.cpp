class BIT {
  private:
    ll d[maxn], dd[maxn];
    int b(int x) {return x & (-x);}
    ll sum(int x) {
        ll s = 0, ss = 0;
        int xx = x + 1;
        for (; x; x -= b(x))
            s += d[x], ss += dd[x];
        return xx * s - ss;
    }
    void add(int x, int v) {
        int c = x * v;
        for (; x < maxn; x += b(x))
            d[x] += v, dd[x] += c;
    }
  public:
    BIT() {
        memset(d, 0, sizeof(d));
        memset(d, 0, sizeof(dd));
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int l, int r, int v) {
        add(l, v), add(r + 1, -v);
    }
};