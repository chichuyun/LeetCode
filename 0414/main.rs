use std::collections::{HashSet, BinaryHeap};
use std::cmp::{max, Reverse};

impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {
        let mut sets: HashSet<i32> = HashSet::new();
        let mut maxs: BinaryHeap<Reverse<i32>> = BinaryHeap::new();

        for n in nums.into_iter() {
            if(!sets.contains(&n)) {
                if maxs.len() < 3  {
                    sets.insert(n);
                    maxs.push(Reverse(n));
                } else if n > maxs.peek().unwrap().0 {
                    sets.remove(&n);
                    maxs.pop();
                    sets.insert(n);
                    maxs.push(Reverse(n));
                }
            }
        }
        if sets.len()==2 {
            maxs.pop();
        }
        maxs.peek().unwrap().0
    }
}