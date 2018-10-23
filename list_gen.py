import random
import sys

a = range(int(sys.argv[1]))
random.shuffle(a)
for b in a:
    print b,
