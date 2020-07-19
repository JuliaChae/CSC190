from stackLib import *

def bc(str_in):
   stack = LIFO() 
   openb = 0;
   closedb=0;
   index = 0;  
   for x in str_in:
      index = index + 1
      if x == "(" or x== "{" or x== "[":
         stack.push(x)
         openb = openb+1
      elif x == ")" or x=="}" or x=="]":
         closedb = closedb+1
         popped = stack.pop()
         if popped==-1:
            break
         if (x==")" and popped != "(") or (x=="{" and popped != "}") or (x =="[" and popped !="]"):
            #print(x)
            closedb = closedb-1
            break;
   if openb!=closedb:
      return[False, index]
   else:
      return [True,0]

      
         
