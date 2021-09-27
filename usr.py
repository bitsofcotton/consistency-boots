#! /usr/bin/env python

import os
import sys
import subprocess

last = ""
files = {""}
pkgs  = {""}
hash  = {}
size  = {}
hashe = {""}
sizee = {""}
opene = {""}
for root, dirs, filesw in os.walk("/"):
  flg = False
  for arg in sys.argv[1:]:
    if(root[0:len("/" + arg)] == "/" + arg):
      flg = True
  if(flg): continue
  for f in filesw:
    files.add(root + "/" + f)
    last = root + "/" + f
    try:
      size[last] = os.stat(last).st_size
      hash[last] = subprocess.check_output(["/bin/sha256", last]).decode("utf-8").split(" ")[- 1]
    except:
      opene.add(root + "/" + f)
for root, dirs, filesw in os.walk("./"):
  flg = False
  for arg in sys.argv[1:]:
    if(root[1:len("/" + arg) + 1] == "/" + arg):
      flg = True
  if(flg): continue
  for f in filesw:
    pkgs.add(root[1:] + "/" + f)
    last = root[1:] + "/" + f
    try:
      if(hash[last] != subprocess.check_output(["/bin/sha256", root + "/" + f]).decode("utf-8").split(" ")[- 1]):
        hashe.add(last)
      if(size[last] != os.stat(root + "/" + f).st_size):
        sizee.add(last)
    except:
      opene.add(root + "/" + f)

print("")
print("/ - ./")
for line in sorted(list(files - pkgs)):
  if(line[- 1] != "/"):
    print(line)

print("")
print("./ - /")
for line in sorted(list(pkgs - files)):
  if(line[- 1] != "/"):
    print(line)

print("")
print("hash error")
for line in sorted(list(hashe)):
  print(line)

print("")
print("size error")
for line in sorted(list(sizee)):
  print(line)

print("")
print("open error")
for line in sorted(list(opene)):
  print(line)

