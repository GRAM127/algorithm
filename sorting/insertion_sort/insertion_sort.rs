fn insertion_sort<T: Ord>(array: &mut [T]) {
    let len = array.len();

    // 한 번 반복할 때마다 요소 하나가 정렬됨
    for i in 1..len {

        // 삽입 진행
        let mut j = i;
        while j > 0 && array[j - 1] > array[j] {
            array.swap(j, j - 1);
            j -= 1;
        }
    }
}