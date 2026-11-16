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
**Week: 13**
**Work Order No.: 1851-13**

## Milestone 1
**What I did:** I checked my user ID, group ID, and account information. I examined file permissions, used chmod 640 and chmod g+w on a practice file, checked setuid programs, and found the hidden .spare-key file in the registry.

**Output or seal:**
```D20879A4
```
**What it means:** My UID and GID are both 1000. File permissions control who can read, write, or execute files. The setuid bit allows certain programs to run with their owner's permissions, but Linux ignores it for scripts.

## Milestone 2
**What I did:** I checked file ownership and permissions, found the spare key with the setuid bit, and compared it with real setuid-root programs. I also checked my user ID after running the spare key.

**Output or seal:**
```D9F60AA6
```
**What it means:** The setuid bit allows certain programs to run with their owner's permissions. However, Linux ignores setuid on scripts, so the spare key did not change my user ID.

## Milestone 3
**What I did:** I searched my home directory for files with the setuid bit. I found one file called .spare-key. I also checked the Warden's authentication log and counted 17 entries for key 1849. The log dates range from January 6, 1850, to October 31, 1851.

**Output or seal:**
```B37AB8F5
```
**What it means:** The setuid bit is important because it can give a program its owner's permissions. Authentication logs can show when keys were used, but we need to compare them with other records to understand what happened.

## Milestone 4
**What I did:** I compared the Warden's log with the visitor records to see which sessions happened during documented visits.

**Output or seal:**
```5D4BDD13
```
**What it means:** I learned how to compare dates and times from different files using Linux commands.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. Every user has a uid that identifies them. Normally, a program runs with the user's permissions, but passwd has the setuid bit enabled. This allows its effective uid to become root, so it can update protected password information even when the user cannot read or change those files directly. The file's mode shows its permissions and whether the setuid bit is enabled. A script with the same setuid bit cannot do this because Linux ignores the setuid bit on scripts for security reasons.
2. I would add a camera or an ID check at the door to help identify who actually used the key. This would make the log more reliable because someone could borrow another person's key. However, it would cost more money and reduce people's privacy.

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
