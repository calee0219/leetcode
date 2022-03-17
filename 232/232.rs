struct MyQueue {
    stack: std::vec::Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        MyQueue { stack: vec![] }
    }
    
    fn push(&mut self, x: i32) {
        let mut tmpStack = vec![];
        while !self.stack.is_empty() {
            tmpStack.push(self.stack.pop().unwrap());
        }
        tmpStack.push(x);
        while !tmpStack.is_empty() {
            self.stack.push(tmpStack.pop().unwrap());
        }
    }
    
    fn pop(&mut self) -> i32 {
        self.stack.pop().unwrap()
    }
    
    fn peek(&self) -> i32 {
        *self.stack.last().unwrap()
    }
    
    fn empty(&self) -> bool {
        self.stack.is_empty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */