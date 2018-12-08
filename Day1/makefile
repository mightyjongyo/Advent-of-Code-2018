all: day1

setup:
	mkdir bld  || true

day1:	setup
	cd bld && g++ ../day1.cpp -o day1 -std=c++14


clean:
	rm -rf bld

test:
	bld/day1 input.txt
