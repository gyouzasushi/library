#pragma once
// 数列Aに対する2種類のクエリを処理
// クエリ1 : 区間[l,r)にxを加算(apply)
// クエリ2 : 区間[l,r)のGCDを取得(fold)
template <typename T>
struct RangeAddRangeGCD {
public:
    RangeAddRangeGCD(int n) : RangeAddRangeGCD(vector<T>(n, 0)) {
    }
    RangeAddRangeGCD(const vector<T> &vec) : N((int)vec.size()) {
        sz = 1;
        while (sz < N) sz <<= 1;
        seg.resize(2 * sz);
        for (int i = 0; i < N - 1; i++) {
            seg[i + sz] = vec[i + 1] - vec[i];
        }
        for (int i = sz - 1; i >= 1; i--) {
            seg[i] = gcd(seg[2 * i], seg[2 * i + 1]);
        }
        dseg.resize(2 * sz);
        for (int i = 0; i < N; i++) {
            dseg[i + sz] = vec[i];
        }
    }

    void apply(int l, int r, T x) {
        assert(0 <= l && l < r && r <= N);
        if (l) {
            int now = l - 1 + sz;
            seg[now] += x;
            now >>= 1;
            while (now) {
                seg[now] = gcd(seg[2 * now], seg[2 * now + 1]);
                now >>= 1;
            }
        }
        if (r <= N - 1) {
            int now = r - 1 + sz;
            seg[now] -= x;
            now >>= 1;
            while (now) {
                seg[now] = gcd(seg[2 * now], seg[2 * now + 1]);
                now >>= 1;
            }
        }
        for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) dseg[a] += x, ++a;
            if (b & 1) --b, dseg[b] += x;
        }
    }

    T fold(int l, int r) {
        assert(0 <= l && l < r && r <= N);
        if (r - l == 1) return _get(l);
        T tmp = 0;
        for (int a = l + sz, b = r - 1 + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) tmp = gcd(tmp, seg[a]), ++a;
            if (b & 1) --b, tmp = gcd(tmp, seg[b]);
        }
        return gcd(tmp, _get(l));
    }

private:
    int N, sz;
    vector<T> seg, dseg;

    T _get(int x) {
        T ret = 0;
        x += sz;
        while (x) {
            ret += dseg[x];
            x >>= 1;
        }
        return ret;
    }
};

template <typename T>
struct RangeArithmeticAddRangeGCD : RangeAddRangeGCD<T> {
public:
    RangeArithmeticAddRangeGCD(int n)
        : RangeArithmeticAddRangeGCD(vector<T>(n, 0)) {
    }
    RangeArithmeticAddRangeGCD(const vector<T> &vec)
        : RARG((int)vec.size() - 1), N((int)vec.size()) {
        for (int i = 0; i < N - 1; i++)
            RARG::apply(i, i + 1, vec[i + 1] - vec[i]);
        sz = 1;
        while (sz < N) sz <<= 1;
        A.resize(2 * sz);
        B.resize(2 * sz);
        for (int i = 0; i < N; i++) B[i + sz] = vec[i];
    }

    void apply(int l, int r, T a, T d) {
        T b = a - d * l;
        for (int x = l + sz, y = r + sz; x < y; x >>= 1, y >>= 1) {
            if (x & 1) A[x] += d, ++x;
            if (y & 1) --y, A[y] += d;
        }
        for (int x = l + sz, y = r + sz; x < y; x >>= 1, y >>= 1) {
            if (x & 1) B[x] += b, ++x;
            if (y & 1) --y, B[y] += b;
        }
        if (l) RARG::apply(l - 1, l, a);
        if (r - l > 1) RARG::apply(l, r - 1, d);
        if (r <= N - 1) RARG::apply(r - 1, r, -a - (r - l - 1) * d);
    }

    T fold(int l, int r) {
        if (r - l == 1) return _get(l);
        return gcd(_get(l), RARG::fold(l, r - 1));
    }

private:
    using RARG = RangeAddRangeGCD<T>;
    int N, sz;
    vector<T> A, B;

    T _get(int x) {
        int now = x + sz;
        T a = 0, ret = 0;
        while (now) {
            a += A[now];
            ret += B[now];
            now >>= 1;
        }
        return ret + a * x;
    }
};