#include <cstdint>
#include <algorithm>
#include <queue>

size_t* dijkstra(std::vector<std::vector<std::pair<size_t, unsigned>>> graph, size_t start) {
  // 거리 정보와 이전 정점을 기록하는 배열
  size_t* dist = new size_t[graph.size()];
  size_t* pred = new size_t[graph.size()];
  
  std::fill(dist, dist + graph.size(), UINT32_MAX);
  std::fill(pred, pred + graph.size(), UINT32_MAX);
  
  // 방문하지 않은 가장 가까운 정점을 탐색하기 위한 우선순위 큐
  std::priority_queue<std::pair<unsigned, size_t>, std::vector<std::pair<unsigned, size_t>>, std::greater<std::pair<unsigned, size_t>>> priority_queue;
  
  // 시작점 설정
  dist[start] = 0;
  pred[start] = start;
  priority_queue.emplace(0, start);
  
  // 방문이 가능한 정점이 없을 때까지 탐색
  while (!priority_queue.empty()) {
    auto top = priority_queue.top();
    priority_queue.pop();
    
    // top이 현재까지 측정한 최단 거리일 때
    if (top.first == dist[top.second]) {
      dist[top.second] = top.first;
      
      // top의 정점의 인접 정점 탐색 시도
      for (auto adj : graph[top.second]) {
        if (dist[top.second] + adj.second < dist[adj.first]) {
          pred[adj.first] = top.second;
          priority_queue.emplace(dist[adj.first] = dist[top.second] + adj.second, adj.first);
        }
      }
    }
  }
  
  // 탐색한 최단 거리 반환, 최단 경로가 필요한 경우 pred를 반환
  delete[] pred;
  return dist;
}