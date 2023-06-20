fn merge_sort<T: Ord + Copy>(array: &mut [T]) {
    let len = array.len();

    if len < 2 {
        return;
    }

    let mid = len / 2;

    // 배열을 반으로 나눈 후 각각 재귀적으로 정렬
    merge_sort(&mut array[0..mid]);
    merge_sort(&mut array[mid..len]);
    
    let mut merged = Vec::with_capacity(len);

    let mut left = 0;
    let mut right = mid;

    // 부분 배열 합치기
    while left < mid && right < len {
        if array[left] <= array[right] {
            merged.push(array[left]);
            left += 1;
        }
        else {
            merged.push(array[right]);
            right += 1;
        }
    }
    for i in left..mid {
        merged.push(array[i]);
    }
    for i in right..len {
        merged.push(array[i]);
    }

    // 원래 배열에 합친 결과 넣기 
    array.copy_from_slice(&merged);
}