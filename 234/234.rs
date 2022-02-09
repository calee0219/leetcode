// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        // Triverse
        let mut helper = head.as_ref();
        let mut arr: [i32; 100000] = [0; 100000];
        let mut depth: usize = 0;
        // while helper.is_some() {
        //     arr[depth] = helper.unwrap().val;
        //     depth += 1;
        //     helper = helper.unwrap().next.as_ref();
        // }
        while let Some(mut node) = helper {
            arr[depth] = node.val;
            depth += 1;
            helper = node.next;
        }
        // Check palindrome
        for idx in 0..(depth/2+1) {
            if arr[idx] != arr[depth-1-idx] {
                return false
            }
        }
        true
    }
}
