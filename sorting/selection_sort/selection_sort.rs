fn selection_sort<T: Ord>(array: &mut [T]) {
    let len = array.len();

    // 한 번 반복할 때마다 요소 하나가 정렬됨
    for i in 0..(len - 1) {

        // 가장 작은 요소 인덱스를 저장할 변수
        let mut min_element_index = i;

        // 정렬되지 않은 배열에서 가장 작은 요소를 탐색
        for j in (i + 1)..len {
            if array[j] < array[min_element_index] {
                min_element_index = j;
            }
        }

        // 가장 작은 값을 i번째 위치로 이동
        if i != min_element_index {
            array.swap(i, min_element_index);
        }
    }
}