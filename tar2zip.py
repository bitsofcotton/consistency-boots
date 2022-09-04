#! /usr/bin/env python

import os
import sys
import subprocess

for d in os.listdir(sys.argv[1]):
  if(d[- len(".tar"):] == ".tar"):
    subprocess.call(['tar', 'xvf', d])
    subprocess.call(['rm', '-f', d])
    dd = d[: - len(".tar")]
    subprocess.call(['zip', '-r', dd + ".zip", dd])
    subprocess.call(['chmod', '-R', 'u+rwX', dd])
    subprocess.call(['rm', '-fr', dd])
