from Queue import *
from binary_tree import *
class tree: 

   def __init__(self,x):
      self.store = [x,[]]
      self.depthfirst = []

   def AddSuccessor (self,x):
      self.store[1] = self.store[1]+[x]
      return True

   def getSuccessors (self):
      return self.store[1]

   def Print_DepthFirst_2(self,indent):
      print(indent +str(self.store[0])) 
      for x in self.store[1]:
         x.Print_DepthFirst_2(indent+"   ")
      return True

   def Print_DepthFirst(self):
      self.Print_DepthFirst_2("")
      return True

   def Get_LevelOrder(self):
      x =Queue()
      x.enqueue(self)
      accum = []
      while x.empty() == False:
         r=x.dequeue()
         accum = accum + [r.store[0]]
         for i in r.store[1]:
            x.enqueue(i)
      print(accum)

   def ConvertToBinaryTree(self):
      return self.ConvertToBinaryTree_2(binary_tree(self.store[0]),self.store[1],[])

   def ConvertToBinaryTree_2(self, bnode, successor, sibling):
      if successor !=[]:
         bnode.AddLeft(binary_tree(successor[0].store[0]))
         self.ConvertToBinaryTree_2(bnode.store[1], successor[0].store[1], successor[1:])
      if sibling !=[]:
         bnode.AddRight(binary_tree(sibling[0].store[0]))
         self.ConvertToBinaryTree_2(bnode.store[2],sibling[0].store[1], sibling[1:])
      return bnode 
      
      
     
