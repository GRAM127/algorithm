#include <algorithm>
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& vec) {
  size_t len = vec.size();
  
  // 한 번 반복할 때마다 요소 하나가 정렬됨
  for (size_t i = len - 1; i >= 1; i--) {
   
    // 정렬 완료 여부를 확인하는 변수
    bool sorted = true;
    
    for (size_t j = 0; j < i; j++) {
      if (vec[j] > vec[j + 1]) {
        // 앞 요소가 크다면 교환
        std::swap(vec[j], vec[j + 1]);
        sorted = false;
      }
    }

    if (sorted) {
      break;
    }
  }
}