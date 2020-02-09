# brace_expansion
I missed to add all the safety checks but code will do following:
* Examples of valid input and output:
 *
 * {A,B,C} -> A B C
 * {A,B}{C,D} -> AC AD BC BD
 * {A,B{C,D}} -> A BC BD
 * {ABC} -> ABC
 *
 * ABC -> ABC

