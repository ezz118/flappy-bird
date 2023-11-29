Flappy Bird
   -
Team members
-   
 - Deng Shen 3036077748 Github: @SillyDacian
 - Lai Ruize 3035973270 Github: @ruizelai
 - Ke Wenjun 3035974365 Github: @poiuy1z
 - Mai Junshen 3035974444 Github: @ezz118

Description of our project
-
 - Welcome to Flappy Bird! We recreated this classic game using C++ so that it can be played through the Linux terminal and SSH.
 - It is a simple but interesting game, the only thing you need to do is just press SPACE!
 - Try to pass as many obstacles as you can, and create a record that none of your friends can beat😎
 - When you feel bored, play this game to kill time; when you feel depressed, play this game to relieve your stress (or increase your stress🫣)

Game rules
-
 - Just press SPACE to make the descending bird fly upwards and fly between columns of green obstacles without hitting them!
 - After passing one column, you can get one score!
 - Be careful! If you hit the green obstacles, the game will end!

How to run Flappy Bird?
-
 -  Download and extract the ZIP containing the files. All files should be under the same directory.
 -  Run the command
 ```bash
make game
```
 - Then run the command to start the game!
```bash
./game
```
 - Remember to fullscreen your console!
 - Then press SPACE to enter the menu
 - Press
   - 1 to start the game
     - During the game, you can press q to pause the game.
     - When you pause, you can resume by pressing SPACE, quit the game by pressing q or return to the main menu by pressing m.
     - After hitting the green block, the game ends and you will be invited to enter your name if your score is high enough to enter the leaderboard. Your records will be saved in the "ranking.txt" file.
   - 2 to show the leaderboard
     - The Leaderboard will show the top 10 results and their names.
   - 3 to quit the game
   
Features implemented in each file and coding requirements
-
- Code Requirement
  - Generation of random game sets or events
    - The heights of the obstacles' holes are generated randomly (see [startgame.cpp](startgame.cpp)).
  - Data structures for storing game status
    - We use a struct Rank which contains a string and int variables to store players' scores (see [menu.cpp](menu.cpp)).
    - The status of the bird is stored in a variable of class Bird (see [startgame.cpp](startgame.cpp)).
  - Dynamic memory management
    - We use dynamic memory management to sort the scores (see [menu.cpp](menu.cpp)).
  - File input/output (e.g., for loading/saving game status)
    -We use "ranking.txt" to save the score leaderboard (see [menu.cpp](menu.cpp)).
  - Program codes in multiple files
    - We write codes in multiple files, which is easy to manage (see [Makefile](Makefile)).
  - Proper indentation and naming styles
    - We name functions and variables properly.
  - In-code documentation
    - We add comments to explain the codes.

- main.cpp
  - Include 3 branches: starting the game, showing the leaderboard and quitting the game.
  - //further description
- menu.cpp
  - Makes a menu page and prints instructions to players.
  - Asks players to input their usernames only when they enter the top 10 leaderboard.
  - File input/output: It updates the score leaderboard and only inputs the top 10 players' scores and usernames in "ranking.txt" to make sure the size of "ranking.txt" won't be too large. It outputs the top 10 scores and their usernames if players want to do so.
  - Dynamic memory management: It uses dynamic memory management to sort the scores.
  - Data structures for storing game status: It uses a struct Rank which contains a string and int variables to store players' scores.
- menu.h
  - Header file of menu.cpp
- bird.cpp
  - Keep track of the position and the velocity of the bird.
  - Set the "rebounce" velocity and the change of speed of the bird after every hit of the keyboard.
- bird.h
  - Header file of bird.cpp
- obstacle.cpp
  - Set the position, moving speed of the obstacle and the position of the "hole" of every obstacle.
  - Provide a discriminant to check whether the bird hits the obstacle.
  - Check whether the bird has passed the current obstacle or not.
- obstacle.h
  - Header file of obstacle.cpp
- startgame.cpp
  - Execute the game.
  - Generation of random game sets: It generates the heights of the obstacles' holes randomly. Besides, we use probability distribution to generate new obstacles.
  - Data structures for storing game status: The status of the bird is stored in a variable of class Bird. The status of the obstacles is stored in a list of obstacle classes.
- startgame.h
  - Header file of startgame.cpp
- Makefile
  - Program codes in multiple files: It compiles files into one game function.
  - It can clean all unnecessary files.
  - It can reset the "ranking.txt", we add this function here instead of in the game because we think players should not have permission to reset the leaderboard.
- interactive.cpp
  -//
- interactive.h
  - Header file of interactive.cpp 
    
