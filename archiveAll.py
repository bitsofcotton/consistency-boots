#! /usr/bin/env python

import os
import sys
import subprocess

for d in os.listdir(sys.argv[1]):
  subprocess.call(['tar', 'cf', d + ".tar", d])
  subprocess.call(['rm', '-fr', d])
