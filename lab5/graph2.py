class graph:
   def __init__(self):
      self.store =[]

   def addVertex(self,n):
      if n<0:
         return -1
      for x in range(0,n):
         self.store = self.store + [[]] 
      return len(self.store) 

   def addEdge(self, from_idx, to_idx, directed, weight):
      exists = False 
      if weight<0:
         return -1
      if from_idx >= len(self.store) or from_idx<0:
         return False
      if to_idx >= len(self.store) or to_idx<0:
         return False 
      if weight<0:
         return False 
      if directed == True:
         count = 2
      else:
         count = 1
      for i in range(0,count):
         if i==1:
            temp = from_idx
            from_idx = to_idx
            to_idx = temp 
         for x in self.store[from_idx]:
            if x!=[] and x[0]==to_idx:
               exists = True
         if exists == False:
            self.store[from_idx] = self.store[from_idx] + [[to_idx, weight]]
      return True   

   def traverse(self,start,typeBreadth):
      c = []
      discovered =[]
      processed = []
      accum = []
      a = []
      count = 0
      for x in self.store:
         discovered = discovered + [False]
         processed = processed + [False] 
      if start != None and (start<0 or start > len(self.store)):
         return []
      if start!=None: 
         v = start 
         if discovered[v]==False:
            c = c + [v]
            discovered[v]==True 
            #count = count + 1
            #print(count)
            #accum = accum + [0]
         while c != []:
            if typeBreadth == True:
               w = c[0]
               c = c[1:]
            else:
               w = c[len(c)-1]
               c = c[0:len(c)-1]
            if processed[w]==False:
               accum= accum + [w]
               processed[w]=True 
            for x in self.store[w]:
               if discovered[x[0]]==False:
                  c = c + [x[0]]
                  discovered[x[0]]=True
      else:
         for v in range(0,len(self.store)):   
            if discovered[v]==False:
               c = c + [v]
               discovered[v]==True 
            #count = count + 1
            #print(count)
            #accum = accum + [0]
            while c != []:
               if typeBreadth == True:
                  w = c[0]
                  c = c[1:]
               else:
                  w = c[len(c)-1]
                  c = c[0:len(c)-1]
               if processed[w]==False:
                  a= a + [w]
                  processed[w]=True 
               for x in self.store[w]:
                  if discovered[x[0]]==False:
                     c = c + [x[0]]
                     discovered[x[0]]=True
            if a != []:
               accum = accum + [a]
            a = []
      return accum  

   def connectivity(self,vx,vy):
      rval = [False,False]
      for x in self.traverse(vx,True):
         if x == vy:
            rval[0] = True
      for x in self.traverse(vy,True):
         if x == vx:
            rval[1]=True 
      return rval 

   def path_helper(self,start,end,discovered,path):
      discovered[start] = True
      if start == end:
         return path + [start]
      for edge in self.store[start]:
         if discovered[edge[0]] == False:
            p = self.path_helper(edge[0],end,discovered,path+[start])
            if p is not None:
               return p

   def path(self,vx,vy):
      discovered=[]
      for x in self.store:
         discovered = discovered+ [False]
        # processed = processed + [False]
      c = []
      rval = [None,None]
      connected = self.connectivity(vx,vy)
      if connected[0] == False and connected[1] == False:
         return [[],[]]
      if connected[0] == False and connected[1] == True:
         return [[], self.path_helper(vy,vx,discovered,c)]
      if connected[0] == True and connected[1] == False:
         return [self.path_helper(vx,vy,discovered,c),[]]
      if connected[0] == True and connected[1] == True:
         return [self.path_helper(vx, vy, discovered,c),self.path_helper(vy, vx, discovered, c)]
   
def main():
   gra=graph()
   gra.addVertex(3)
   gra.addEdge(0,2,True,3)
   print(gra.store)

main()
