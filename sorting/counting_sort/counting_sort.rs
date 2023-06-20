fn counting_sort(array: &mut [i32], min_value: i32, max_value: i32) {
    let temp = array.to_vec();
    let mut cnt = vec![0usize; (max_value - min_value + 1) as usize];

    // 카운팅 작업
    for element in array.iter() {
        cnt[(*element - min_value) as usize] += 1;
    }

    // 누적 합 작업
    for i in 1..cnt.len() {
        cnt[i] += cnt[i - 1];
    }

    // 카운트 배열 참조해 알맞은 위치 찾아서 넣기
    for element in temp.iter().rev() {
        let idx = (*element - min_value) as usize;
        cnt[idx] -= 1;
        array[cnt[idx]] = *element;
    }
}