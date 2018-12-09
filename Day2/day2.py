#!/usr/bin/env python3

import sys
from collections import defaultdict

def check_num(word, num):
    lettermap = defaultdict(int)
    for l in word:
        lettermap[l] = lettermap[l] + 1
    for key, count in lettermap.items():
        if count == num:
            #print(line, key)
            return True

def part1(words):
    two_count = 0
    three_count = 0

    for line in words:
        if check_num(line, 2):
            two_count = two_count + 1
        if check_num(line, 3):
            three_count = three_count + 1

    print(two_count * three_count)

def count_uncommon(word1, word2):
    uncom_count = 0
    # We assume that the words are the same length
    for i in range(0, len(word1)):
        if word1[i] != word2[i]:
            uncom_count = uncom_count + 1
    #print("Uncommon count for %s, %s: %d"%(word1.strip(), word2.strip(), uncom_count))
    return uncom_count

def part2(words):
    # we're taking an iterative approach. not elegant but it works
    for word1 in words:
        words2 = words
        del words2[words2.index(word1)]
        for word2 in words2:
            if count_uncommon(word1, word2) == 1:
                #print(word1.strip(), word2.strip())
                common_array = [x for (x,y) in list(zip(word1.strip(),word2.strip())) if x == y]
                print("".join(common_array))
                sys.exit(0)


if len(sys.argv) != 2:
    print("Usage: %s <input file>", sys.argv[0])
    sys.exit(1)

fp = open(sys.argv[1])

words = fp.readlines()

part1(words)
part2(words)

fp.close()
