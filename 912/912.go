func merge(arr []int, arr_len int) {
    if arr_len == 1 {
        return;
    }
    var sub1 []int;
    var sub2 []int;
    for i := 0; i < arr_len / 2; i++ {
        sub1 = append(sub1, arr[i]);
    }
    for i := arr_len / 2; i < arr_len; i++ {
        sub2 = append(sub2, arr[i]);
    }
    
    sub1_len := arr_len/2;
    sub2_len := arr_len - arr_len/2;
    
    merge(sub1, sub1_len);
    merge(sub2, sub2_len);
    
    sub1_idx := 0;
    sub2_idx := 0;
    for ; sub1_idx+sub2_idx < arr_len; {
        if sub1_idx < sub1_len && sub2_idx < sub2_len && sub1[sub1_idx] <= sub2[sub2_idx] {
            arr[sub1_idx+sub2_idx] = sub1[sub1_idx];
            sub1_idx++;
        } else if sub2_idx < sub2_len {
            arr[sub1_idx+sub2_idx] = sub2[sub2_idx];
            sub2_idx++;
        } else {
            arr[sub1_idx+sub2_idx] = sub1[sub1_idx];
            sub1_idx++;
        }
    }
}

func sortArray(nums []int) []int {
    merge(nums, len(nums));
    return nums;
}

// func sortArray(nums []int) []int {
//     for i := 0; i < len(nums); i++ {
//         for j := i; j < len(nums); j++ {
//             if nums[i] > nums[j] {
//                 nums[i], nums[j] = nums[j], nums[i];
//             }
//         }
//     }
//     return nums;
// }