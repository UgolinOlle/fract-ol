# fract-ol

<div align="center">
    <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/fract-olm.png" alt="fract-ol 42 project badge">
</div>

[![42 School Project](https://img.shields.io/badge/42%20Project-printf-blue)](https://github.com/ugolinolle/ft_printf)
[![Language: C](https://img.shields.io/badge/language-C-green.svg)](<https://en.wikipedia.org/wiki/C_(programming_language)>)

## 💻 Description

Fract-ol is a graphical project that explores fractals, mathematical sets that exhibit a repeating pattern displayed at every scale. This project allows users to visualize and interact with various fractals in real-time.

## ⌨️ Usage

### Prerequisites

Before running the program, make sure you have the following dependencies installed:

- [MinilibX](https://github.com/42Paris/minilibx-linux) - A simple X-Window (X11R6) programming API in C, needed for graphics.

### Compilation

To compile the Fract-ol program, use the provided Makefile:

```bash
make
make bonus
```

### Execution

Run the program with the desired fractal type as an argument:

```bash
./fractol [fractal name] [option]
./fractol julia [1 | 2 | 3]
```

Supported fractal types:

- Mandelbrot
- Julia
- Tricorn

### Controls

- Arrow keys: Move around the fractal
- Scroll wheel: Zoom in and out
- AWSD: Change Julia iteration

## 🧑‍🤝‍🧑・Contributing

To use Auto-Push in development, follow these steps:

1. Fork the project.

2. Install MLX library.

3. Create a branch with [conventionnal name](https://tilburgsciencehub.com/building-blocks/collaborate-and-share-your-work/use-github/naming-git-branches/).

   - fix: `bugfix/the-bug-fixed`
   - features: `feature/the-amazing-feature`
   - test: `test/the-famous-test`
   - hotfix `hotfix/oh-my-god-bro`
   - wip `wip/the-work-name-in-progress`

4. Commit your change with [conventional commit](https://www.conventionalcommits.org/en/v1.0.0/)
5. Push to the branch
6. Open a pull request

Please make sure to test your changes thoroughly before submitting a pull request.

## 📑・Licence

This project is licensed under the MIT licence. For more information, please consult the file [LICENSE](./LICENSE).

## 📩・Contact

If you have any questions or would like to collaborate, please do not hesitate to contact me at [email](mailto:hello@ugolin-olle.com) or [LinkedIn](https://linkedin.com/in/ugolin-olle)
