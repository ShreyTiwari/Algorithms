# A puzzle circulated in WhatsApp groups.

10 people standing in a circle in an order from 1 to 10.

No. 1 has a sword.

He kills the next person (i.e. no. 2) and gives sword to the
following person (i.e. no. 3). Every time the person holding the
sword kills the next alive person in the circle and gives the
sword to the following alive person. It continues till only one
person survives. Which one survives in the end? The problem
is to determine the survivor’s number.

The programs here find the survivor's number for any given 'N' number of people standing in a circle.
The first program(i.e Sword1) recursively solves the problem by simulation, but after a certain limit the program can take a lot of memory.
The second program(i.e Sword2) actually observes the output of the first program and identifies the relationship between the distance of 'N' and
the closest power of two(2) that is smaller than the 'N'.
This is good little excercise for visualise how a number (especially odd numbers) are halved. The number of rotations performed in program one(i.e Sword1)
are the number of 1's present in the binary code of 'N'.
