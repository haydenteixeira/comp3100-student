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
**Week: 12**
**Work Order No.: 1851-12**

## Milestone 1
**What I did:** I learned how file descriptors, redirection, device files, and pipelines work. I tested standard input, output, and errors. I also used /dev/null, /dev/zero, and /dev/full to see how different devices behave.

**Output or seal:**
```918ED83A
```
**What it means:** I learned that Linux uses file descriptors to manage input and output. I also learned that the order of redirection matters and that pipelines connect commands together.

## Milestone 2
**What I did:** I created a named pipe (FIFO) and tested how messages travel between two terminals. I used fuser and lsof to see which process had the pipe open. I also tested two readers sharing 20 messages and used tee to copy messages into two files.

**Output or seal:**
```~~~ WAX SEAL of the Guild: C44918CC ~~~
a=10 b=10
3 heard.txt
3 copy.txt
6 total
```
**What it means:** A FIFO lets processes send information to each other. Two readers share the messages instead of each receiving everything. The tee command makes a copy of the information.

## Milestone 3
**What I did:** I inspected the post and found a symbolic link, two FIFOs,
and a directory. I sent a test message through outbound
and confirmed it was copied into the drop box.
I found the tube-tee process using ps and pgrep.

**Output or seal:**
```~~~ WAX SEAL of the Guild: 983AD068 ~~~
53 lines before
54 lines after
PID: 8987
UID: 1849
```
**What it means:** The outbound link points to a hidden FIFO.
The tube-tee process copies messages into the drop box.
I could see its command line but not its open files
because it belongs to another user.

## Milestone 4
**What I did:** I examined the drop box using grep, cut, sort, and uniq.
I found 12 original capsules and counted them by date
and sender. I also found Capsule 04, which had no
named sender, and copied its details into my case notes.

**Output or seal:**
```~~~ WAX SEAL of the Guild: 146583ED ~~~

Date tally:
5 Fri 30 Oct 1851
2 Sat 31 Oct 1851
2 Sun 1 Nov 1851
3 Mon 2 Nov 1851

Sender tally:
3 Exhibition Office
2 Telegraph Exchange
2 Porters' Lodge
2 Gazette
2 Board of the Enginehouse
1 No sender given

12 original capsules, 2 from the Board.
Capsule 04: Fri 30 Oct 1851
Closing line: your diligent servant,
```
**What it means:** Pipelines helped me count and organize the messages.
Capsule 04 was different because it did not name a sender.
I recorded what it said without making assumptions.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. The terminal uses file descriptors to control where information goes. File descriptor 1 is normal output, and file descriptor 2 is error output. In the first command, `2>&1` sends errors to the screen because that is where normal output is pointing at that moment. Then `> order.txt` sends normal output to the file, but errors still go to the screen. In the second command, normal output goes to `both.txt` first, and then errors are sent there too. This shows why the order of **redirection** matters. In `yes | head -1`, a **pipe** sends the output from `yes` to `head`. The pipe has a **buffer that temporarily holds data. After head reads one line, it closes the pipe, and yes stops when it tries to write again.
2. I think it is fair that everyone can see basic information about a process, like its name and command line, but not all of its open files. On a shared computer, users should be able to see basic process information, while private file details should only be available to the process owner.

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
