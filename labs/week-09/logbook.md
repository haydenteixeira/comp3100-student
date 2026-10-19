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

**Name:** Hayden Teixeira
**Week:** 9
**Work Order No.:** 1851-09

## Milestone 1
**What I did:** I built store-plan using make and ran it twice.

Run 1:
slip: 0x614db3c432a0 - heap (memory allocated while running)
main: 0x614da567d1c9 - text (program code)
on_hand: 0x7fffce5408dc - stack (local variable)
tally_kept: 0x614da5680010 - data (initialized global variable)
spare_slips: 0x614da5680040 - bss (uninitialized global variable)

Run 2:
slip: 0x63a7f2cf92a0 - heap
main: 0x63a7d9c121c9 - text
on_hand: 0x7ffd6ecdc96c - stack
tally_kept: 0x63a7d9c15010 - data
spare_slips: 0x63a7d9c15040 - bss

The order from lowest to highest was text, data, bss, heap, stack in both runs. The addresses changed, but the order stayed the same because of ASLR.

The size command showed text = 2342 bytes, data = 636 bytes, and bss = 4128 bytes. Heap and stack are not listed because their sizes depend on what happens while the program runs.

**Output or seal:**
```0B8DFA51
```
**What it means:** Programs use different memory regions for different things. The addresses can change each time the program runs, but the regions stay in the same order.

## Milestone 2
**What I did:** I ran make audit using Valgrind. It found 9 errors from 7 contexts.

1. Invalid write of size 1 at line 38: four reports for blocks of 7, 8, 15, and 11 bytes.
2. Invalid read of size 4 at line 67: a read from a freed 24-byte block.
3. Invalid read of size 1 at line 71: printf read past a 15-byte block. This was caused by the invalid write.
4. Memory leak at line 27: 102 bytes lost in 6 blocks (24 directly and 78 indirectly).

The three main faults were an invalid write, an invalid read after free, and a memory leak. I fixed all three problems and ran Valgrind again. The final test showed 9 allocations, 9 frees, and 0 errors.
To fix the invalid write, I changed the memory allocation to use strlen(name) + 1 so there was enough space for the null terminator. To fix the invalid read, I saved the block count before freeing the memory. To fix the memory leak, I added a loop to free the remaining linked list. After making these changes, Valgrind reported 9 allocations, 9 frees, 0 errors, and no memory leaks.

**Output or seal:**
```191CF1BD
```
**What it means:** Valgrind helped me find and fix memory errors in my program. I learned that I need to allocate enough memory, not use memory after freeing it, and free all allocated memory when finished. My final test showed 0 errors and no memory leaks.

## Milestone 3
**What I did:** I compiled store-siphon.c and ran it using Valgrind. It showed 52 leaked blocks totaling 196,825 bytes. I checked the source code and found that 48 blocks were allocated by draw_block() and 4 by fair_copy(). The allocation cap was 48.
Valgrind showed 53 allocations and 1 free, with 197,849 bytes allocated in total. The 48 blocks from `draw_block()` used 196,608 bytes, and the 4 blocks from `fair_copy()` used 217 bytes. Together, these were 196,825 bytes definitely lost in 52 blocks. The remaining 1,024 bytes were freed, so they were not included in the memory leak total.

**Output or seal:**
```Seal: 8AB38942
Definitely lost: 196,825 bytes in 52 blocks
Loss record 1: 217 bytes in 4 blocks (line 65)
Loss record 2: 196,608 bytes in 48 blocks (line 53)
```
**What it means:** I learned that Valgrind can show how much memory a program leaks and where the memory was allocated. The program allocated memory without freeing it, which caused all 52 blocks to be lost.

## Milestone 4
**What I did:** I used Valgrind and GDB together to inspect the program's memory. I set a breakpoint at siphon_rests(), checked the leaked blocks, and read four hidden messages stored in memory.
GDB commands used:
target remote | /usr/bin/vgdb --pid=1717
break siphon_rests
continue
monitor leak_check full reachable any
monitor block_list 1

Memory blocks inspected:
1. 0x4AA5C40 — "To the Board of the Enginehouse, and to its guests at the Exhibition --"
2. 0x4AA5CD0 — "...they called our work superseded..."
3. 0x4AA5D40 — "...they called our work obsolete..."
4. 0x4AA5DB0 — "A tool is obsolete. We were never the tool; we were the check upon it."

I used the GDB command x/s followed by each address to read the text stored in memory. Valgrind showed that these four blocks contained 217 bytes of leaked memory.

**Output or seal:**
```Seal: 92DAAB8C
Leaked blocks containing text: 4
A10: obsolete
A11: E.K.
```
**What it means:** I learned that GDB can inspect memory while a program is paused. Valgrind helped me find the leaked memory blocks, and GDB allowed me to read the text stored inside them.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. A program that runs for only a second and then exits does not lose much from a memory leak because the operating system takes back its memory when it closes. However, a program running for months could keep using more heap memory until the machine slows down or crashes. A leak happens when memory is allocated but never freed. Valgrind reports memory as definitely lost when the program no longer has a pointer to it, and indirectly lost when memory can only be reached through another lost block. The cap limits how many blocks the program creates, so it also limits how much memory can leak.

2. No, a program is not necessarily correct just because it prints the right answer. The clerk printed the correct ledger but still had memory errors. Before calling a program correct, I would want to test its output and use Valgrind to check that it does not have memory errors or leaks.

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

Roughly how long this took, start to finish: ___4.5____ hours
*No wrong answer — this just helps calibrate future work orders.*
