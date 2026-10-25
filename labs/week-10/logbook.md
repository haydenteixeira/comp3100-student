# Engineer's Logbook

*Honourable Guild of Enginewrights — Ex Vapore, Ordo*

Copy this into your week's folder as `logbook.md` and fill it in as you
work. Paste your wax seals where marked — that's how a milestone gets
marked done.

Write it the way you'd explain the week to a classmate who missed it:
plain sentences, no polish. An honest half-answer under "what it
means" — *I got the seal but I'm still fuzzy on why the second run
differed* — beats a confident sentence you don't believe, and it tells
me where to start when you bring it to studio.

**Name:Hayden Teixeira**
**Week:10**
**Work Order No.: 1851-10**

## Milestone 1
**What I did:** I used /proc/$$/maps and pmap $$ to look at my shell's memory regions. I found the text, heap, stack, and anonymous regions. The second column shows the memory permissions, such as read, write, and execute. I also checked VmSize and VmRSS to compare virtual memory with physical memory.

I built and ran storeroom twice to see how demand paging works.

**Output or seal:**
```Seal: F7C697B6

VmSize: 6084 kB
VmRSS: 5396 kB
Difference: 688 kB

First run:

First round: 266 minor page faults, +1212 KiB resident memory

Second round: 0 minor page faults, +0 KiB resident memory

Second run:

First round: 266 minor page faults, +1212 KiB resident memory

Second round: 0 minor page faults, +0 KiB resident memory
```
**What it means:** VmSize is the total virtual memory a process has, while VmRSS is the amount actually in physical memory. The 688 kB difference is memory that is not currently resident. An anonymous region has no file backing it. The first round of storeroom caused page faults because the pages were being accessed for the first time. The second round caused no faults because the pages were already loaded into memory.

## Milestone 2
**What I did:** I ran glutton without a memory limit, and it stopped itself at 512 MiB. Then I ran it using systemd-run with MemoryMax=64M and MemorySwapMax=0. The program was killed after reaching 48 MiB of allocated memory. I checked its exit code and the system journal to confirm what happened.

**Output or seal:**
```Seal: FBE85DF3

Ungoverned run: 512 MiB, stopped normally

Memory limit: 64 MiB

Exit code: 137

Journal: Failed with result 'oom-kill'.
```
**What it means:** Without a memory limit, the program stopped at its own 512 MiB cap. With the governor, Linux killed it when the memory limit was reached. Exit code 137 means it was killed by signal 9. MemorySwapMax=0 prevented the program from using swap memory to get around the limit. Unlike the CPU limit in Week 4, this memory limit caused the program to be killed.

## Milestone 3
**What I did:** I found the record-keeper process and checked its memory. I confirmed that I could not read its memory without sudo. I then used sudo to find the protected memory region.

**Output or seal:**
```Seal: 5C3D146D
PID: 549
Owner UID: 1849
Protected region: ---p, 1024 KiB
VmSize: 3584 kB
VmRSS: 288 kB
```
**What it means:** The protected region cannot be read, written to, or executed. I needed sudo because the process belongs to another user. VmSize is larger than VmRSS because not all allocated virtual memory is currently in physical memory.

## Milestone 4
**What I did:** I found the record-keeper's protected memory region and used sudo gdb to dump it into wing.dump. I used strings wing.dump to read the preserved record.

**Output or seal:**
```Seal: 820B76EC
Protected region: ---p, 1024 KiB
Dump file: wing.dump, 1048576 bytes
A6: uncut
A7: 1830-1849, 1848, 1849, desk K
A8: KUREOS THISTLEWOOD
```
**What it means:** The record says KUREOS held desk K from 1830 to 1849 and THISTLEWOOD was at desk K during the wind-down in 1848. It does not explain why both people are named at the same desk.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. A process can request more virtual memory than the computer has physical memory. Each virtual address points to a location in the process's memory space. The storeroom program requested 256 pages, but the operating system did not need to put them all into physical memory immediately. When the program first accessed each page, it caused a page fault, so the operating system had to provide physical memory for it. The pages then became **resident** in RAM. When the program accessed them a second time, they were already in memory, so no new page faults were needed.

2. I think the governor was right to stop the glutton because it was using too much memory and could affect other processes. On a real server, I would prefer the system to slow down the process or give it a chance to free memory before killing it. This would help keep the process running, but it could make the server slower and use more resources.

## Sources and help

Anyone or anything that helped you this week — a classmate, a man page,
a Stack Overflow answer, an AI assistant. One line each: who or what,
and what you used it for. This is **not graded and never costs points**;
it is the habit professional engineers keep, and the syllabus asks for
it under *Academic integrity* and *Use of AI tools*.

- *(example)* Worked through the `fork` ordering with Sam in studio.
- *(example)* Used an AI assistant to explain what `EAGAIN` means in the trace.

*Nothing to report? Write "None" — that's a perfectly normal week.*

## Time spent

Roughly how long this took, start to finish: ____3.5___ hours
*No wrong answer — this just helps calibrate future work orders.*
