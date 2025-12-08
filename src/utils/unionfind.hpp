#pragma once

#include <numeric>
#include <vector>

//disjoint set (union-find data structure) https://github.com/xiety/AdventOfCode/blob/main/Advent.Common/DSU.cs
struct unionFind {
  std::vector<int> parent;
  std::vector<int> size;
  std::vector<int> rank;

  int count;

  unionFind(int n) : parent(n), size(n), rank(n), count(n) {
    for(int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);

    return parent[x];
  }

  void unite(int i, int j) {
    int ir = find(i);
    int jr = find(j);

    if(ir == jr) return;

    if(rank[ir] < rank[jr]) {
      int temp = ir;
      ir = jr;
      jr = temp;
    }

    parent[jr] = ir;
    size[ir] += size[jr];

    if(rank[ir] == rank[jr]) rank[ir]++;
    
    count--;
  }
};