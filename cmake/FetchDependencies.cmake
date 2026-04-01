include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG "v1.17.0"
)

FetchContent_Declare(
  sdl
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG "release-3.4.2"
)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Disable Unneeded SDL Parts
set(SDL_GPU OFF)
set(SDL_RENDER OFF)
set(SDL_CAMERA OFF)
set(SDL_SENSOR OFF)

FetchContent_MakeAvailable(spdlog sdl)

