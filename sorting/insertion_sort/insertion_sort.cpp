#include <vector>

using namespace std;

template<typename T>
void insertion_sort(vector<T>& vec) {
  size_t len = vec.size();

  // 한 번 반복할 때마다 요소 하나가 정렬됨
  for (size_t i = 1; i < len; i++) {
    
    // 삽입 위치와 삽입할 요소를 저장하는 변수
    size_t j = i;
    T element = vec[i];
    
    // 삽입 위치 탐색
    while (j > 0 && vec[j - 1] > element) {
      vec[j] = vec[j - 1];
      j--;
    }
    
    vec[j] = element; 
  }
}