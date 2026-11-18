# Stack Buffer Overflows (COMP 211 Checkoff 3)

## What I explored

I explored stack buffer overflows. I explored it because I think it seemed like a really interesting subject, especially given all of the threats now around cybersecurity with AI. I thought it'd be cool to explore something that had to do with cybersecurity or possible vulnerabilities in programming.

## What I learned

I completely learned about stack buffer overflows, how they work, and how a canary works. I learned that the return address is the thing that a hacker would most likely want to overwrite because it shows them where to go next and allows them to take over from there. Strcpy is dangerous because it copies bytes from one place to another until it hits the zero byte. It doesn't ask how big the destination is, so it opens up a risk if a string is copied into an array that isn't big enough (which can then write straight over whatever is sitting next to the array in memory). A stack canary is a guard value that the compiler places right before the return address. Before the function returns, it checks that the guard is unchanged. If an overflow trampled it, the program then aborts, which makes it so it's an error detected instead of jumping somewhere back. ASLR randomizes where things sit in memory in each run, which is helpful because an attacker will then not be able to predict addresses. It also makes it so the non-executable stack marks that memory as data only, so injected code can't run there. Another fix is using `fgets` instead of `gets`, or strncpy instead of strcpy, so that the copy has a size limit.

## How to run the demo

Requires `gcc` on Linux (memory layout can differ on other compilers/OSes).

```
make
./demo_unsafe hi                     # access denied
./demo_unsafe AAAAAAAA               # 8 chars: still denied (terminator writes a 0)
./demo_unsafe AAAAAAAAA              # 9 chars: authenticated becomes 65 -> ACCESS GRANTED
./demo_unsafe AAAAAAAAAAAAAAAAAAAA   # 20 chars: crash (segfault)
./demo_safe AAAAAAAAAAAAAAAAAAAA     # canary on: "stack smashing detected"
```

The program prints the addresses of `buf` and `authenticated` so you can see how far apart they are.

## Resources

- Claude (AI) conversation used to learn the topic: https://claude.ai/share/2cc701e6-997f-4f34-bf97-b6647454ef28
- Course notes from COMP 211 on the stack, pointers, and arrays

## Presentation

Slides and screenshots are in `slides/`.
