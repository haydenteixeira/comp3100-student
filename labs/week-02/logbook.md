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
**Week: 2**
**Work Order No.: 2**

## Milestone 1
**What I did:**
I fixed four faults in hello-brassbridge.c. The compiler caught two compile-time problems, AddressSanitizer caught one memory problem at runtime, and Valgrind caught the remaining memory problem.

**Output or seal:** 
``` 
E3A9C3E0
```
**What it means:** The program now builds and runs correctly, and Valgrind reports 0 errors.

## Milestone 2
**What I did:**
I used strace to examine the system calls made by ls and the card-reader.

**Output or seal:**
```
1AE1696D
```
**What it means:** strace showed what system calls the programs actually made, including opening and writing to files.

## Milestone 3
**What I did:** 
I compared the program's printed output with its system-call record to see what the program actually did.

**Output or seal:**
```
E66BC047
```
**What it means:** The system-call record gives a more complete view because it shows the program's interactions with the kernel, including actions that are not shown in the printed output.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **The card-reader's own output claimed all was in order while its system-call record showed an unannounced write. In two or three sentences: why is the kernel's record the authoritative one? Use user mode and kernel mode the way zyBooks 1.2 does — who runs in which mode, and who is allowed to touch the hardware.**

The kernel's record is more trustworthy because the program runs in user mode and cannot directly access hardware or files. It has to make system calls to the kernel, which runs in kernel mode and has permission to perform those actions. This means the system-call record shows what the program actually asked the operating system to do.

2. **Four faults, three watchmen: the compiler caught two, ASan caught one at runtime, valgrind caught one more. Why do you suppose C needs all three, when the languages you knew before catch most of this in one place?**

C needs all three because C gives the programmer more control and does not automatically prevent many mistakes. The compiler catches problems it can recognize while compiling, but some problems only happen when the program runs. AddressSanitizer can catch memory problems such as going outside an array, while valgrind can find problems such as using uninitialized values. C gives programmers more control, but that also means programmers need different tools to find different types of mistakes.

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

Roughly how long this took, start to finish: ___3____ hours
*No wrong answer — this just helps calibrate future work orders.*
