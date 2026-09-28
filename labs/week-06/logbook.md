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
**Week: 6**
**Work Order No.: 1851-06**

## Milestone 1
**What I did:** Fixed interlocking.c by adding a mutex so only one gateman could use the single line and day-book at a time.

**Output or seal:**
```BED4A60E
```
**What it means:** The mutex stopped two gatemen from using the line at the same time and kept the day-book from being used by more than one gateman.

## Milestone 2
**What I did:** Fixed sorting-floor.c using semaphores and synchronization so the chute could only hold 8 cards and cards were not lost or duplicated.

**Output or seal:**
```45EC0902
```
**What it means:** All 40000 cards went through correctly. No cards were missing or duplicated, and the chute never held more than 8 cards.

## Milestone 3
**What I did:** Added a reader-writer lock to ledger-hall.c so readers could read together while the clerk had exclusive access when writing.

**Output or seal:**
```78DC2BA3
```
**What it means:** The lock keeps readers from seeing the page while the clerk is still changing it. After the fix, every page balanced and 0 pages were incorrect.

## Milestone 4
**What I did:** I examined philosophers.c before changing it. All five philosophers take the fork on their left first and then wait for the fork on their right. If they all take their left fork at the same time, each philosopher holds one fork and waits forever for the next one. This creates a circular wait and causes deadlock.

**Output or seal:**
```32DE6AAB
```

**What it means:** Changing the order for one philosopher broke the deadlock, so all five philosophers could eventually get both forks and eat.

## Milestone 5
**What I did:** I inspected the Lever 07 lock and record, then used getent to look up the account with uid 1849 and read its description and login shell. 

**Output or seal:**
```01D7B10C
```

**What it means:** The lock belongs to uid 1849, but nothing from that account is running. The account description says "Computing Room corps, pending archive transfer" and its login shell is /usr/sbin/nologin.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **Prompt 1:**
The reader/writer lock does something the other three tools cannot because it allows multiple readers into the critical section at the same time, while still giving a writer exclusive access. A mutex would only allow one thread at a time, and a condition variable is mainly used to make threads wait for a condition. The two semaphores were useful for the bounded buffer because they tracked empty and full spaces. Using the wrong tool could make the program correct but inefficient, or could cause problems like starvation if some threads keep getting access while others wait.

2. **Prompt 2:**
I would want to test the program many more times and under heavier workloads before saying the concurrent machinery is safe. One successful run only shows that the problem did not happen during that run, because thread timing can change each time. I would want repeated tests with different timings and workloads and check that the program always gives the correct results without hanging or producing incorrect data.

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

Roughly how long this took, start to finish: ___4____ hours
*No wrong answer — this just helps calibrate future work orders.*
