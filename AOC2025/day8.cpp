#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

struct Point {
    
    long long x, y, z;
    
};

struct Connection {
    int u, v; 
    long long distSq;
};


struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};


long long solutionPartOne(vector<string>& rawData) {
    
    vector<Point> points;
            
    for(string line : rawData){
        stringstream ss(line);
        string val;
        Point p;
        getline(ss, val, ','); p.x = stoll(val);
        getline(ss, val, ','); p.y = stoll(val);
        getline(ss, val, ','); p.z = stoll(val);
        points.push_back(p);
    }
    
    vector<Connection> allPairs;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            long long dx = points[i].x - points[j].x;
            long long dy = points[i].y - points[j].y;
            long long dz = points[i].z - points[j].z;
            allPairs.push_back({i, j, dx*dx + dy*dy + dz*dz});
        }
    }
    
    sort(allPairs.begin(), allPairs.end(), [](const Connection& a, const Connection& b) {
        return a.distSq < b.distSq;
    });
    
    
    DSU dsu(points.size());
    int connectionsMade = 0;
    for (int i = 0; i < allPairs.size() && connectionsMade < 1000; ++i) {
        dsu.unite(allPairs[i].u, allPairs[i].v);
        connectionsMade++;
    }
    
    vector<long long> finalSizes;
    for (int i = 0; i < points.size(); ++i) {
        if (dsu.find(i) == i) {
             finalSizes.push_back(dsu.size[i]);
        }
    }
    
    sort(finalSizes.rbegin(), finalSizes.rend());
        
    return finalSizes[0] * finalSizes[1] * finalSizes[2];
}

long long solutionPartTwo(vector<string>& rawData){
    vector<Point> points;
    for (const string& line : rawData) {
        stringstream ss(line);
        string val;
        Point p;
        getline(ss, val, ','); p.x = stoll(val);
        getline(ss, val, ','); p.y = stoll(val);
        getline(ss, val, ','); p.z = stoll(val);
        points.push_back(p);
    }
    
    vector<Connection> allPairs;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            long long dx = points[i].x - points[j].x;
            long long dy = points[i].y - points[j].y;
            long long dz = points[i].z - points[j].z;
            allPairs.push_back({i, j, dx*dx + dy*dy + dz*dz});
        }
    }
    
    sort(allPairs.begin(), allPairs.end(), [](const Connection& a, const Connection& b) {
        return a.distSq < b.distSq;
    });
    
    DSU dsu(points.size());
    int components = points.size();
    
    for (const auto& edge : allPairs) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            components--;

            if (components == 1) {
                return points[edge.u].x * points[edge.v].x;
            }
        }
    }
    return 0;
    
}


int main() {
    
    vector<string> rawData; 
    string content;
    ifstream inputFile("input.txt");
    while(getline(inputFile, content)){
            rawData.push_back(content);
    }
    inputFile.close();

    long long answer1 = solutionPartOne(rawData);
    cout << answer1 << endl; 
    long long answer2 = solutionPartTwo(rawData);
    cout << answer2;
    
    return 0;
}
