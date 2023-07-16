use std::{cmp::Reverse, collections::BinaryHeap};

fn dijkstra(graph: Vec<Vec::<(usize, usize)>>, start: usize) -> Vec<usize> {
    // 거리 정보와 이전 정점을 기록하는 배열
    let mut dist = vec![usize::MAX; graph.len()];
    let mut pred = vec![usize::MAX; graph.len()];
    
    // 방문하지 않은 가장 가까운 정점을 탐색하기 위한 우선순위 큐
    let mut priority_queue = BinaryHeap::new();

    // 시작점 설정
    dist[start] = 0;
    pred[start] = start;
    priority_queue.push((Reverse(0), start));

    // 방문이 가능한 정점이 없을 때까지 탐색
    while !priority_queue.is_empty() {
        let top = priority_queue.pop().unwrap();

        // top이 현재까지 측정한 최단 거리일 때
        if top.0.0 == dist[top.1] {
            dist[top.1] = top.0.0;

            // top의 정점의 인접 정점 탐색 시도
            for adj in &graph[top.1] {
                if dist[top.1] + adj.1 < dist[adj.0] {
                    dist[adj.0] = dist[top.1] + adj.1;
                    pred[adj.0] = top.1;
                    priority_queue.push((Reverse(dist[adj.0]), adj.0));
                }
            } 
        }
    }

    // 탐색한 최단 거리 반환, 최단 경로가 필요한 경우 pred를 반환
    dist
}