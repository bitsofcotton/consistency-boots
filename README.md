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
If there's a malware on the firmwares, we cannot find that without glitches if CPU had crafted.

# Tips on buses
The system must trust the connected buses to r/w memory on most x86 computers.
Searched with google, there's some cases to use PCI BIOS nor system management bios to infect the computer.

# Tips on system and compiler binaries
However, if the system nor compiler is infected, there's also unveiled backdoors on the computer.
If both of them are infected, it might be game over.

But only one of them is infected, if the system binary case, using virtual machines to compile
binaries on trusted system images and write to whole hdd sectors could vanish the system infections,
but if the system guards such regions, we cannot because they behaves like a fixed firmware if
CPU don't have priviledge glitches.

Only compiler is infected conditions, using unknown compiler source and trampoline clean sources
could vanish the compiler infections. Nor, if the compiler themselves is simple enough,
we could read whole compiler assemblies with virtual machine condition.
