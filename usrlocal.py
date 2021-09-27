#! /usr/bin/env python

import os
import sys
import subprocess

last = ""
files = {""}
sym   = {""}
pkgs  = {""}
hashe = {""}
sizee = {""}
opene = {""}
for root, dirs, filesw in os.walk("/usr/local"):
  for f in filesw:
    if(os.path.islink(root + "/" + f)):
      sym.add(root + "/" + f)
    else:
      files.add(root + "/" + f)
for root, dirs, filesw in os.walk("/var/db/pkg"):
  for f in filesw:
    if(f == "+CONTENTS"):
      for line in open(root + "/" + f, "r").readlines():
        if(len(line) <= 1): continue
        if(line[0] == "@"):
          arr = line[1:- 1].split(" ")
          if(arr[0] == "bin" or arr[0] == "lib" or arr[0] == "man" or arr[0] == "shell" or arr[0] == "so" or arr[0] == "static-lib" or arr[0] == "info" or arr[0] == "unexec-delete"):
            last = "/usr/local/" + arr[1]
            pkgs.add("/usr/local/" + arr[1])
          if(last == ""): continue
          try:
            if(arr[0] == "sha"):
              if(0 < len(last) and \
                 arr[1] != subprocess.check_output(["/bin/sha256", "-b", last]).decode("utf-8")[:- 1].split(" ")[- 1]):
                print(arr[1])
                print(subprocess.check_output(["/bin/sha256", "-b", last]).decode("utf-8")[:- 1].split(" ")[- 1])
                hashe.add(last)
            if(arr[0] == "size"):
              if(0 < len(last) and int(arr[1]) != os.stat(last).st_size):
                sizee.add(last)
          except:
            opene.add(last)
        else:
          last = "/usr/local/" + line[:- 1]
          pkgs.add("/usr/local/" + line[:- 1])

print("/usr/local - /var/db/pkg")
for line in sorted(list(files - pkgs)):
  print(line)

print("")
print("/var/db/pkg - /usr/local")
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

print("")
print("symbolic links")
for line in sorted(list(sym)):
  print(line)

