#! /usr/bin/env python

import os
import sys
import subprocess

for d in os.listdir(sys.argv[1]):
  if(d[- len(sys.argv[2]):] == sys.argv[2]):
    subprocess.call(['tar', 'xvf', d])
    subprocess.call(['rm', '-f', d])
