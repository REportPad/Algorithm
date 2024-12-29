def triangle_containment(x,y):
  s0 = 0.5*abs(x[0]*(y[1]-y[2]) +x[1]*(y[2]-y[0]) +x[2]*(y[0]-y[1]))
  s1 = 0.5*abs(x[1]*(y[2]) +x[2]*(-y[1]))
  s2 = 0.5*abs(x[0]*(-y[2]) +x[2]*(y[0]))
  s3 = 0.5*abs(x[0]*(y[1]) +x[1]*(-y[0]))

  if s0 == s1+s2+s3:
    return 1
  return 0

arr = []
with open('0102_triangles.txt', 'r', encoding='utf-8') as file:
  lines = file.readlines()
  for line in lines:
    arr.append(line.strip())

cnt=0
for a in arr:
  x = [0]*3
  y = [0]*3
  k=0
  i=0
  while i < 3:
    t = ''
    while a[k] != ',':
      t += a[k]
      k+=1
    x[i] = int(t)
    k+=1

    t=''
    while a[k] != ',':
      t += a[k]
      if k+1 < len(a):
        k+=1
      else:
        break
    y[i] = int(t)
    k+=1
    i+=1
    # print(x,y)

  cnt += triangle_containment(x,y)
print(cnt)
