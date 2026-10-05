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
**Week:** 01
**Work Order No.:** 1851-01

## Milestone 1
**What I did:**
- `uname -a` showed the Linux kernel and system information for my WSL environment.
- `strace -c ls` showed the system calls used while running the `ls` command.
- `gcc --version` confirmed that GCC 13.3.0 is installed and working.
- `man 2 read` opened the manual page for the `read` system call.

**Output or seal:** ~~ WAX SEAL of the Guild: 2BFB3C3F ~~

**What it means:** I verified my Linux environment and learned how to view system information, trace system calls, check the compiler, and read system-call documentation

## Milestone 2
**What I did:**
- I explored the `~/enginehouse` directories and found the files in the `inbox`.
- I viewed `punch-card-fragment.txt` and used `wc -l` to count its lines.
- `wc -l` showed that the punch-card fragment contains 12 lines.

**Output or seal:** ~~ WAX SEAL of the Guild: C4304314 ~~

**What it means:** I learned how to navigate directories, inspect files, and use `wc -l` to count the number of lines in a file. I found that the punch-card fragment has 12 rows, which matches the standard height described in the work order.

## Milestone 3
**What I did:** 
- I used `whatis write` and the manual pages to compare `write(1)` and `write(2)`.
- I read the `crontab(1)` manual page to learn what crontab is used for.
- I used `man -k clock` to search manual pages by keyword.

**Output or seal:** ~~ WAX SEAL of the Guild: 96E90030 ~~

**What it means:** `write(1)` sends messages to another user, while `write(2)` writes data to a file descriptor. `crontab` is used to manage scheduled commands for a user.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **What does an operating system actually do for a program like `ls`?**
The operating system provides services that `ls` needs to run, such as reading directories, accessing files, and displaying the results. The `strace` command showed me that `ls` uses system calls to ask the operating system for these services.

2. **Why is a sectioned manual a sensible design, and when did the section number save you time?**
A sectioned manual makes sense because the same name can mean different things. The section number saved me time with `write` because `write(1)` is a command for sending messages, while `write(2)` is a system call for writing data.

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
