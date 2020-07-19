class FIFO:
   def __init__(self):
      self.queue = []

   def enqueue(self, val):
      self.queue = self.queue+ [val] 
      return 0

   def dequeue(self):
      if len(self.stack)==0:
         return -1
      popped = self.stack[0]
      self.stack = self.stack[1:len(self.stack)]
      return popped 
   
   def empty():
      if len(self.stack)==0:
         return True
