from collections import deque
class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = deque([])
        self.queue2 = deque([])

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.append(x)
        while self.queue2:
            self.queue1.append(self.queue2.popleft())

        tempqueue = self.queue1
        self.queue1 = self.queue2
        self.queue2 = tempqueue

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue2.popleft()

    def top(self) -> int:
        """
        Get the top element.
        """
        element = self.queue2.popleft()
        self.queue1.append(element)

        while self.queue2:
            self.queue1.append(self.queue2.popleft())

        while self.queue1:
            self.queue2.append(self.queue1.popleft())

        return element


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue2) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
