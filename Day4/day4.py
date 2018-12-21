#!/usr/bin/env python

import sys
from datetime import datetime

def process_line(line):
    # Line comes in as:
    # [1518-11-01 00:00] Guard #10 begins shift
    (date, comment) = line.split("] ")
    date = date.split('[')[-1]
    ymd, time = date.split(" ")
    dt = datetime(*([int(x) for x in ymd.split("-")] + [int(x) for x in time.split(":")]))
    return (dt, comment.strip())

class Guard(object):
    def __init__(self, g_id):
        self.id = g_id
        # sleeps will be represented with the start minute as the key, and the length of sleep as the value
        self.sleeps = {}

    def add_sleep(self, start, end):
        self.sleeps[start] = end - start


def construct_timeline(guardlog):
    # After sorting, we have a Guard, followed by a series of sleep/wake until the next Guard.
    # We want the guard who stays asleep for the longest interval
    for dt, comment in guardlog:
        print dt, comment
        if "Guard" in comment:

# Could also use argparse. Not worth it here.
if len(sys.argv) != 2:
    print("Usage: %s <input file>" % sys.argv[0])
    sys.exit(1)

fp = open(sys.argv[1])

dt_lines = [process_line(line) for line in fp.readlines()]
dt_lines.sort()

construct_timeline(dt_lines)


