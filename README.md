# A-Maze-D

A C-based multi-agent pathfinding simulation where a fleet of robots must navigate a maze toward an exit, requiring a centralized scheduling system to prevent occupancy conflicts and optimize flow.

---

## 🧠 Description

This project implements a discrete-time simulation of robot movement within a graph-based maze structure. The core constraint dictates that each room (node) can host a maximum of one robot per time step (tick), necessitating the development of a traffic management algorithm to redirect units and resolve bottlenecks.

---

## 🚀 Getting started

### Installing

**Clone the repository:**

```bash
git clone https://github.com/QUINTIN-Killian/A-Maze-D.git
cd A-Maze-D
```

### Executing program

**Compiling:**

```bash
make
```

**Executing:**

```bash
./amazed < <maze_file>
```

Example:

```bash
./amazed < bonus/scripts/maze
```

---

## 👥 Authors

* [@Killian QUINTIN](https://github.com/QUINTIN-Killian)
* [Noë GEBERT](https://github.com/noe-gt)
* [Elie CHARDIN](https://github.com/Elieleche)
