//
// Created by Kaushik on 25-07-2019.
//

#include <turbojpeg.h>
#include <fstream>
#include <utility>
#include <iostream>
#include <string.h>
#include <android/log.h>
#include <syslog.h>

#define JPEG_LIB_VERSION 82
#define  LOG_TAG    "DEBUG"
//#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


//Vars for source img
unsigned long jpg_size;
unsigned char *jpg_buffer;

//Vars for decompressed image
unsigned long fullsize;

int width, height, samples;


extern "C" unsigned char * read_Image(int size, unsigned char *_img, char *logfile)
{
    jpg_size = size;
    jpg_buffer = _img;

    std::ofstream st (logfile, std::ios_base::app);
    st << "Proc: Create Decompress struct \n" << jpg_size;

    st << "\n assigned vars \n";

    tjhandle _jpegDecompressor = tjInitDecompress();

    tjDecompressHeader2(_jpegDecompressor, jpg_buffer, jpg_size, &width, &height, &samples);
    long len = width * height * 4;
    long pitch = width * 4;

    st << "width : " <<  width << "\n height : " << height;

    st << "\n=============== DECOMP IN PROGRESSS ==============";

    unsigned char *fullImage = tjAlloc(len);

    st << "\n=============== DECOMPING NOW ==============";

    int res = tjDecompress2(_jpegDecompressor, jpg_buffer, jpg_size, fullImage, width, pitch, height, TJPF_RGBA, TJFLAG_FASTDCT);

    st << "\n=============== DECOMPING DONE ============== : " << res;

    tjDestroy(_jpegDecompressor);

    return fullImage;
}

extern "C" int TestPlugin(char *path)
{
    // Test plugin calls
    return 9000;
}
