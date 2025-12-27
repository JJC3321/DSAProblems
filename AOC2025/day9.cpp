#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;


long long solutionPartOne(vector<string>& rawData) {

	long long maxArea = 0;
	vector<pair<long long, long long >> points;

	for(const string& line : rawData) {
		stringstream ss(line);
		long long x, y;
		char comma;

		if(ss >> x >> comma >> y) {
			points.push_back({x, y});
		}
	}

	for(size_t i = 0; i < points.size(); i++) {
		for (size_t j = i + 1; j < points.size(); j++) {
			long long width = abs(points[i].first - points[j].first) + 1;
			long long height = abs(points[i].second - points[j].second) + 1;
			long long area = width * height;
			if (area > maxArea) {
				maxArea = area;
			}
		}
	}

	return maxArea;
}

struct Point {
    long long x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            return hash<long long>()(p.x) ^ (hash<long long>()(p.y) << 1);
        }
    };
}


bool check_rectangle(Point p1, Point p2, const unordered_set<Point>& outer_edge) {
    long long min_x = min(p1.x, p2.x), max_x = max(p1.x, p2.x);
    long long min_y = min(p1.y, p2.y), max_y = max(p1.y, p2.y);

    for (long long x = min_x; x <= max_x; x++) {
        if (outer_edge.find({x, min_y}) != outer_edge.end() || 
            outer_edge.find({x, max_y}) != outer_edge.end()) {
            return false;
        }
    }

    for (long long y = min_y; y <= max_y; y++) {
        if (outer_edge.find({min_x, y}) != outer_edge.end() || 
            outer_edge.find({max_x, y}) != outer_edge.end()) {
            return false;
        }
    }
    return true;
}


long long solutionPartTwo(vector<string>& rawData) {
    vector<Point> points;
    for (const string& line : rawData) {
        stringstream ss(line);
        long long x, y; char c;
        if (ss >> x >> c >> y) points.push_back({x, y});
    }

    if (points.empty()) return 0;

    unordered_set<Point> edges, outer_edge;
    auto get_direction = [](Point p1, Point p2) {
        if (p1.x == p2.x) return p1.y < p2.y ? "DOWN" : "UP";
        return p1.x < p2.x ? "RIGHT" : "LEFT";
    };

    for (size_t i = 0; i < points.size(); i++) {
        Point p1 = points[i], p2 = points[(i + 1) % points.size()];
        string dir = get_direction(p1, p2);
        long long dx = abs(p1.x - p2.x), dy = abs(p1.y - p2.y);

        for (long long step = 0; step <= max(dx, dy); step++) {
            long long cur_x = p1.x + (dx ? (p2.x > p1.x ? step : -step) : 0);
            long long cur_y = p1.y + (dy ? (p2.y > p1.y ? step : -step) : 0);
            edges.insert({cur_x, cur_y});

            if (dir == "UP") outer_edge.insert({cur_x - 1, cur_y});
            else if (dir == "RIGHT") outer_edge.insert({cur_x, cur_y - 1});
            else if (dir == "DOWN") outer_edge.insert({cur_x + 1, cur_y});
            else if (dir == "LEFT") outer_edge.insert({cur_x, cur_y + 1});
        }
    }

    for (auto const& e : edges) outer_edge.erase(e);


    long long maxArea = 0;
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            long long width = abs(points[i].x - points[j].x) + 1;
            long long height = abs(points[i].y - points[j].y) + 1;
            long long area = width * height;
            
            if (area <= maxArea) continue;
            
            if (check_rectangle(points[i], points[j], outer_edge)) {
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}


int main() {

	vector<string> rawData;
	string content;
	ifstream inputFile("input.txt");
	while(getline(inputFile, content)) {
		rawData.push_back(content);
	}
	inputFile.close();

	long long answer1 = solutionPartOne(rawData);
	cout << answer1 << endl;
	long long answer2 = solutionPartTwo(rawData);
	cout << answer2;

	return 0;
}
