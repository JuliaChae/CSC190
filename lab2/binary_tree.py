from Queue import *
from tree import *

class binary_tree:
   def __init__(self, x):
      self.store = [x, [], []]

   def AddLeft(self, tree):
      self.store[1] = tree
      return True

   def AddRight(self, tree):
      self.store[2] = tree
      return True 

   def Print_tree(self, indent):
      print(indent + str(self.store[0]))
      for x in range(1,3):
         if self.store[x] != []:
            self.store[x].Print_tree(indent + "   ")
      return True
   
   def Get_LevelOrder(self):
      x =Queue()
      x.enqueue(self)
      accum = []
      while x.empty() == False:
         r=x.dequeue()
         #print(r.store[0])
         accum = accum + [r.store[0]]
         for i in range(1,3):
            if r.store[i] != []:
               x.enqueue(r.store[i])
      print(accum)
 
   def ConvertToTree(self):
      root = self.store[0]
      rtree = tree(root)
      if self.store[1]!=[]:
         successor = self.store[1]
         while True:
            succ = successor.ConvertToTree()
            rtree.AddSuccessor(succ)
            if successor.store[2]!=[]:
               successor = successor.store[2]
            else:
               break
      return rtree
            
         
             
         
