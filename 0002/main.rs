// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = Some(Box::new(ListNode::new(0))); // Fake head
        let mut p = &mut head;
        let (mut h1, mut h2) = (&l1, &l2);
        let mut con: i32 = 0;  // carry
        let mut num: i32 = 0;
        let mut flag: i32 = 0;  // to avoid adding with 0
        loop {
            flag = 0;
            if let Some(q) = h1 {
                num += q.val;
                h1 = &q.next;
                flag = 1;
            }
            if let Some(q) = h2 {
                num += q.val;
                h2 = &q.next;
                flag = 1;
            }

            num += con;
            con = num/10;
            num = num%10;
            if num == 0 && con == 0 && flag == 0 {
                break;
            } else {
                p.as_mut().unwrap().next = Some(Box::new(ListNode::new(num)));
                p = &mut p.as_mut().unwrap().next;
            }
            num = 0;
        }

        head.unwrap().next
    }
}