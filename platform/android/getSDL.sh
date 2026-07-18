#!/bin/bash

mkdir SDL

pushd SDL

wget https://www.libsdl.org/release/SDL2-2.0.12.zip
unzip -q SDL2-2.0.12.zip
mv SDL2-2.0.12/include include
ln -s . include/SDL2

sed -i '35s@.*@#include "SDL_opengles2_khrplatform.h"@' include/SDL_opengles2.h
sed -i '36s@.*@#include "SDL_opengles2_gl2platform.h"@' include/SDL_opengles2.h
sed -i '37s@.*@#include "SDL_opengles2_gl2.h"@' include/SDL_opengles2.h
sed -i '37a#include "SDL_opengles2_gl2ext.h"' include/SDL_opengles2.h

rm SDL2-2.0.12.zip
rm -r SDL2-2.0.12

popd
