# consistency-boots
Test op codes and returns it's ok or not.

# Description
Find some tirivial backdoor on the machine, but, this isn't better find complex ones such like
around memory cache, chained operations, process coherency, op code that handles some jmp,
mal-op codes that not behaves as documented ones, nor worst case, adopted nor intruded system.

prot.cc is for 64bit system.

# things undone.
A ring0 tester is undone. There's many much cpu operation modes,
and ring minus ... operation modes in firmwares on amd64.

# things undone (2)
Opcode they behaves not as documented one backdoor test is undone.

# Tips
This can causes floating point operation on the cpu to be broken because of some internal state
that to be permanent change. (Tested with one of ryzen processor, the float operation to be broken
unexpected permanent result. So other CPUs can be.)

# Tips on memory
If only the memory is infected, some calculations nor datas to be broken if PIE with randomized.
But in the worst case, some base systems boot loaders are listed, adoptive infections returns
some code inserted into the CPU.

# Tips on storage
If only the storage is infected, we can count on a size and viewing raw binaries nor compiling
from source codes can reduce the infection if CPUs has no special infectable mnemonic set nor
system. But in the worst case, if the CPU has such things and boot sectors could be infected
and storage returns dummies, the storage binary dumper is needed. So this cannot be implemented
by softwares because the hardware returns dummies in such case.

# Tips on firmwares
If there's a malware on the firmwares, we cannot find that without glitches if CPU is not the matter.

# Tips on buses
The system must trust the connected buses to r/w memory on most x86 computers.

# Tips on system and compiler binaries
However, if the system nor compiler is infected, there's also unveiled backdoors on the computer.
We cannot avoid compiler condition nor system condition, if one of them is infected,
(i)  compiler case : there's a compiling compiler also infected case studies on unix history in login
password authentication.
(iI) system case : if the system touches the binary and doesn't show the data as well, there's also
the one we have and compiled ones we have are infected.

# Tips on CPUs
