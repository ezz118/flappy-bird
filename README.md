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
 - Welcome to Flappy Bird! We recreated this classic game using C++ and it can run in Linux environment.
 - It is an interesting and simple game, the only thing you need to do is to press SPACE to move your bird!
 - Try to pass as many obstacles as you can, and create your best record that none of your friends can beat you😎
 - When you feel bored, play this game to kill time; when you feel depressed, play this game to relieve your stress (or increase your stress🫣)
 - The original version of the game is https://flappybird.io/, but we made a scoreboard in addition to it.
- Game rules
 - Just press SPACE to make the failing bird fly upwards and fly between columns of green obstacles without hitting them!
 - After passing one column, you can get one score!
 - Be careful! If your bird hits the green obstacles or falls to the ground, the game will end!

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
    - The intervals between obstacles and the heights of the holes are generated randomly (see [startgame.cpp](startgame.cpp)).
  - Data structures for storing game status
    - We use a struct Rank which contains a string and int variables to store players' scores (see [menu.cpp](menu.cpp)).
    - The status of the bird is stored in a variable of class Bird (see [bitr.cpp](bird.cpp)).
    - We use an STL list to store the position of obstacles on the screen (see [startgame.cpp](startgame.cpp)).
  - Dynamic memory management
    - We use a dynamic memory variable of class bird to store its status for each game (see [startgame.cpp](startgame.cpp)).
  - File input/output (e.g., for loading/saving game status)
    -We use "ranking.txt" to save the score leaderboard (see [menu.cpp](menu.cpp)).
  - Program codes in multiple files
    - We write codes in multiple files, which is easy to manage (see [Makefile](Makefile)).
  - Proper indentation and naming styles
    - We do proper indentation and name functions and variables properly.
  - In-code documentation
    - We add comments to explain the functions and important constants and variables.

- main.cpp
  - Print the introduction of the game. 
  - Include 3 branches: starting the game, showing the leaderboard and quitting the game.
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
  - Check whether the bird hits the obstacle.
  - Check whether the bird has passed the current obstacle or not.
- obstacle.h
  - Header file of obstacle.cpp
- startgame.cpp
  - Execute the game with the main loop.
  - Generation of random game sets: It generates the heights of the obstacles' holes randomly. Besides, we use probability distribution to generate new obstacles.
  - Data structures for storing game status: The status of the bird is stored in a variable of class Bird. The status of the obstacles is stored in a list of obstacle classes.
- startgame.h
  - Header file of startgame.cpp
- Makefile
  - Program codes in multiple files: It compiles files into one game function.
  - It can clean all unnecessary files.
  - It can reset the "ranking.txt", we add this function here instead of in the game because we think players should not have permission to reset the leaderboard.
- interactive.cpp
  - Support interaction between the user and the computer, including functions that are different in Linux and Windows like checking the hit keyboard, clear screen and sleep function.
  - For the function of keyboard_hit, we refer to https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
- interactive.h
  - Header file of interactive.cpp 
