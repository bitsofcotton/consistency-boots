import sys

ports = []
for p in range(0, 65536):
  ports.append(0)
bp = 0
for line in sys.stdin:
  p = int(line.split(":")[- 2].split(".")[- 1])
  ports[p] += 1
  if(p != bp): print(bp, ports[bp])
  bp = p

