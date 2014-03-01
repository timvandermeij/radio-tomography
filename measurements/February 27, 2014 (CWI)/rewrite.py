import sys

f = open(sys.argv[1])
f2 = open(sys.argv[2], "w")

pending = {}
for i in f:
    ii = i.split(",")
    nodeid = int(ii[1])
    if nodeid == 1:
        for p in sorted(pending.keys()):
            f2.write(pending[p])
        pending = {}
    pending[nodeid] = i
