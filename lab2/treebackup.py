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

   def ConvertToBinaryTree(self, sibs):
      for x in sibs:
         print(x.store[0])
      root = self.store[0]
      if len(self.store[1]) == 0:
         succ = []
      else:
         if len(self.store[1])!=1:
            succsib = self.store[1][1:]
         else:
            succsib = [] 
         succ = self.store[1][0].ConvertToBinaryTree(succsib)
      if sibs == []:
         sib = []
      else:
         if len(sibs) != 1:
            sibsib = sibs[1:]
         else:
            sibsib = []
         sib = sibs[0].ConvertToBinaryTree(sibsib)
      node = binary_tree(root)
      if succ != []:
         print("Added Left " + succ.store[0]+ " to " + root)
         node.AddLeft(succ)
      if sib != []:
         print("Added Right " + sib.store[0] + " to " + root)
         node.AddRight(sib)
      return node 
      
      
      
