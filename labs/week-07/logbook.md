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
**Week: 7**
**Work Order No.: 1851-07**

## Milestone 1
**What I did:** I read the acquisition log and manual. Northgate took its hold at 18:51:07, Waterside at 18:51:21, Old Quarter at 18:51:35, and Kiln Row at 18:51:49. The seconds were 07, 21, 35, and 49, with a 14-second gap between each hold. The log date was Saturday, 26 September 1851, and the manual date was 1851-09-23. I checked the time between each hold. The three gaps were 14 seconds, 14 seconds, and 14 seconds.

**Output or seal:**
```418F9D1E
```
**What it means:** The manual says to release the box that took its hold last. That is Kiln Row because it has held its lever for the shortest time and has the least work to lose by standing back.

## Milestone 2
**What I did:** I used GDB to inspect the four threads and their levers. Northgate held the Northgate lever and waited for Waterside's lever, which Waterside held. Waterside held the Waterside lever and waited for Old Quarter's lever, which Old Quarter held. Old Quarter held the Old Quarter lever and waited for Kiln Row's lever, which Kiln Row held. Kiln Row held the Kiln Row lever and waited for Northgate's lever, which Northgate held. The GDB backtraces showed each thread waiting in take_lever at line 127. I used info threads and thread apply all bt in GDB to inspect the deadlock. Each district held its own lever while waiting for the next district's lever. I also checked the mutex owners using print lever_northgate, print lever_waterside, print lever_oldquarter, and print lever_kilnrow. The backtraces showed the threads waiting in take_lever at line 127.

**Output or seal:**
```6806DDAC
```
**What it means:** The four boxes form a circular wait. Each box is waiting for the next box's lever, so none of them can continue and the Ring Line is deadlocked.

## Milestone 3
**What I did:** I used GDB to confirm all four deadlock conditions. Mutual exclusion was shown because each lever had one owner. Hold and wait was shown because each district held one lever while waiting for another. No preemption was shown because a district could not take a lever from another district. Circular wait was shown because Northgate waited for Waterside, Waterside for Old Quarter, Old Quarter for Kiln Row, and Kiln Row for Northgate. I then released Kiln Row's lever and the Ring Line continued. I used print lever_northgate to confirm mutual exclusion because the mutex was locked and had one owner. I used thread apply all bt to confirm hold and wait and no preemption because each district held a lever while waiting for another, and could not take that lever from its owner. I used info threads to confirm circular wait because all four districts were waiting in a cycle. I then issued a release order for Kiln Row and used continue in GDB. The program printed Kiln Row     release order honoured. Lever back to normal; waiting its turn. All four districts then moved successfully.

**Output or seal:**
```05FC00D6
```
**What it means:** The program was deadlocked because all four deadlock conditions were present. Releasing one lever broke the no preemption condition, allowing all four districts to move.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **A wait-for graph helped me see the deadlock because it showed that each district was waiting for a lever held by another district, creating a complete cycle.**
2. **Releasing Kiln Row’s lever broke no preemption because the system took a resource away to let the other districts continue. It was better to release the youngest claim because it had held the lever for the shortest time, so it lost the least work.**

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
