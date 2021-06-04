# Disclaimer: Tic, Tac, Toe (B)
If 
- you have not completed the previous Tic, Tac, Toe Assignment
- or if you would like to go back to it and clean it up a bit
  - using a two-dimensional array 
  - an AI that uses random numbers
  - etc.

Then you may do so :) I'm happy about any result showing that you've understood arrays and random numbers.

# Bonus: Battleships (A/A*)
## The Rules (A):
- 2 Players
- 10 x 10 grid per player
- Simplified Ship Sizes: Only 5x 1 sized ships
- Players take alternating turns
- Coordinates given in the form g7, a2, d2 etc...
  - consider using the numeric value of chars! :)
  - can be simplified at first with two inputs:
    - first: `int x`
    - then: `int y`
- Feedback "Hit" or "Miss"
- Win Condition: All enemy ships have been sunk

## Bonus Rules (A*):
- Ships: sizes 5, 4, 3, 2 ships with 2
- Ships may be placed vertically or horizontally
- Ships may not overlap and may not touch each other (i.e. there needs to be at least 1 empty grid cell around the ship in every direction)
- Feedback "Ship sunk!"

# Bonus Bonus (No score):
- A.I.? :)
- Radar Power Up
  - Can be used to detect ships in a 3x3 radius around the location placed (but not hit them)
  - Can you think of other power-ups? :)
- Scanner Power Up
  - Can be used to scan a 3x3 radius around the location placed
  - Only returns "Ship detected" or "No ship detected"