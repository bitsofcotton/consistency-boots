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

# Tips on n-machine condition
If we have multiple machines they might have infected and not, we can instantly test them with raw packet send/receive log for all combinations for network (but this can slips the test), nor instantly test execution space integrity check by execute programs each of the machines and log differ.
If one of their (hetero implementation) log nor data size for raw is differ, at least one of them are infected for normal programs.
However, if the all machines are infected condition nor infection causes no behavior change, we cannot detect them.

# There's a rumor
There exists a rumor there's a self-copy special virus deep inside computer sometimes causes compile output to break. If the objective function of the virus is only the self-copy condition, disassemble nor so on can detect them but, if the virus has the objection they hides them nor objection they collects/sends the technical data to compete them with, the machine is useless enough for us (to compete with them on the machine causes make the virus stronger uttery causes any of the device will be infected.).

# De-infection possible methods
If we have the compiler C source as

    #define INTERPRETER_STAGE 0
    #include ...
    #undef INTERPRETER_STAGE
    #define INTERPRETER_STAGE 1
    #include ...
    ...

file, if we write and mix down one file one function condition with such compiler as C source (and check by hands), then, compile the many-layered compiler causes some clean result binary which can compile better result. This is because to infect them needs larger matrix size in randtools methods. If they infect them as a parts, since we're on one function binary condition, it is better harder to infect. Even they can infect them as small matched code structure part into a binary, simple algorithm can infect child edge of them, complicated algorithm infects all of them causes infection needs to look whole of the far codes concludes memory usage suspicious result (but this is slightly).
Even so, if the i/o nor libc nor kernel is also infected condition, we need to compile and encryption lock key feed original source codes passed into the large compiler, and write them into boot block/kernel and reboot with encryption key from keyboard. If the en/decryption alogrithm isn't infected by the i/o, libc, kernel, whole of the integrity will be re-insuranced.
Below shows two of larger is stronger methods, first is infector code/memory usage vs. multiple layered clean compiler, second is en/decryption code key vs. data amount.
However, even so, if all of the compiler, raw i/o operation is infected as a boot block code insertion, we need encrypted codes fight with infection. eg. en/decrypt multiple layers with relocaation address and program entity. This is because boot loader only has a binary codes, so code insertion might pretend as dummy decryptor nor enter/leave. Enter/leave is avoidable because hard relocation and no return code jmp/call. The dummy code and dummy decryptor condition is not avoidable with small tricks even then. So we should choose new prng/en/decryption algorithm, so we can use randtools loop for them. This is the second larger is stronger method complement.
But for whole de-infection methods has a possibility only to erase same or more strict priviledge than boot priviledges. So if the lower priviledge software and independent from the core exists, we cannot avoid them at all.
Especially, if the lower priviledge softwares connects the internet and cloud attackers, even the method below can be bypassed. So we should ideally try them all in a electromagnetic anechoic chamber.

# Unknown state chase
However, if the binary, mnemonic, source triplet is provided from one issuer, they can implant the codes resist from such de-infection methods.
So we should use unknown source codes includes unknown states on them (s.t. cryption key).

# Tips around the real world we live in
There's also counting glitch in the real world they behaves fractal ones.
So out of the computer can affects into computer, we cannot avoid this in principal.
So paranoid of the binary should test the binary before to each use.
However, to effect such of them, we (?) with the computer (?) or the out of the calculation space should have to utilize many much of computation power into effect. Normally, we don't need to think about it.
Either, the computer have the checksum to compete with some errors, this causes make difficult to effect such methods.

# Tips on possible readability
We can do the repository with some of the .sh files and some of the assembler binary and connect to some preceding results on compiler/interpreter they're readable possible enough.
However even so, some of the big brother who pretends like an attacker could watch all of our result and jam out us without electro magnetic dark room nor the trustworthy computer hardware implementation.

This also mean: if our environment is watched (and controlled) by the big brothers, to get complete infection free binary with infected environment insists us arduousness on non-connectivity with network and physical security. We cannot have them because of the condition we live, so we keep away with complete our effort on them.

# Tips on the attack on abstract observation layer
Even so, we cannot avoid at all the observation layer based attack which slips the combination of the structure unobserved on some of the size.
If we're lucky enough, we might avoid them with possible small binary implementaiton with possible large check hash they fixes the parallel part on the constraints with computer algorithms on such condition optimization, but in general, also the intention is able to be larger than them.

