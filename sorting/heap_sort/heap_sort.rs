fn heap_sort<T: Ord>(array: &mut [T]) {
    let len = array.len();

    // 요소를 차례대로 추가하며 최대 힙 구조로 만듦
    for i in 1..len {
        let mut index = i + 1;
        while index > 1 && array[index - 1] > array[(index >> 1) - 1] {
            array.swap(index - 1, (index >> 1) - 1);
            index >>= 1;
        }
    }

    // 힙에서 루트를 꺼내 맨 뒤로 보내는 작업을 반복
    for i in (1..len).rev() {
        array.swap(0, i);

        let mut index = 2;
        while index <= i {
            // 더 큰 값의 자식을 선택
            if index != i && array[index - 1] < array[index] {
                index += 1;
            }

            // 교환 가능하면 교환
            if array[(index >> 1) - 1] < array[index - 1] {
                array.swap((index >> 1) - 1, index - 1);
            }
            else {
                break;
            }

            index <<= 1;
        }
    }
}