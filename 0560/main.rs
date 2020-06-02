use std::collections::HashMap;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut pres: HashMap<i32,i32> = HashMap::new();
        let mut pre: i32 = 0;
        let mut count: i32 = 0;
        pres.insert(0, 1);
        for n in nums.iter() {
            pre += n;
            if let Some(&m) = pres.get(&(pre-k)) {
                count += m;
            }
            pres.entry(pre).and_modify(|m| *m += 1).or_insert(1);
        }
        return count;
    }
}