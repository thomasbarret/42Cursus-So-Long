# 42 Cursus - So Long

**So Long** is a 2D puzzle game where the player navigates through a maze while collecting items and avoiding obstacles. The goal is to reach the exit while collecting all the necessary collectibles. This project was developed as part of the 42 Cursus and aims to showcase skills in programming, particularly in C, and problem-solving abilities.

---

## Table of Contents
- [Requirements](#requirements)
- [Compilation and Usage](#compilation-and-usage)
- [Game Rules](#game-rules)
- [File Structure](#file-structure)
- [Libraries](#libraries)
- [Map Format](#map-format)
- [Contributing](#contributing)

---

## Requirements

- GCC (GNU Compiler Collection)
- Make
- MinilibX (a graphics library)
- A Unix-based system (macOS or Linux) is recommended

---

## Compilation and Usage

To compile the project, use the `Makefile` provided:

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your_username/so_long.git
   cd so_long
   ```

2. To compile the project:
   ```bash
   make
   ```

3. Run the game:
   ```bash
   ./so_long <map_file.ber>
   ```

   The game will open a window where you control the player to move around the map.

---

## Game Rules

- **Objective:** Navigate the maze, collect all items, and reach the exit without running into walls or missing any collectibles.
- **Movement:** Use the arrow keys (`UP`, `DOWN`, `LEFT`, `RIGHT`) to move.
- **Items:** Collectibles are marked by items in the maze. You need to collect all before heading to the exit.
- **Exit:** Once all collectibles are gathered, the exit will be unlocked. Reach the exit to complete the level.
- **Walls:** Navigate through walls and ensure not to collide with them. The game will end if you run into a wall.

---

## File Structure

```
.
├── Makefile                  # Makefile to compile the project
├── assets                    # Game assets like images
│   ├── exit.xpm
│   ├── floor.xpm
│   ├── item.xpm
│   ├── player.xpm
│   └── wall.xpm
├── libs
│   └── mlx                   # MinilibX library for graphics
├── maps                      # Predefined maps to test the game
│   ├── 01_noextension
│   ├── 02_empty.ber
│   └── 18_42map.ber
├── src
│   ├── functions             # Game logic (e.g., events, map handling, etc.)
│   ├── hooks.c               # Keyboard/mouse event handling
│   ├── player.c              # Player movement and interactions
│   └── so_long.c             # Main entry point for the game
└── headers                   # Header files for functions and structures
    ├── ft_printf.h
    ├── get_next_line.h
    ├── libft.h
    └── so_long.h
```

---

## Libraries

The project uses the **MinilibX** library for graphics and window management. Additionally, it uses custom libraries such as `libft` and `get_next_line` for handling basic functionalities like memory allocation, string manipulation, and file reading.

- **MinilibX**: The core library for rendering images and handling user inputs.
- **libft**: A collection of basic C functions like string handling and memory management.
- **get_next_line**: A utility to read files line-by-line, used to parse the map files.

---

## Map Format

The game maps are in `.ber` format and consist of a grid of characters. The following are the possible characters in the map:

- `1`: Wall
- `0`: Floor
- `P`: Player's starting position
- `C`: Collectible item
- `E`: Exit

Each map must have at least one player, one exit, and one collectible.
