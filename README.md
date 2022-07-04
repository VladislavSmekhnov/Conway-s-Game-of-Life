# Conway-s-Game-of-Life

## On MacOs:
for ncurses.h usage
```sh
brew install ncurses
```
```sh
# cd src/
gcc -Wall -Werror -Wextra -lncurses conways_game_of_life.c
```
### then your_output_file < your_txt_file.txt
```sh
# for example:
./a.out < 1.txt
```
### to terminate the program press: Control + C or wait until:
```sh
GAME OVER
```
#
## On Linux (Ubuntu, Debian):
for ncurses.h usage
```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```

```sh
# cd src/
gcc -Wall -Werror -Wextra conways_game_of_life.c -lncurses
```
### then your_output_file < your_txt_file.txt
```sh
# for example:
./a.out < 1.txt
```
### to terminate the program press Ctrl + C or wait until:
```sh
GAME OVER
```
#
## On Windows (10):
### Download from Microsoft Store any Linux distributive (Ubuntu for example) - <a href="https://apps.microsoft.com/store/detail/ubuntu-on-windows/9NBLGGH4MSV6?hl=ru-ru&gl=RU">WSL</a>. And then use Linux commands in your system!