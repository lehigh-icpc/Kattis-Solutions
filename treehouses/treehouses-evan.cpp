/*
Evan Hruskar
treehouses
2019-03-17 23:45:15
0.47 s
*/

//This c++ implementation is terrible.

//#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

class Point;
class Edge;
//class Tree;
double distance(Point *point1, Point *point2);

//class Tree {
//public:
//  vector<Point*> points;
//  Tree() {
//
//  }
//  void combine(Tree *other, vector<Tree*> &treeList);
//};

class Point {
public:
    double x, y;
    int id;
    //Tree *tree; //alias for a tree.
    Point(double x, double y, int id) {
        this->x = x;
        this->y = y;
        this->id = id;
        //this->tree = parent;
        //parent->points.push_back(this);
    }
};

class Edge {
public:
    Point *point1, *point2;
    double dist;
    Edge(Point *point1, Point *point2) {
        this->point1 = point1;
        this->point2 = point2;
        this->dist = distance(this->point1, this->point2);
    }

    //Make these const for better style (?)
    bool operator>(Edge &other) {
        return dist > other.dist;
    }

    bool operator<(Edge &other) {
        return dist < other.dist;
    }
};

double distance(Point *point1, Point *point2) {
    //is any of this mapping necessary?
    static map<tuple<double, double, double, double>, double> distMap;
    auto check1 = make_tuple(point1->x, point2->x, point1->y, point2->y);
    auto check1result = distMap.find(check1);
    if (check1result != distMap.end()) {
        return check1result->second;
    }
    else {
        auto check2 = make_tuple(point2->x, point1->x, point2->y, point1->y); //necessary?
        double dist = sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
        distMap.insert(make_pair(check1, dist));
        distMap.insert(make_pair(check2, dist));
        return dist;
    }
}

void printPointVector(vector<Point *> pointList) {
    cout << "[";
    for (Point* point : pointList) {
        cout << point->id << ":(" << point->x << ", " << point->y << "), ";
    }
    cout << "]" << endl;
}

void printEdgeVector(vector<Edge> edgeList) {
    cout << "[";
    for (Edge edge : edgeList) {
        cout << "(" << edge.point1->id << ", " << edge.point2->id << "):" << edge.dist << ", ";
    }
    cout << "]" << endl;
}

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

bool same(int a, int b, vector<int> &link) {
    return find(a, link) == find(b, link);
}

//this can be used on any points, not just representations!
void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b]) {
        size[b] += size[a];
        link[a] = b;
    }
    else {
        size[a] += size[b];
        link[b] = a;
    }
}

int main() {
    int n, e, p;
    cin >> n >> e >> p;
    //cin.ignore();

    if (e == n) {
        cout << 0 << endl;
        return 0;
    }

    double distCount = 0.0;
    vector<Point *> pointList;

    //Should this be a deque instead???
    vector<Edge> edgeList;

    //new kruskal's stuff:
    vector<int> link(1000); //contains index of next node in chain of representaiton.
    vector<int> size(1000); // contains size of representation.

    for (int index = 0; index < n; index++) {
        double x, y;
        cin >> x >> y;

        if (e != 0 && index == 0) {
            //first iteration link creation.
            link[0] = 0; //zero'th element links back to itself.
            size[0] = 1; //zero'th element has size 1 (one node).
            Point* pointPtr = new Point(x, y, index);
            pointList.push_back(pointPtr);
            e -= 1;
        }
        else if (e != 0) {
            //treehouses which are linked. (walking distance)
            link[index] = 0; //links to zero'th element
            size[index] = 0;
            size[0] += 1; //set grows by one
            Point* pointPtr = new Point(x, y, index);
            pointList.push_back(pointPtr);
            e -= 1;
        } 
        else {
            //treehouses which are not linked.
            link[index] = index; //links to itself.
            size[index] = 1; //has size of one
            Point* pointPtr = new Point(x, y, index);
            pointList.push_back(pointPtr);
        }
    }
    //printPointVector(pointList);
    //cout << "[";
    //for (auto item : link) {
    //  cout << item << ", ";
    //}
    //cout << "]" << endl;

    //create new connections
    for (int i = 0; i < p; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        id1 -= 1;
        id2 -= 1;
        
        if (!same(id1, id2, link)) {
            //only connect if they're not already connected
            unite(id1, id2, link, size);
        }
    }

    //create all of the edges between different trees
    for (int i = 0; i < pointList.size(); i++) {
        for (int j = i + 1; j < pointList.size(); j++) {
            edgeList.push_back(Edge(pointList[i], pointList[j]));
        }
    }

    //sort the edges (thank god these aren't pointers)
    sort(edgeList.begin(), edgeList.end());
    
    //printEdgeVector(edgeList);

    //just go through the entire edge list?
    for (int i = 0; i < edgeList.size(); i++) {
        //take the smallest edge (a copy)
        Edge canEdge = edgeList[i];
        //cout << same(0, 1, link) << endl;
        //cout << "same " << canEdge.point1->id << " vs " << canEdge.point2->id << " " << same(canEdge.point1->id, canEdge.point1->id, link) << endl;


        //make sure they aren't already connected
        if (!same(canEdge.point1->id, canEdge.point2->id, link)) {
            //connect them
            unite(canEdge.point1->id, canEdge.point2->id, link, size);
            //pointList[canEdge.point1->id - 1]->tree->combine(pointList[canEdge.point2->id - 1]->tree, treeList);
            
            //add to dist counter
            distCount += canEdge.dist;
        }
        //cout << "[";
        //for (auto item : link) {
        //  cout << item << ", ";
        //}
        //cout << "]" << endl;
    }
    
    cout << distCount << endl;

    //printPointVector(pointList);
    //printTreeVector(treeList);
    //printEdgeVector(edgeList);
    return 0;
}
