fn quick_sort<T: Ord>(array: &mut [T]) {
    let len = array.len();
    
    if len < 2 {
        return;
    }

    let mut left = 1;
    let mut right = len - 1;

    // 피벗 기준으로 분할
    while left <= right {
        
        // 왼쪽에서 피벗보다 큰 요소 찾기
        while left < len && array[left] <= array[0] {
            left += 1;
        }
        
        // 오른쪽에서 피벗보다 작은 요소 찾기
        while right > 0 && array[right] >= array[0] {
            right -= 1;
        }

        // 각각 찾은 요소 교환해서 왼쪽에는 피벗보다 작은 요소, 오른쪽에는 피벗보다 큰 요소가 오도록 만듦
        if left < right {
            array.swap(left, right);
        }
    }

    // 피벗을 나눈 배열 가운데로 이동
    array.swap(0, right);

    // 재귀적으로 정렬
    quick_sort(&mut array[0..right]);
    quick_sort(&mut array[(right + 1)..len]);
}