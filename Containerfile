# Build:   podman build -t zmoag-exp -f Containerfile .
# Compile: podman run --rm -v "$PWD":/workspace:Z zmoag-exp
#          (pass "debug" as an extra argument for a debug build)
FROM localhost/base24

ENV DEBIAN_FRONTEND=noninteractive

# base24 defaults to the unprivileged "builder" user; installing needs root.
# Staying root also lets rootless podman write build output into the mounted
# workspace as the host user.
USER root

ARG SDL3_VERSION=3.4.20
ARG SDL3_IMAGE_VERSION=3.4.8
ARG SDL3_TTF_VERSION=3.2.2

# Ubuntu 24.04 does not package SDL3, so install the libraries it needs
# (video, audio, input, image and font backends) and build it from source.
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential ca-certificates git ninja-build pkg-config \
    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev \
    libxi-dev libxss-dev libxtst-dev libxkbcommon-dev \
    libwayland-dev wayland-protocols libdecor-0-dev \
    libegl1-mesa-dev libgl1-mesa-dev libgles2-mesa-dev libdrm-dev libgbm-dev \
    libasound2-dev libpulse-dev libpipewire-0.3-dev \
    libdbus-1-dev libudev-dev \
    libpng-dev libjpeg-dev \
    libfreetype-dev libharfbuzz-dev \
    && rm -rf /var/lib/apt/lists/*

RUN set -e; \
    build() { \
        git clone --depth 1 --branch "release-$2" "https://github.com/libsdl-org/$1.git" "/tmp/$1"; \
        repo="$1"; shift 2; \
        cmake -S "/tmp/$repo" -B "/tmp/$repo/build" -G Ninja \
            -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local "$@"; \
        cmake --build "/tmp/$repo/build"; \
        cmake --install "/tmp/$repo/build"; \
        rm -rf "/tmp/$repo"; \
    }; \
    build SDL "$SDL3_VERSION" -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF; \
    build SDL_image "$SDL3_IMAGE_VERSION" -DSDLIMAGE_VENDORED=OFF \
        -DSDLIMAGE_AVIF=OFF -DSDLIMAGE_JXL=OFF -DSDLIMAGE_TIF=OFF -DSDLIMAGE_WEBP=OFF; \
    build SDL_ttf "$SDL3_TTF_VERSION" -DSDLTTF_VENDORED=OFF -DSDLTTF_PLUTOSVG=OFF; \
    ldconfig

# Project sources live in a mounted workspace, not baked into the image.
VOLUME ["/workspace"]
WORKDIR /workspace

ENTRYPOINT ["./build.sh"]
CMD ["release"]
