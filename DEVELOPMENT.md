11/15/18
* fixed issues with pushing to Github
* got openframeworks working correctly
* started basic game logic (e.g., pruning full rows)

11/27/18
* added background music (library requirement met)
* added class to keep track of high scores
* created basic-looking background for game
* fixed a bug in which sound wouldn't restart after game was paused

11/29/18
* added randomized piece generation
* polished game's appearance 

12/5/18
* fixed bug where pieces weren't the right color
* continued polishing game's appearance (likely final version)
* rewrote tetromino generation function

12/6/18
* restructured tetromino/board representation
* moving pieces side-to-side now works (but is slow and needs fixing)

12/8/18
* completely restructured tetromino/board representation (again)
* added functions to check if tetromino can continue falling and if it can move to the left or right
* added basic version of scoring
* added an endgame condition

12/10/18
* largely rewrote generation/placing functions

12/12/18
* added ability to rotate tetrominoes
* fixed bug where not all tetromino blocks checked for collision when falling
* added (moving) collision detection with other tetrominoes


STILL NEEDED (AS OF 12/8)
- [ ] add pause screen
- [ ] add game over screen
- [ ] add leaderboard (code mostly there; mainly needs graphic implementation)

