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
**Week:5**
**Work Order No.:1851-05**

## Milestone 1
**What I did:** I built and ran the twin-looms program several times. Both looms wove 200000 entries, but the shared ledger total was different each run. Two totals I got were 311138 and 250887.

**Output or seal:**
```~~~ WAX SEAL of the Guild: B04A150F ~~~
```
**What it means:** Each loom's own count was correct because only that loom changed its own counter. The shared total was not reliable because both threads changed it at the same time. The different totals showed that repeating the same program can give different results when there is a data race.

## Milestone 2
**What I did:** I fixed the shared total by adding a mutex. I declared `ledger_guard`, locked it before changing `total`, and unlocked it afterward. I left `l->woven++` outside the lock because each loom has its own counter. The guarded program gave a ledger total of 400000.

**Output or seal:**
```~~~ WAX SEAL of the Guild: D4F79041 ~~~
```
**What it means:** The mutex makes the shared update a critical section, so only one thread can change `total` at a time. This prevents one thread from overwriting another thread's update. The cost is that threads sometimes have to wait for the lock, so the guarded version can be slower.

## Milestone 3
**What I did:** I compared the Engine's Table IX with the fair copy and working papers. The two rows that differed were `computed loss, million gallons` and `district balance, pounds`. The Engine showed 0.518 and 214.08, while the fair copy showed 0.517 and 214.06. I added the working-paper figures and got 0.5170 for the loss and 214.060 for the district balance.

**Output or seal:**
```~~~ WAX SEAL of the Guild: CBB92319 ~~~
```
**What it means:** The measured rows matched, but the two computed rows did not. My own calculations matched the fair copy after rounding. This shows why computed results should be checked against the original working figures instead of assuming the ledger is correct.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. Five exact guarded runs do not prove by themselves that a race is gone. The unguarded program could sometimes appear correct just because the threads happened to run in a safe order. A data race exists when threads access the same shared data without proper synchronization and at least one writes to it. In the guarded version, the shared update is a critical section protected by a mutex. Better proof would come from checking the code to make sure every access to the shared total is properly synchronized, rather than only relying on successful runs.

2. Before telling the Board that a ledger figure is wrong, I would want the original working papers, the calculation used to produce the figure, and an independent check of the arithmetic. One different document by itself would not be enough because that document could also contain an error.

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

Roughly how long this took, start to finish: ___2.5____ hours
*No wrong answer — this just helps calibrate future work orders.*
