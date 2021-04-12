#pragma once
#include <tuple>
#include <vector>
#include <stack>
#include <ctime>
#include <math.h>

using namespace std;

class Points 
{
private:
	vector<pair<int, int>> nodes;

public:
	Points(){}
	~Points(){}

	bool addPoints(int x, int y) {
		pair<int, int> node;
		node.first = x;
		node.second = y;

		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i].first == x && nodes[i].second == y) {
				return false;
			}
		}

		nodes.push_back(node);
		return true;
	}

	bool cleaner() {
		if (nodes.size() > 0) {
			nodes.clear();
			return true;
		}
		else {
			return false;
		}
		
	}

	vector<pair<int, int>> getnodes() {
		return nodes;
	}

};

