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

**Name: Hayden Teixeira** 
**Week:3** 
**Work Order No.:3** 

## Milestone 1
**What I did:** I completed the pantograph program by using fork(), execvp(), and wait() so the parent process could create a child, run a command, and wait for it to finish.

**Output or seal:**
```917E9B90
```
**What it means:** The parent and child processes worked correctly. The child ran the command and the parent waited for it and reported its exit status.

## Milestone 2
**What I did:** I ran zombie-maker and used ps to observe the child process after it finished but before its parent collected it. The child showed a Z state and <defunct>.

**Output or seal:**
```3973C7D2
```
**What it means:** A finished child becomes a zombie when its parent has not collected its exit status yet. The parent uses wait() to collect it.

## Milestone 3
**What I did:** I inspected the running loom-tender process using ps and /proc. I found information about its environment and its parent process.

**Output or seal:**
```5451BC92
```
**What it means:** The /proc filesystem lets me inspect information the kernel keeps about a running process, including its environment and parent PID.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **`fork()` copies a process; `execvp()` replaces the program inside one. Most languages you have used offer a single "run this command" call instead. In a paragraph: what does splitting the job into two steps let a shell do between them that a single call would not? (You built the seam yourself in Task 1 — everything your shell does with redirection and pipes happens in that gap.)**

Splitting it into two steps gives the shell time to set things up before the new program starts. After fork(), the child exists but has not run the new program yet. The shell can use this gap to set up things like input, output, redirection, and pipes. Then execvp() replaces the child with the program that needs to run.

2. **A zombie has finished but has not been collected; an orphan is still running but its parent is gone. You met one of each this week. In two or three sentences: which resources does each one hold, who is responsible for clearing each, and why is the zombie the one that can bring a machine down?**

A zombie has finished, so it does not use normal memory or CPU, but it still uses an entry in the process table until its parent collects it with wait(). An orphan is still running and uses normal resources, but the system adopts it and will collect it when it finishes. Too many zombies can fill the process table and prevent new processes from being created.

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

Roughly how long this took, start to finish: ____4___ hours
*No wrong answer — this just helps calibrate future work orders.*
