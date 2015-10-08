# Texture

Writes converts images from whatever format to the texture format for projectionist

File format:

* uint64_t width
* uint64_t height
* byte[] pixels in RGBA

Depends ImageMagick++, install from source, headers required.
Don't forget to `sudo ldconfig /usr/local/lib`.
