#include <algorithm>
#include <vector>

template<typename T>
void heap_sort(std::vector<T>& vec) {
  size_t len = vec.size();

  // 요소를 차례대로 추가하며 최대 힙 구조로 만듦
  for (size_t i = 1; i < len; i++) {
    size_t index = i + 1;
    while (index > 1 && vec[index - 1] > vec[(index >> 1) - 1]) {
      std::swap(vec[index - 1], vec[(index >> 1) - 1]);
      index >>= 1;
    }
  }

  // 힙에서 루트를 꺼내 맨 뒤로 보내는 작업을 반복
  for (size_t i = len - 1; i >= 1; i--) {
    std::swap(vec[0], vec[i]);

    size_t index = 2;
    while (index <= i) {
      // 더 큰 값의 자식을 선택
      if (index != i && vec[index - 1] < vec[index]) {
        index += 1;
      }

      // 교환 가능하면 교환
      if (vec[(index >> 1) - 1] < vec[index - 1]) {
        std::swap(vec[(index >> 1) - 1], vec[index - 1]);
      }
      else {
        break;
      }

      index <<= 1;
    }
  }
}