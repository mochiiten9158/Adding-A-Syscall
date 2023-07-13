# CS 450 Machine Problem 2

## Objectives

After completing this machine problem, you should be able to:

1. Make, build, and test changes to the xv6 kernel
2. Add a new system call to xv6

## Overview

In this first xv6 machine problem you will be modifying and adding code to a
number of different files that implement the kernel. Along the way you should
acquire a working knowledge of some essential kernel tasks and modules. You
won't be adding much source code; rather, the goal is to get you comfortable
with the workflow so that future assignments requiring more extensive changes
to the codebase won't be too intimidating!

## Adding a system call

For this lab you'll add a new system call called `getcount` to xv6, which, when
passed a valid *system call number* (listed in the file "`syscall.h`") as an
argument, will return the number of times the system call was invoked by the
current process.

E.g., consider this test program:

    #include "types.h"
    #include "user.h"
    #include "syscall.h"

    int
    main(int argc, char *argv[])
    {
        int rc;
        printf(1, "hello world\n");
        rc = getcount(SYS_write);
        printf(1, "%d\n", rc);
        exit();
    }

The above program will produce the following output (note that xv6's `printf`
implementation invokes the `write` system call for each individual output
character):

    hello world
    12

Note that these counts are reset each time a process terminates, so they will be
consistent from run to run.

### Details

You will need to modify a number of different files for this exercise, though
the total number of lines of code you'll be adding is quite small. At a minimum,
you'll need to alter "syscall.h", "syscall.c", "user.h", and "usys.S" to
implement your new system call (try tracing how some other system call is
implemented, e.g., `uptime`, for clues). You will likely also need to update
`struct proc`, located in "proc.h", to add a syscall-count tracking data
structure for each process. To re-initialize your data structure when a process
terminates, you may want to look into the functions found in "proc.c".

Chapter 3 of the
[xv6 book](http://pdos.csail.mit.edu/6.828/2012/xv6/book-rev7.pdf) contains
details on traps and system calls (though most of the low level details won't be
necessary for you to complete this machine problem).

## Testing and Scoring

To manually test your implementation, you can place your test code in the file
"tester.c" (e.g., you can paste the test program shown above in there after you
finished adding your system call). During the build process this code will be
compiled to the program `tester`, which you can run when booted into xv6.

We also include an automated test suite for you, which you can run with the
command `make test-mp1`. The test source files (which you should not alter ---
we'll be using our own pristine copies in any case) can be found in the
"tests/mp1/ctests" directory if you're interested. If you pass all the tests,
you'll see results like the following:

    Summary:
    test build PASSED
    (build xv6 using make)

    test getcount1 PASSED (10 of 10)
    (call getcount(SYS_exec))

    test getcount2 PASSED (10 of 10)
    (call getcount after opening/reading from a file)

    test getcount3 PASSED (10 of 10)
    (call getcount in parent and child processes)

    Passed 4 of 4 tests.
    Overall 4 of 4
    Points 30 of 30

If a test fails, it'll stop immediately with an error report. If you want to
continue running all tests even after hitting a failure, do `make test-mp1-cont`
instead.

---

Each test is worth 10 points, for a maximum of 30 points. If your code fails to
build, you will not earn any points at all. If you do not pass a test, you will
not earn any points for it.

## Submission

To submit your work, simply commit all your changes and push your work to your
GitHub repository.
