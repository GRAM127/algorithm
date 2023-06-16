#include <algorithm>
#include <vector>

template<typename T>
void quick_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
  
  // 배열의 반복자(iterator)를 이용해 정렬 범위를 나타냄, 반복자 간 거리가 1 이하이면 정렬 불필요
  if (end - begin < 2) {
    return;
  }
  
  auto left = begin + 1;
  auto right = end - 1;
  
  // 피벗 기준으로 분할
  while (left <= right) {

    // 왼쪽에서 피벗보다 큰 요소 찾기
    while (left < end && *left <= *begin) {
      left++;
    }
    
    // 오른쪽에서 피벗보다 작은 요소 찾기
    while (right > begin && *right >= *begin) {
      right--;
    }
    
    // 각각 찾은 요소 교환해서 왼쪽에는 피벗보다 작은 요소, 오른쪽에는 피벗보다 큰 요소가 오도록 만듦
    if (left < right) {
      std::swap(*left, *right);
    }
  }
  
  // 피벗을 나눈 배열 가운데로 이동
  std::swap(*begin, *right);
  
  // 재귀적으로 정렬
  quick_sort<T>(begin, right);
  quick_sort<T>(right + 1, end);
}