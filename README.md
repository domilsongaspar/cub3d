# cub3D

A small 3D raycasting project developed for the 42 school curriculum. This implementation renders a simple 3D scene from a 2D map using a raycasting engine and the MiniLibX graphics library.

All mandatory and bonus objectives were completed for this repository.

## Features
- Raycasting-based 3D renderer
- Textured walls and floor/ceiling colors
- Sprite rendering (objects/enemies)
- Minimap and map parsing/validation
- Door handling (open/close)
- Mouse and keyboard controls

## Requirements
- Linux
- GCC
- MiniLibX (provided in the `mlx/` folder)

## Build
Run `make` at the project root. The repository includes a `Makefile` that builds the `cub3d` binary.

```sh
make
```

## Usage
Run the program with a `.cub` map file from the `maps/` directory:

```sh
./cub3d maps/subject_map.cub
```

Controls (default):
- `W` / `S`: move forward / backward
- `A` / `D`: move left / right (strafe)
- Left / Right arrows: rotate view
- Mouse: look around
- `ESC`: quit

## Maps
Maps are plain `.cub` files located in the `maps/` directory. The parser validates textures, colors, and map enclosure. Use the included example maps to test the engine.

## Notes
- This project was implemented for educational purposes as part of the 42 curriculum.
- All bonus features were implemented and tested locally.

## Author
Student at 42 — project completed with all bonuses.
