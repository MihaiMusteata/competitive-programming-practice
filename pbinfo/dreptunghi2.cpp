// Problema #3724 Dreptunghi2
// https://www.pbinfo.ro/probleme/3724/dreptunghi2

#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

struct Node {
    char type;
    int k;
    Node* left;
    Node* right;
    Node(char t='*', int kk=0) : type(t), k(kk), left(NULL), right(NULL) {}
};

struct Info {
    long long leaves;
    int minN;
    int minM;
    long long cnt;
    Info() : leaves(0), minN(1), minM(1), cnt(1) {}
    Info(long long L, int N, int M, long long C) : leaves(L), minN(N), minM(M), cnt(C) {}
};

string S;
int posi = 0;

int readInt() {
    int x = 0;
    while (posi < (int)S.size() && isdigit((unsigned char)S[posi])) {
        x = x * 10 + (S[posi] - '0');
        posi++;
    }
    return x;
}

Node* parse() {
    char c = S[posi++];
    if (c == '*') return new Node('*', 0);
    Node* n = new Node(c, readInt());
    n->left = parse();
    n->right = parse();
    return n;
}

void normalize(Node* n) {
    if (!n || n->type == '*') return;
    normalize(n->left);
    normalize(n->right);
    if (n->type == 'H' || n->type == 'V') {
        char op = n->type;
        while (n->left && n->left->type == op) {
            Node* L = n->left;
            int a = n->k;
            int b = L->k;
            Node* A = L->left;
            Node* B = L->right;
            Node* C = n->right;
            n->k = b;
            n->left = A;
            Node* newRight = new Node(op, a - b);
            newRight->left = B;
            newRight->right = C;
            n->right = newRight;
            normalize(n->right);
        }
    }
}

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

vector<long long> factv, invfactv;

long long Cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return factv[n] * invfactv[k] % MOD * invfactv[n-k] % MOD;
}

long long catalan(int n) {
    if (n < 0) return 0;
    long long res = Cnk(2*n, n);
    res = res * modpow(n + 1, MOD - 2) % MOD;
    return res;
}

void flatten(Node* n, char op, vector<Node*>& out) {
    if (n->type != op) {
        out.push_back(n);
        return;
    }
    flatten(n->left, op, out);
    flatten(n->right, op, out);
}

Info solve(Node* n) {
    if (n->type == '*') return Info(1, 1, 1, 1);

    Info L = solve(n->left);
    Info R = solve(n->right);

    Info ret;
    ret.leaves = L.leaves + R.leaves;

    if (n->type == 'H') {
        ret.minM = max(L.minM, R.minM);
        ret.minN = n->k + R.minN;
    } else {
        ret.minN = max(L.minN, R.minN);
        ret.minM = n->k + R.minM;
    }

    char op = n->type;
    vector<Node*> ops;
    flatten(n, op, ops);

    long long prod = 1;
    for (size_t i = 0; i < ops.size(); i++) {
        Info ii = solve(ops[i]);
        prod = (prod * ii.cnt) % MOD;
    }

    long long ways = catalan((int)ops.size() - 1);
    ret.cnt = (prod * ways) % MOD;

    return ret;
}

long long countLeaves(Node* n) {
    if (!n) return 0;
    if (n->type == '*') return 1;
    return countLeaves(n->left) + countLeaves(n->right);
}

pair<int,int> minDims(Node* n) {
    if (n->type == '*') return make_pair(1,1);
    pair<int,int> a = minDims(n->left);
    pair<int,int> b = minDims(n->right);
    if (n->type == 'H') {
        int M = max(a.second, b.second);
        int N = n->k + b.first;
        return make_pair(N, M);
    } else {
        int N = max(a.first, b.first);
        int M = n->k + b.second;
        return make_pair(N, M);
    }
}

void printCode(Node* n) {
    if (n->type == '*') {
        cout << '*';
        return;
    }
    cout << n->type << n->k;
    printCode(n->left);
    printCode(n->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    cin >> P >> S;

    int MAXN = 2000;
    factv.assign(MAXN + 1, 1);
    invfactv.assign(MAXN + 1, 1);
    for (int i = 1; i <= MAXN; i++) factv[i] = factv[i-1] * i % MOD;
    invfactv[MAXN] = modpow(factv[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--) invfactv[i-1] = invfactv[i] * i % MOD;

    posi = 0;
    Node* root = parse();

    if (P == 1) {
        cout << countLeaves(root) << "\n";
        return 0;
    }

    if (P == 2) {
        pair<int,int> ans = minDims(root);
        cout << ans.first << " " << ans.second << "\n";
        return 0;
    }

    if (P == 3) {
        Info info = solve(root);
        cout << info.cnt % MOD << "\n";
        return 0;
    }

    if (P == 4) {
        normalize(root);
        printCode(root);
        cout << "\n";
        return 0;
    }

    return 0;
}
