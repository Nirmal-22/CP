int findRoot(int v, int parent[])
{
    if (v == parent[v])
        return v;
    // path compression
    return parent[v] = findRoot(parent[v], parent);
}

void Union(int a, int b, int parent[], int size[])
{
    a = findRoot(a, parent);
    b = findRoot(b, parent);
    if (a != b)
    {
        // Union by size
        if (size[a] < size[b])
        {   
            parent[a] = b;
            size[b] += size[a];
        } 
        else
        {
            parent[b] = a;
            size[a] += size[b];            
        }

    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int parent[A + 1];
    int size[A + 1];

    for (int i = 1; i <= A; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    sort(B.begin(), B.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2]; // Compare B based on their weight (index 2)
    });

    int total_cost = 0;
    for (auto &edge : B)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (findRoot(u, parent) == findRoot(v, parent))
            continue;
        Union(u, v, parent, size);
        total_cost += wt;
        // cout << u << " " << v << endl;
    }

    return total_cost;
}
