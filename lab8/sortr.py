def sortr(L):
   maxDigit = False 
   temp = -1
   placement = 1
   table = []
   while not maxDigit:
      maxDigit = True 
      table = []
      for i in range(0,10):
         table = table + [[]]
      for i in L:
         temp = i//placement 
         table[temp%10]= table[temp%10] + [i]
         if maxDigit and temp > 0:
            maxDigit = False
      index = 0 
      for i in range(0,10):
         for x in table[i]:
            L[index]=x
            index = index + 1
      placement = placement*10
   return 0
