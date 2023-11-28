Flappy Bird
   -
Team members
-   
 - Deng Shen 3036077748
 - Lai Ruize 3035973270
 - Ke Wenjun 3035974365
 - //

Description of our project
-
 - We recreated the game "Flappy Bird" using C++ so that it can be played through the Linux terminal and SSH.

Game rules
-
 - Just press SPACE to make the descending bird fly upwards and fly between columns of green obstacles without hitting them!

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
     - After hitting the green block, the game will end and you will be invited to enter your username. Your records will be saved in the "ranking.txt" file.
   - 2 to show the leaderboard
     - The Leaderboard will show the top 10 results and their usernames.
   - 3 to quit the game
   
Features implemented in each file and coding requirements
-
- Code Requirement
  - Generation of random game sets or events
  - Data structures for storing game status
  - Dynamic memory management
  - File input/output (e.g., for loading/saving game status)
  - Program codes in multiple files
  - Proper indentation and naming styles
  - In-code documentation

- main.cpp
  - // please explain
- menu.cpp
  - Make a menu page and print instructions to players.
  - File input/output: It saves players' scores in "ranking.txt", and outputs the top 10 scores and their usernames if players want to do so.
  - Dynamic memory management: It uses dynamic memory management to sort the scores.
  - Data structures for storing game status: It uses a struct Rank which contains a string and an int variables to store players' scores.
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
  - Generation of random game sets: It generates the height of the obstacles' holes randomly. Besides, we use probability distribution to generate new obstacles.
  - Data structures for storing game status: The status of the bird is stored in a variable of class Bird. The status of the obstacles is stored in a list of obstacle classes.
- startgame.h
  - Header file of startgame.cpp 
    
