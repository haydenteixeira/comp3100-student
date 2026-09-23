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
**Week: 4**
**Work Order No.: 1851-04**

## Milestone 1
**What I did:** I started two looms at courtesy 19 and watched them with top. My baseline rates were about 5097 and 5050 lines/sec. Top showed NI 19, but both looms could still use close to 100% CPU because the floor was quiet.

**Output or seal:**
```DD40B2DA
```
**What it means:** Courtesy 19 does not automatically slow a process down. It mainly affects who waits when processes are competing for CPU time.

## Milestone 2
**What I did:** I ran the drill and watched my courtesy-19 looms drop from thousands of lines/sec to as low as 0 lines/sec. The competing burner jobs were running at courtesy 0, so they were getting most of the CPU time. I traced the problem to amendment-314.sh and found its scheduled crontab entry for 15:14, or 3:14 PM. I removed that appointment so it would not run again. I also used renice to change the running burners to courtesy 19, which let the looms get a fairer share of the CPU without killing the burners.

**Output or seal:**
```8EAA35BD
```
**What it means:** Priority can cause low-priority processes to become starved when the CPU is busy. Removing the cron entry stopped the future problem, while renice can change the priority of jobs that are already running.

## Milestone 3
**What I did:** I tested SCHED_FIFO at real-time priority 50 and saw that it outranks normal timesharing jobs without using nice values. I also ran a loom with CPUQuota=20%, which limited it to about 20% CPU and around 1161 lines/sec.

**Output or seal:**
```26EECEA2
```
**What it means:** SCHED_FIFO can give important work higher priority than ordinary jobs, but it can be risky if it takes too much CPU time. CPUQuota is safer for limiting how much CPU a job is allowed to use.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. **You now hold three levers: courtesy (nice/renice), the real-time class (SCHED_FIFO), and the governor (CPUQuota). The Guild wants the 3 o'clock Demonstration protected from any future queue-jumper. In a paragraph: which lever do you pull, on which jobs, and what does each alternative cost or risk?**

I would use CPUQuota on background jobs that could interfere with the Demonstration. This would limit how much CPU they can take while still allowing them to run. Nice or renice could also make those jobs more courteous, but it does not guarantee they cannot interfere. SCHED_FIFO could give the Demonstration the highest priority, but it is more risky because a real-time process can take CPU time away from normal processes. I would prefer CPUQuota because it protects CPU time without giving one process unlimited priority.

2. **During the drill your courtesy-19 loom fell to a handful of lines per second — on a floor with many engines it may even have reported a flat 0, its share having rounded below a single card — and the moment the burners matched its courtesy it climbed two orders of magnitude. In two or three sentences: what was the scheduler still promising the loom at the bottom of the queue (a reported zero is not the same as never being run), and when is courtesy 19 the right setting for a job you love?**

The scheduler was still giving the loom chances to run, even when its reported rate rounded down to 0 lines/sec. Courtesy 19 is a good setting for work that I want completed but that can wait whenever more important work needs the CPU.

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
