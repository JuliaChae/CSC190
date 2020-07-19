class LIFO:
   def __init__(self):
      self.stack = []

   def push(self, val):
      self.stack = self.stack + [val]
      return 0

   def pop(self):
      if len(self.stack)==0:
         return -1
      popped = self.stack[-1]
      self.stack = self.stack[0:len(self.stack)-1]
      return popped 
