def f(num):
   if num<0:
      return False
   if num==90:
      return 100
   return num%90 + 10

print(f(90))
