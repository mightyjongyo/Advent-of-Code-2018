#!/usr/bin/env python

import sys
from collections import defaultdict

def check_num(word, num):
    lettermap = defaultdict(int)
    for l in word:
        lettermap[l] = lettermap[l] + 1
    for key, count in lettermap.items():
        if count == num:
            print line, key
            return True


if len(sys.argv) != 2:
    print "Usage: %s <input file>", sys.argv[0]
    sys.exit(1)

fp = open(sys.argv[1])

two_count = 0
three_count = 0

for line in fp.readlines():
    if check_num(line, 2):
        two_count = two_count + 1
    if check_num(line, 3):
        three_count = three_count + 1

print two_count * three_count

fp.close()
