use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res: Vec<i32> = vec![0, 0];
        let mut map: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            if let Some(n) = map.get(&(target - nums[i])) {
                res[0] = *n;
                res[1] = i as i32;
                break;
            } else {
                map.insert(nums[i], i as i32);
            }
        }
        res
    }
}