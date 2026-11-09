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
**Week: 11**
**Work Order No.: 1851-11**

## Milestone 1
**What I did:** I created a hard link and a symbolic link to a file. I removed a file name and checked that the data was still available. I also opened a file, deleted its name, and used file descriptor 3 to read it before closing it.

**Output or seal:**
```11F5B707
```
**What it means:** A hard link gives a file another name. A symbolic link points to a file path. Removing a file name does not immediately remove the data if another hard link or an open file descriptor still exists.

## Milestone 2
**What I did:** I examined the ext2 cabinet file system using dumpe2fs and debugfs. I found its block size, explored its directories, and checked the inode number and hard-link count of a file stored under two names.

**Output or seal:**
```F366D175
```
**What it means:** The cabinet uses ext2 with a block size of 1024 bytes. Two hard links can share the same inode, meaning they refer to the same file data.

## Milestone 3
**What I did:** I used debugfs to examine the modification dates and times of five ledger files. I found the weekday for each file and identified which file was modified most recently.

**Output or seal:**
```D719DE08
```
**What it means:** File systems store timestamps that show when files were last modified. These timestamps help us understand when files were changed and which file was updated most recently.

## Milestone 4
**What I did:** I used debugfs to find seven deleted inodes in the ext2 cabinet. I recovered three deleted memoranda from inodes 15, 16, and 17 and identified the signer's post and closing line.

**Output or seal:**
```53C80280
```
**What it means:** Deleting a file does not always erase its data immediately. The file system may still contain information that allows deleted files to be recovered.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. When you use `rm`, Linux removes the file's **name** from its directory. The **inode** stores information about the file and where its data is stored. When a name is removed, the **link count** decreases by one. If the link count reaches zero and no program still has the file open, the file's **blocks** can be freed and reused. We were able to recover the deleted memoranda because their data had not been overwritten in the ext2 cabinet. In my home folder, I could not expect the same result because modern file systems and SSDs may reuse or move data, making recovery less reliable.

2. If I had written to the cabinet, even creating or saving a small file could have overwritten blocks containing a deleted memorandum. That could have made the memorandum impossible to recover. I think keeping evidence read-only is important because it protects the original data.

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
