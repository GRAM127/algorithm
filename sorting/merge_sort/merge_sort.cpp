#include <algorithm>
#include <cstddef>
#include <vector>

template<typename T>
void merge_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
  size_t len = end - begin;

  if (len < 2) {
    return;
  }

  size_t mid = len / 2;

  // 배열을 반으로 나눈 후 각각 재귀적으로 정렬
  merge_sort<T>(begin, begin + mid);
  merge_sort<T>(begin + mid, end);

  // 부분 배열 정렬 결과 임시 배열에 저장
  auto temp = vector(begin, end);

  size_t left = 0;
  size_t right = mid;
  auto iter = begin;

  // 부분 배열 합치기
  while (left < mid && right < len) {
    if (temp[left] <= temp[right]) {
      *iter++ = temp[left++];
    }
    else {
      *iter++ = temp[right++];
    }
  }
  while (left < mid) {
    *iter++ = temp[left++];
  }
  while (right < len) {
    *iter++ = temp[right++];
  }
}