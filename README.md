# Facebook Hacker Cup 2017

This repository contains my solutions to the problems from [Facebook Hacker Cup 2017][1]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [25: Progress Pie][qual1] (`progress-pie`)
* ✓ [30: Lazy Loading][qual2] (`lazy-loading`)
* ✓ [45: Fighting the Zombie][qual3] (`fighting-the-zombie`)

### Round 1

* ✓ [10: Pie Progress][round11] (`pie-progress`)
* ✓ [25: Manic Moving][round13] (`manic-moving`)

[1]: https://www.facebook.com/hackercup
[qual1]: https://www.facebook.com/hackercup/problem/1254819954559001/
[qual2]: https://www.facebook.com/hackercup/problem/169401886867367/
[qual3]: https://www.facebook.com/hackercup/problem/326053454264498/
[round11]: https://www.facebook.com/hackercup/problem/1800890323482794/
[round13]: https://www.facebook.com/hackercup/problem/300438463685411/
