<h3 align="center">42 São Paulo - fract-ol</h3>

<div align="center">

![![norminette](https://github.com/librity/ft_fractol/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_fractol/actions/workflows/norminette_v3.yml)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_fractol?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_fractol?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_fractol?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_fractol?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_fractol?color=orange)

</div>

<p align="center"> A fractal navigator for the Julia and Mandelbrot sets.
  <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Checklist](#checklist)
- [Getting Started](#getting_started)
- [Controls](#controls)
- [Gallery](#gallery)
- [Notes](#notes)
- [42 São Paulo](#ft_sp)
- [Resources](#resources)

## 🧐 About <a name = "about"></a>

## ✅ Checklist <a name = "checklist"></a>

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

This will only compile on Linux and FreeBSD.

You will need a C compiler (`gcc` or `clang`)
and [minilibx](https://github.com/42Paris/minilibx-linux),
an X-Window API in C made by 42 Paris:

```bash
# Clone the repo
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux

# Install dependencies and build
sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
make

# Copy archive and headers to system path
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
sudo cp mlx_int.h /usr/local/include/

# Add pages to man (optional)
sudo mkdir /usr/local/man/man1
sudo cp man/man1/* /usr/local/man/man1/
man mlx
```

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone https://github.com/librity/ft_fractol.git
$ cd ft_fractol
$ make mbt
```

This should open a new window with a beautiful fractal.

```C
	ctl->julia_factor = complex(0.3, 0.4);
	ctl->julia_factor = complex(-2.0, 0.0);
	ctl->julia_factor = complex(-1.0, 0.0);
	ctl->julia_factor = complex(0.0, 0.0);
	ctl->julia_factor = complex(1.0, 0.0);
	ctl->julia_factor = complex(2.0, 0.0);
	ctl->julia_factor = complex(3.0, 0.0);
	ctl->julia_factor = complex(1.0, 1.0);
	// Dendrite fractal
	ctl->julia_factor = complex(0.0, 1.0);
	// Douady's rabbit fractal
	ctl->julia_factor = complex(-0.123, 0.745);
	// San Marco fractal
	ctl->julia_factor = complex(-0.75, 0.0);
	// Siegel disk fractal
	ctl->julia_factor = complex(-0.391, -0.587);
```

## 🕹️ Controls <a name="controls"></a>

- `Esc` or `q`: Exits program
- `=` and `-`: Zoom in and out
- `Mouse Wheel`: Zoom in and out
- `Arrow Keys`: Moves the fractal
- `Mouse Left Click`: Warp to clicked pixel
- `c`: Switches color algorithm
- `l` and `.`: Shifts color bases up and down
- `i` and `k`: Increases and decreases iterations
- `t` and `g`: Increases and decreases infinity
- `s`: Saves viewport to bitmap

## 🎨 Gallery <a name="gallery"></a>

<p align="center">
  <img src="gallery/mbt_x_0.000000_y_0.000000_zoom_414.719999_iter_451_inf_4.000000_cmode_2_.png" />
</p>

<p align="center">
  <img src="gallery/mbt_x_-0.105700_y_-0.925569_zoom_352745.176312_iter_551_inf_54.000000_cmode_2_.png" />
</p>

<p align="center">
  <img src="gallery/mbt_x_-0.105700_y_-0.925569_zoom_352745.176312_iter_151_inf_54.000000_cmode_2_.png" />
</p>

<p align="center">
  <img src="gallery/julia_lerp_hotline_miami_1.png" />
</p>

<p align="center">
  <img src="gallery/julia_lerp_hotline_miami_2.png" />
</p>

<p align="center">
  <img src="gallery/mandelbrot_lerp_malayan_coral_5.png" />
</p>

<p align="center">
  <img src="gallery/mandelbrot_lerp_malayan_coral_16.png" />
</p>

<p align="center">
  <img src="gallery/mandelbrot_lerp_malayan_coral_24.png" />
</p>

<p align="center">
  <img src="gallery/julia_x_-0.382581_y_-0.643019_zoom_914412203648.733276_iter_1751_inf_314.000000_cmode_1_lerpfr_-139024413_lerpto_-125743310_.png" />
</p>

[and much, much more...](https://github.com/librity/ft_fractol/tree/main/gallery)

## 📝 Notes <a name = "notes"></a>

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>
