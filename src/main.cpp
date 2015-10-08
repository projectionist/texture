#include <iostream>
#include <Magick++.h>
#include <cstdio>

using namespace std;
using namespace Magick;

int main(int argc, char **argv)
{
  // return check();

  if (argc != 3) {
    cerr << "USAGE: texture <input_image_path> <output_texture_path>" << endl;
    return EXIT_FAILURE;
  }

  if (sizeof(size_t) != sizeof(uint64_t)) {
    cerr << "size_t type is not 64bit." << endl;
    return EXIT_FAILURE;
  }

  Image img(argv[1]);

  Blob blob;

  img.write(&blob, "RGBA");

  const void *pixels = blob.data();

  auto sz = img.size();
  auto width = sz.width();
  auto height = sz.height();

  FILE *file = fopen(argv[2], "w");
  if (!file) {
    cerr << "can't open texture file for writing." << endl;
    return EXIT_FAILURE;
  }

  // TODO check these writes work.
  fwrite(&width, sizeof(uint64_t), 1, file);
  fwrite(&height, sizeof(uint64_t), 1, file);
  fwrite(pixels, 1, blob.length(), file);

  fclose(file);

  return EXIT_SUCCESS;
}
