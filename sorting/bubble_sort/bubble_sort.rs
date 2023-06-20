fn bubble_sort<T: Ord>(array: &mut [T]) {
    let len = array.len();
    
    // 한 번 반복할 때마다 요소 하나가 정렬됨
    for i in (1..len).rev() {
        
        // 정렬 완료 여부를 확인하는 변수
        let mut sorted = true;
        
        for j in 0..i {
            if array[j] > array[j + 1] {
                // 앞 요소가 크다면 교환
                array.swap(j, j + 1);
                sorted = false;
            }
        }
        
        if sorted {
            break;
        }
    }
}