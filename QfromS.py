class Stack:

    def __init__(self):
        self.s = []

    def push(self, v):
        self.s.append(v)

    def pop(self):
        if self.isEmpty():
            return "Already Empty"
        return self.s.pop()
    
    def size(self):
        return len(self.s)

    def isEmpty(self):
        return self.size() == 0
    

class Queue:

    def __init__(self):
        self.s = Stack()
        self.ss = Stack()


    def enqueue(self, v):
        self.s.push(v)
    
    def dequeue(self):
        if self.s.size() == 0 and self.ss.size() == 0:
            return "Empty queue"
        elif self.ss.size() == 0:
            while (not self.s.isEmpty()):
                self.ss.push(self.s.pop())
            return self.ss.pop()
        else:
            return self.ss.pop()


q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
q.enqueue(3)
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())

        

