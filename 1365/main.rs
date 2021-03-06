impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut counts = vec![0i32; 101];

        for n in nums.iter() {
            counts[*n as usize] += 1;
        }

        for i in 1..101 {
            counts[i] += counts[i-1];
        }
        
        let mut res: Vec<i32> = Vec::new();
        for n in nums.iter() {
            match n {
                0 => res.push(0),
                _ => res.push(counts[(*n as usize) - 1]),
            }
        }

        res

       // let mut counts = vec![0; 102]; // 0
       // nums.iter().for_each(|&n| counts[1 + n as usize] += 1);
       // (1..counts.len()).for_each(|n| counts[n] += counts[n-1]);
       // nums.iter().map(|&n| counts[n as usize]).collect() // map is lazy evaluation
    }
}