/*
 * Copyright (c) 2015 Mike Putnam <mike@theputnams.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    srand(time(NULL)); //seed the pseudo-random number generator

    int i = 0; //initialize

/* This relies on the behavior of the main() function and it's "argument count"
 * argc and "argument vector" argv.
 *
 *                     |           |
 *                     V           V
 *      int main(int argc, char *argv[])
 *
 * The int argc contains the count of arguments including one for the name of
 * the command used to run the program itself. In this example:
 *
 *      ./drawstraws bill ted
 *
 * ...argc contains the integer "3".
 *
 * Using the same example above, the argv contains:
 *
 *      ./drawstraws\0bill\0ted\0
 *
 * ...where the "\0" represents the end of a position in the array.
 *
 * This is actually an array of arrays of bytes. Analogous to an array of
 * strings.
 *
 *
 * printf() is a function for emitting output.
 *
 *                |                  |
 *                V                  V
 *              ____    ____________________________
 *             |    |  |                            |
 *      printf("%s\n", argv[(rand() % (argc-1)) + 1]);
 *
 * Here we are providing two parameters. The first is "%s\n" which is a placeholder we declare to be a
 * string followed by a newline. The second parameter returns the string we
 * want to output.
 *
 * The second parameter is doing the majority of the work in this program.
 *
 *              |    |    |       |
 *              V    V    V       V
 *      argv[(rand() % (argc-1)) + 1]
 *
 * argv[] is our array of strings: ./drawstraws\0bill\0ted\0
 *
 * We don't want position 0 of the array to be in our output. So the rightmost
 * " + 1" ensures we never return the 0th position.
 *
 * rand() produces a pseudo-random number based on the srand() seed we called
 * earlier.
 *
 * argc-1 is complementing our desire to exclude the 0th position in the array.
 * We no longer want 3 positions. We want 3 minus the program name itself or 2.
 * Just the "bill" and "ted" portions; not the "./drawstraws" one.
 *
 * Lastly the % or modulo symbol takes the random number and our desired count
 * of strings and results in a random selection of an integer in our array.
 *
 */

    printf("%s\n", argv[(rand() % (argc-1)) + 1]);

    exit(0); //all done
}
