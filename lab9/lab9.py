def quicksort(u, ini, fin):
   if (fin-ini)>0:
      p = partition(u, ini, fin)
      quicksort(u, ini, p-1)
      quicksort(u, p+1, fin)
   return True 

def partition(u, ini,fin):
   p = fin
   pivot = ini
   for i in range(ini,fin):
      if u[i]<u[p]:
         temp = u[i]
         u[i] = u[pivot]
         u[pivot] = temp 
         pivot=pivot+1
   temp = u[p]
   u[p] = u[pivot]
   u[pivot] = temp
   return pivot 

def hanoi (n, start, tmp, final):
   if n>0:
      hanoi(n-1,start, final, tmp)
      final.append(start.pop())
      hanoi(n-1,tmp, start, final)
      print (start)
      print(tmp)
      print(final)
      return True
   else:
      return True

