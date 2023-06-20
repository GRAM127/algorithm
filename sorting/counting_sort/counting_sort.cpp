#include <algorithm>
#include <vector>

void counting_sort(std::vector<int>& vec, int min_value, int max_value) {
  auto temp = std::vector(vec);
  auto cnt = new int[max_value - min_value + 1]();

  // 카운팅 작업
  for (int element : vec) {
    cnt[element - min_value]++;
  }

  // 누적 합 작업
  for (size_t i = 1; i <= max_value - min_value; i++) {
    cnt[i] += cnt[i - 1];
  }

  // 카운트 배열 참조해 알맞은 위치 찾아서 넣기
  for (size_t i = temp.size(); i > 0; i--) {
    size_t idx = temp[i - 1] - min_value;
    vec[--cnt[idx]] = temp[i - 1];
  }

  delete[] cnt;
}