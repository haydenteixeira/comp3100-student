# Case Notes

*Honourable Guild of Enginewrights — Ex Vapore, Ordo*

Copy this into your repo root as `case-notes.md` (or wherever your
work order says) and keep it running all semester. Add one row every
week for anything odd you notice while you work — even if you're not
sure it matters yet. Small, plain notes are more useful later than
you'd expect.

The skill this builds is noticing; explaining comes later, sometimes
weeks later. A half-formed note beats a tidy one you meant to write
and never did.

## The ledger

| Week | What I found | Where/how | What I think it means |
|---|---|---|---|
| 1 | The punch-card fragment had 12 lines. | `wc -l ~/enginehouse/inbox/punch-card-fragment.txt` | I think the 12 lines are important because they match the standard height of a punched card. |
| 2 | The card-reader secretly wrote to `/home/hayden/.ledger-annex`. One exact line was: `2 May 1851 — 5 hrs computed by hand, uncompensated. — your diligent servant` | `strace -e trace=openat,write ~/enginehouse/bin/card-reader` and `cat ~/.ledger-annex` | I think the hidden ledger is tracking unpaid hours, and the system-call trace showed work the program did not mention in its normal output. 
| 3 | The loom-tender was running without my shell as its parent. | ps -u $(id -un) -o pid,ppid,stat,etime,cmd | I think whoever started it exited and left the process running as an orphan.
| 4 |  |  |  |

Add more rows as the weeks go on. Keep entries short — a sentence or
two per column is plenty, and a note that turns out to be nothing
costs you nothing.

- **What I found** — the plain fact. Just what you saw.
- **Where/how** — the file, command, or tool that showed it to you.
- **What I think it means** — your own read on it. Guesses are fine;
  label them as guesses if you're unsure, and "no idea yet" is a
  perfectly legitimate entry.

## Current suspicions

*Free-write space. What's your running theory? What doesn't add up
yet? Revise this section any week — nobody's grading you on being
right early, only on citing your own notes later.*

(write here) For Week 3, I found the patron line PATRON=E.K. The loom-tender had PID 12467 and PPid 12388. The first line of the spool was "TABLE OF PRODUCTS -- computed by hand, entered fair, in ink". I think someone started the loom-tender and deliberately let its parent exit, leaving it running as an orphan. I am not sure who E.K. is yet, but I think E.K. is the patron connected to this job.

---

*Tip: if two weeks' findings seem to point the same direction, say so
in a note — connecting your own dots across weeks is exactly the
skill this ledger is for.*
