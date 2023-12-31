#!/bin/bash

git clone https://github.com/jeekpark/lunar-lander.git

compiler=$(cc --version)
arch=$(uname -m)

if [[ $compiler == *"gcc"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-linux-gcc-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-macOS-clang-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "arm64" ]; then 
  sfml_bundle="SFML-2.6.1-macOS-clang-arm64.tar.gz"
fi

sfml_bundle_out=${sfml_bundle%.tar.gz}

tar -xzvf ./lunar-lander/lib/sfml/$sfml_bundle -C ./lunar-lander/lib/sfml
mv ./lunar-lander/lib/sfml/$sfml_bundle_out ./lunar-lander/lib/sfml/2.6.1
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/FLAC.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/FLAC.framework
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/freetype.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/freetype.framework
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/ogg.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/ogg.framework
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/vorbis.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/vorbis.framework
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/vorbisenc.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/vorbisenc.framework
mv ./lunar-lander/lib/sfml/2.6.1/extlibs/vorbisfile.framework ./lunar-lander/lib/sfml/2.6.1/Frameworks/vorbisfile.framework



make -C lunar-lander clangd
make -C lunar-lander all


