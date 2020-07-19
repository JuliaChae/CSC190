from FIFO import *

def traverse_breadth(T):
   x = queue() 
   x.enqueue(T)
   while x.empty() == False:
      r = x.dequeue()
      print(r[0])
      for i in r[1:len(r)]:
         x.enqueue(i)
     
