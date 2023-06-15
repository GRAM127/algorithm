#include <vector>

using namespace std;

template<typename T>
void selection_sort(vector<T>& vec) {
  size_t len = vec.size();

  // 한 번 반복할 때마다 요소 하나가 정렬됨
  for (size_t i = 0; i < len - 1; i++) {

    // 가장 작은 요소 인덱스를 저장할 변수
    size_t min_element_index = i;

    // 정렬되지 않은 배열에서 가장 작은 요소를 탐색
    for (size_t j = i + 1; j < len; j++) {
      if (vec[j] < vec[min_element_index]) {
        min_element_index = j;
      }
    }

    // 가장 작은 값을 i번째 위치로 이동
    if (i != min_element_index) {
      swap(vec[i], vec[min_element_index]);
    }
  }
}