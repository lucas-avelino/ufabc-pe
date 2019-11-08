#!/usr/bin/python3

import random as rd

rd.seed(2017)

listax = []
listay = []
nint = 500
N = 200
for i in range(nint):
    x = rd.randint(-20, 20)
    y = rd.randint(-20, 20)
    listax.append(x)
    listay.append(y)

ndouble = 500
for i in range(ndouble):
    x = rd.uniform(-20, 20)
    y = rd.uniform(-20, 20)
    listax.append(x)
    listay.append(y)

n = nint + ndouble
for i in range(N):
    indices = [rd.randint(0, n - 1) for k in range(24)]
    for k in indices:
        print(listax[k], listay[k])

for i in range(N):
    indices = [rd.randint(nint, n - 1) for k in range(24)]
    for k in indices:
        print(listax[k], listay[k])        
    
for i in range(N):
    indices = [rd.randint(0, nint - 1) for k in range(24)]
    for k in indices:
        print(listax[k], listay[k])     
    
