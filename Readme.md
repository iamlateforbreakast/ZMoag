A small isometric exploration game demonstration.

## Building in a container

The `Containerfile` builds on the local `base24` image (Ubuntu 24.04) and
compiles SDL3, SDL3_image and SDL3_ttf from source, since Ubuntu 24.04 does
not package them.

Build the image:

```sh
podman build -t zmoag-exp -f Containerfile .
```

Compile the game (release by default, add `debug` at the end for a debug build):

```sh
podman run --rm -v "$PWD":/workspace:Z zmoag-exp
podman run --rm -v "$PWD":/workspace:Z zmoag-exp debug
```

The executable is written to `build/bin/ZMoag`.

## Running in the container

The game loads its assets (`gfx/`, `fonts/`, ...) relative to the current
directory, so it must be started from the repository root. To open its window
on the host Wayland desktop:

```sh
podman run --rm --security-opt label=disable -v "$PWD":/workspace \
  -e WAYLAND_DISPLAY=$WAYLAND_DISPLAY -e XDG_RUNTIME_DIR=/tmp/xdg \
  -v $XDG_RUNTIME_DIR/$WAYLAND_DISPLAY:/tmp/xdg/$WAYLAND_DISPLAY \
  --device /dev/dri --entrypoint ./build/bin/ZMoag zmoag-exp
```

To run without a display (e.g. for testing), use SDL's offscreen video and
dummy audio drivers:

```sh
podman run --rm -v "$PWD":/workspace:Z \
  -e SDL_VIDEO_DRIVER=offscreen -e SDL_AUDIO_DRIVER=dummy \
  --entrypoint ./build/bin/ZMoag zmoag-exp
```

## Running on the host

The binary can also be run directly from the repository root as
`./build/bin/ZMoag`, provided SDL3, SDL3_image and SDL3_ttf are installed on
the host (on Fedora: `sudo dnf install SDL3 SDL3_image SDL3_ttf`).
