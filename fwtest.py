import sys
import re

pat0 = re.compile('192\.168\.4\.4\.([0-9]+): S')
pat1 = re.compile('192\.168\.4\.4\.([0-9]+): udp')

a0 = {- 1}
a1 = {- 1}
for line in sys.stdin:
  m = pat0.search(line)
  if(m != None):
    a0.add(int(m.group(1)))
  m = pat1.search(line)
  if(m != None):
    a1.add(int(m.group(1)))
b = {- 1}
for i in range(0, 65536):
  b.add(i)
print(str(b - a0).replace(' ', ''))
print(str(b - a1).replace(' ', ''))

