# X-Settlers

"The Settlers 3/4" re-work. Planned to run on as many platforms as possible, including Android, Raspberry Pi, OSX, GNU/Linux and Windows 10.

* C Standard: C++17

![X-Settlers Topography](./xsettlers/docs/screenshots/xsettlers_textured.png)

Also checkout the [OpenS4 Project](https://github.com/MadShadow-/OpenS4) with more progress in settlers game logic implementation.

## Upcoming Features

- [ ] Add perfomance profiling options. (ImGUI)
- [ ] Texture Atlas creation ~~directly from original Settlers 3 GFX files~~
- [ ] Load S3 graphics and maps directly from s3 install directory
- [x] Consistent camera dragging behavior, regardless of current zoomlevel
- [x] Assigning correct texture atlas UV coordinates to each triangle vertex based on field type (grass, rock, sea, etc.)
- [ ] More easily understandable, editable texture assignment. (maybe ID lookup table)
- [ ] Order map into quadtree data structure for fast CPU-side view frustum culling.

## Planned Features

* Generate map texture as LOD mesh replacement at certain camera distance

# Table of Contents

* [Project Setup](#project-setup)
  * [Windows](#windows)
  * [Linux](#linux)
* [Controls](#controls)
* [Contributing](#contributing)
* [Credits](#credits)

### Engine Documentation

  * [Components](./engine/docs/COMPONENTS.md)
  * [Renderer](./engine/docs/RENDERER.md)

### X-Settlers Documentation

  * [Maps](./xsettlers/docs/MAPS.md)

# Project Setup

Make sure to include the git submodules when cloning the repository!

```shell
> git clone --recurse-submodules https://github.com/Skarmux/X-Settlers
> cd X-Settlers/
```

## Windows

Requirements:

* Visual Studio 2019
* CMake 3.19+
* SDL 2.0 (binaries already included)

Making the Visual Studio solution files.

```shell
> cmake . -A x64 -G "Visual Studio 16 2019"
```

Open the newly created 'X-SETTLERS.sln' solution file in Visual Studio, build and run the project using Visual Studio.

## Linux

Requirements:

* SDL 2.0
* CMake 3.19+

Generate a Unix Makefile.

```shell
> cmake . -A x64 -G "Unix Makefile"
> make
```

# Controls

* Move camera by right-clicking and dragging the mouse.
* Zoom in- and out using the scroll wheel

# Contributing

At this early stage of development, contributions about certain features of the game- and engine are best brought in at our public discord server:

Settlers IV Modding: https://discord.gg/qXDkvW6

# Credits

Maintainer and Core Engine Developer:<br>
[Skarmux](https://github.com/Skarmux)<br>

Mentor and a helping hand regarding low-level,<br>C/C++, CMake and other valuable intel:<br>
[tehKaiN](https://github.com/tehKaiN)<br>

Siedler 3 map and gfx decryption ( [sied3](https://github.com/tomsoftware/sied3) ):<br>
[Thomas Zeugner (tomsoftware)](https://github.com/tomsoftware)

Basic core engine setup derived from the awesome<br>
[Game Engine Series](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) by [Yan Chernikov
(TheCherno)](https://github.com/TheCherno)