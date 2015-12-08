# Texture

Converts images from imagemagick-supported formats to a simple to process texture format.

File format:

* uint64_t width
* uint64_t height
* byte[] pixels in RGBA

Depends ImageMagick++, install from source, headers required.
Don't forget to `sudo ldconfig /usr/local/lib`.
