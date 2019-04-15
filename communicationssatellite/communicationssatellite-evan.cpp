/*
Evan Hruskar
communicationssatellite
2019-03-28 22:19:23
0.41 s
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

double dist(tuple<int, int, int> node1, tuple<int, int, int> node2) {
    return sqrt(pow(get<0>(node1) - get<0>(node2),2) + pow(get<1>(node1) - get<1>(node2),2)) - get<2>(node1) - get<2>(node2);
}

bool comp(tuple<int, int, double> e1, tuple<int, int, double> e2) {
    return get<2>(e1) < get<2>(e2);
}



int find(int x, vector<int> &link) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b, vector<int> &link) {
    return find(a, link) == find(b, link);
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> nodes(n);

    for (int i = 0; i < n; ++i) {
        cin >> get<0>(nodes[i]) >> get<1>(nodes[i]) >> get<2>(nodes[i]);
    }

    //edge       id1  id2  dist
    vector<tuple<int, int, double>> edges;
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = i + 1; j < nodes.size(); ++j) {
            edges.push_back(make_tuple(i, j, dist(nodes[i], nodes[j])));
        }
    }

    vector<int> link(nodes.size());
    for (int i = 0; i < link.size(); i++) link[i] = i;
    vector<int> size(nodes.size());
    for (int i = 0; i < size.size(); i++) size[i] = 1;
    sort(edges.begin(), edges.end(), comp);

    double totDist = 0;
    for (auto& edge : edges) {
        if (!same(get<0>(edge), get<1>(edge), link)) {
            totDist += get<2>(edge);
            unite(get<0>(edge), get<1>(edge), link, size);
        }
    }
    cout.precision(9);
    cout << totDist << endl;
    return 0;
}
