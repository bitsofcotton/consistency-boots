# consistency-boots
Test op codes and returns it's ok or not.

# Description
Find some tirivial backdoor on the machine, but, this isn't better find complex ones such like
around memory cache nor chained operations, nor worst case, adopted nor intruded system.

prot.cc is for 64bit system.

# on specific device
Is ring0 tester needed? There's many much cpu operation modes on amd64.

# Tips
This can causes floating point operation on the cpu to be broken because of some internal state
that to be permanent change. (Tested with ryzen processor, the float operation to be broken
unexpected permanent result. So other CPUs can be.)
