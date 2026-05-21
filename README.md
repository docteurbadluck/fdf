# fdf — Fil de Fer

> Wireframe 3D map renderer — a 42 school project

![fdf screenshot](https://github.com/user-attachments/assets/bf2a4c1d-b671-48b1-93f0-8d23c6273e62)

<img width="1200" height="960" alt="fdf demo" src="https://github.com/user-attachments/assets/5b4b3f53-6583-4367-bc50-c2eb6acfe12b" />

---

## About

**fdf** reads a `.txt` map file containing a grid of elevation values and renders it as a 3D wireframe using an isometric projection. Each value in the grid represents the altitude (Z) of a point; adjacent points are connected by lines to form the mesh.

The rendering is done with [MiniLibX](https://github.com/42Paris/minilibx-linux), a lightweight X11 graphics library used in the 42 curriculum.

---

## Features

- Isometric 3D projection of any elevation map
- Color gradient on lines based on altitude (blue → green)
- Clean memory management and input validation
- ESC or window close button exits gracefully

---

## Dependencies

- Linux with X11
- `cc` (GCC or Clang)
- `make`
- X11 development headers: `libx11-dev`, `libxext-dev`

```bash
sudo apt-get install libx11-dev libxext-dev
```

---

## Build

```bash
git clone <repo-url> fdf
cd fdf
make
```

The binary is placed in `build/fdf`.

| Rule | Description |
|------|-------------|
| `make` | Build the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | Full rebuild |

---

## Usage

```bash
./build/fdf <map_file>
```

**Example:**

```bash
./build/fdf test1.txt
```

Press `ESC` or close the window to quit.

---

## Map format

A map file is a plain text grid of integers separated by spaces. Each integer is the elevation of a point. All rows must have the same number of columns.

```
0  0  0  0  0
0  1  2  1  0
0  2  4  2  0
0  1  2  1  0
0  0  0  0  0
```

Test maps are provided in the repository: `test1.txt` through `test4.txt`.

---

## Project structure

```
fdf/
├── srcs/
│   ├── main.c                        # Entry point
│   ├── init.c                        # MLX window/image init, key hooks
│   ├── from_file_to_array.c          # Parse map file → string array
│   ├── array_of_str_to_int.c         # Convert string array → int array
│   ├── point.c                       # Build 3D and 2D point arrays
│   ├── point_2d.c                    # Isometric projection helpers
│   ├── draw_line.c                   # Bresenham line drawing
│   ├── print.c                       # Render loop
│   ├── valid_input.c                 # Input validation
│   ├── same_number_of_column_in_array.c
│   ├── any_test_on_str_array.c
│   ├── free_any_array.c
│   └── print_any_array.c
├── includes/
│   └── fdf.h
├── libft/                            # Custom C library (42)
├── minilibx-linux/                   # MiniLibX (X11)
├── build/                            # Compiled output
└── test*.txt                         # Sample map files
```

---

## PDF subject

[fdf.pdf](https://github.com/user-attachments/files/18749260/fdf.pdf)
