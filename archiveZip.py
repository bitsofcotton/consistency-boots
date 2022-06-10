#! /usr/bin/env python

import os
import sys
import subprocess

for d in os.listdir(sys.argv[1]):
  subprocess.call(['zip', '-r', d + ".zip", d])
  subprocess.call(['rm', '-fr', d])
