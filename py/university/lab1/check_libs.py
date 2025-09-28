import math 
import random
import hashlib

print("Косинус 0: ", math.cos(0))
print("Випадкове число: ", random.randint(1, 10))

data = "student"
h = hashlib.sha256(data.encode()).hexdigest()
print("SHA256: ", h)
