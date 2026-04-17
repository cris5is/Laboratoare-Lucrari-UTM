import numpy as np

arr=np.random.randint(-10,10,(3,3))

print(arr)

media=np.mean(arr)
minim=np.min(arr)
maxim=np.max(arr)
determinant= np.linalg.det(arr)

print(f"\nMedia: {media}\nMinim: {minim}\nMaxim: {maxim}\nDeterminantul: {determinant}")