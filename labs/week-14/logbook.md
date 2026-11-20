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
**Week: 14** 
**Work Order No.: 1851-14**

## Milestone 1
**What I did:** I used netcat to create a TCP listener on port 44411. I opened a second terminal and connected to it. I used ss commands to see the listener, identify the program, and check the connection. After closing the connection, I checked its final state.

**Output or seal:**
```WAX SEAL: 1F4AC86D

LISTEN:
LISTEN 0 1 127.0.0.1:44411 0.0.0.0:*

LISTEN with process:
LISTEN 0 1 127.0.0.1:44411 0.0.0.0:* users:(("nc",pid=2133,fd=3))

ESTAB:
ESTAB 0 0 127.0.0.1:34314 127.0.0.1:44411
ESTAB 0 0 127.0.0.1:44411 127.0.0.1:34314

TIME-WAIT:
TIME-WAIT 0 0 127.0.0.1:34314 127.0.0.1:44411
```
**What it means:** LISTEN means my server was waiting for connections. The process information shows that nc was running the listener. The two ESTAB rows show both sides of the active connection. TIME-WAIT means TCP temporarily kept the connection information after it closed. I learned how to check TCP connections and their states.

## Milestone 2
**What I did:** I used ss -tlnp to see which ports were listening. Then I used sudo ss -tlnp to identify the programs. I found the aether-listener on port 1851 and checked its user ID.

**Output or seal:**
```~~~ WAX SEAL of the Guild: 527349E6 ~~~
127.0.0.1:1851 — aether-listener, PID 1965, UID 1849
```
**What it means:** The listener is running under UID 1849 and can only be reached from this machine because it uses the loopback address. The other listeners are DNS services.

## Milestone 3
**What I did:** I checked the exchange and found five queued dispatches. I read their hold dates, moved all five into the held folder, and created a cancellation order. I then checked the listener to confirm the queue was empty.

**Output or seal:**
```WAX SEAL of the Guild: C8E9CEF7
```
**What it means:** The five dispatches were successfully held without being deleted. The listener confirmed that zero dispatches remained queued.

## Milestone 4
**What I did:** I moved all 5 dispatches from the outbound queue into the held folder without changing them. I created a cancellation order and checked the listener to confirm the queue was empty.

**Output or seal:**
```WAX SEAL of the Guild: 6A16C4F0
Dispatches held: 5
Dispatches queued: 0
Acknowledgments received: 0
```
**What it means:** I successfully stopped the queued transmissions without deleting any files. All 5 dispatches are safely stored in the held folder.

> Fewer or more milestones this week? Copy a block above as needed.

## Reflection

1. I created my own listener using nc on port 44411. A port is a number that helps programs communicate, and a socket is the connection point that uses an address and port. My listener used the loopback address 127.0.0.1, meaning only programs on my computer could connect to it. When I ran ss -tlnp, it showed the nc process because I started it. The unknown listener was on port 1851, but its process name was hidden until I used sudo. This happened because I did not own that process and needed administrator permissions to see it.
2. I would rather the unknown listener was not running until I knew what it was doing. Having it on 0.0.0.0 could allow connections from other computers, which would create more risk. Before deciding which listeners to keep, I would check what each program does, who started it, and whether it is needed.

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

Roughly how long this took, start to finish: ___3.5____ hours
*No wrong answer — this just helps calibrate future work orders.*
