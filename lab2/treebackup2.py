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

   #def ConvertToBinaryTree(self):
    #  self.ConvertToBinaryTree_2()
     # return True 

  # def DepthFirstOrder(self, sibling):
   #   if self.store[1] == []:
    #     return self.store[0]
     # else:
      #   for x in self.store[1]:
       #     return [self.store[0]] + [x.DepthFirstOrder()]

   def ConvertToBinaryTree(self, node, successor, sibling):
      bnode = binary_tree(node.store[0])
      if successor !=[]:
         print("Node is: " + node.store[1][0].store[0])
         successor = node.ConvertToBinaryTree(node.store[1][0], node.store[1][0].store[1],node.store[1][1:])
         bnode.AddLeft(binary_tree(successor.store[0]))
         print("Added " + successor.store[0]+ " to " + bnode.store[0])  
      if sibling !=[]:
         sibling = sibling[0].ConvertToBinaryTree(sibling[0],sibling[0].store[1], sibling[1:])
         bnode.AddRight(binary_tree(sibling.store[0]))
         print("Added "+ sibling.store[0] + " to " + bnode.store[0])
      return bnode 
      
      
     
