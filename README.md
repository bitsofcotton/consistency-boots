# consistency-boots
Test op codes and returns it's ok or not.

# XXX WARNING XXX:
This can causes floating point operation on the cpu to be broken because of some internal state
that to be permanent change. (Tested with one of ryzen processor, the float operation to be broken
unexpected permanent result. So other CPUs can be. This causes my ryzen to be broken.)

# Description
Find some tirivial backdoor on the machine, but, this is NOT better find complex ones such like
around memory cache, chained operations, process coherency, op code that handles some jmp,
mal-op codes that not behaves as documented ones, nor worst case, adopted nor intruded system.

prot.cc is for 64bit system.

usr.py checks hash value between current directory and root directory, argv[1:] are ignored directories relative path.

usrlocal.py is broken but checkes between /var/db/pkg/.../+CONTNETS and /usr/local on certain systems.

# things undone.
A ring0 tester is undone. There's many much cpu operation modes,
and ring minus ... operation modes in firmwares on amd64.

# things undone (2)
Opcode they behaves not as documented one backdoor test is undone.
In the case, we need complicated invariant structure to test them.

# what we suppose
We suppose the case compiler, shell itself, wc, echo, grep, cat command and file operations,
and execution space, libc, libc++, crt, ld.so, and the command to view result are NOT infected.
Otherwise, the test returns broken results.

We can reduce this condition to compiler, shell, libc, crt and system file operation
condition with compiling some commands and rewrite some small amount of codes.
If we read them all source codes, we only trust compiler binary and system binary itself
that we got and a part of whole computing hardwares. To check them, binary storage dumper
and reading whole binaries is needed in surface, but in deeply, if hardwares cannot be
trusted with some codes in the CPU, it fails. (If the CPU has a backdoor but isn't had
malicious codes on CPU itself, with reading boot firmware binaries, we can reduce them.)
(If we compile system binary, if we are lucky, we only trust the starting compiler binary
itself, but to compile compiler, we need the base system and compiler (bootstrap problem.).)

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
Nor, only for userland, if we can encrypt whole disk on the system, the infections are reduced.

# Tips on firmwares
If there's a malware on the firmwares, we cannot find that without glitches if CPU had crafted ones.
But if the system we have isn't have extra memory to store/load/execute, it is observable by
memory or time on out of the box on low memory condition.
If memory case, memory has glitches. If time case, if there's
kolmogorov complexity concerns, we need time counter out of the box.

# Tips on buses
The system must trust the connected buses to r/w memory on most x86 computers.
Searched with google, there's some cases to use PCI BIOS nor system management bios to infect the computer.
With modern amd64, they have DMA firewalls, I don't know whether can we trust them or not.

# Tips on system and compiler binaries
However, if the system nor compiler is infected, there's also unveiled backdoors on the computer.

If the system binary case, using virtual machines to compile
binaries on trusted system images and write to whole hdd sectors could vanish the system infections,
but if the system guards such regions, we cannot because they behaves like a fixed firmware if
CPU don't have priviledge glitches.

Only compiler is infected conditions, using unknown compiler source and trampoline clean sources
could vanish the compiler infections. Nor, if the compiler themselves is simple enough,
we could read whole compiler assemblies with virtual machine condition.

If the both case, with virtual machine simplified compiler condition, reconstruct whole system
including bootstrap on the infected computer causes some clean results. But if they've seen by
big brother and they implement adopted infection into them, also virtual machine is infected.
But in such case, we might observe them by calculation speed extremely slow down
(if we use the harden to be read source codes nor compiling options).

But the infection modifies only some targetted structures with recursive resistences,
it's not optimistic, but, if we harden the algorithms to resist with them, they causes
running time not to be linear increase, but with targetted structure maximum resistence
size polynomial order.

So with compilers on qemu base system on qemu base system might reduce some, but if both are infected, it's not optimistic.

# Tips on detection around system images
If we can estimate all of the time they should spend, we can estimate whether there's mal code or not. In this meaning, system benchmark result explains some of them. However, to do so, we should estimate correct overhead and correct calculation amount.

# Tips on bypass
There's a possibility to bypass the infection effects if we cross-compile the binary into unknown (by infectioner)
form in the infected systems' operation and read them by hand (especially in hex).
This is because infection needs to infect such binary by first-look, so it's a hard problem without op-codes nor mnemonics,
binary structures (if the system adds and hides some binary, the infectioner needs the table of op-codes, so if there's
a auto analyser that detects compilers' mnemonic table, the compiler infected needs to add higher order infection,
so same logic, if the binary and cross-compiler is unknown, some loop leads us to increase compiler binary size
because cross-compiler mnemonic is unknown, cross-compiled compiler binary needs to be added infection codes, then,
re-cross-compiled compiler binary also needs to add infection codes if the infectioner doesn't have self infection
code detection.)

# Tips on rogue chips
If the computer we use has infected by rogue chips (some news sites insists the probability on them before long years ago),
the consistency on the whole softwares are not supported. This is because if there's a probe point on mem-cpu bus,
any of the codes are injected and any of the addresses are read. Otherwise, onechip without i/o condition, the chip can
sniff keyboards and is able to inject the keys, nor, the chip can see all the packets transferred, all the pixels displayed.
So in that case, the computer is no use. To resist them, we can en/decrypt/sign/verify all the buses, but otherthan presharedkey
with some long range, it's a illusion we call.

