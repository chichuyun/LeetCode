impl Solution {
    pub fn subarrays_div_by_k(a: Vec<i32>, k: i32) -> i32 {
        let mut nums = vec![0; k as usize];
        nums[0] += 1;
        let (mut num, mut count): (i32, i32) = (0, 0);
        for n in a.iter() {
            num = (num + n)% k;
            if num < 0 {
                num += k;
            }
            count += nums[num as usize];
            nums[num as usize] += 1;
        }
        count
    }
}