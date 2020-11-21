# libjpeg.Net
Libjpeg C# and Unity Wrapper Source.

Based on https://github.com/libjpeg-turbo/libjpeg-turbo

Standalone Source Code

Wrapper is part of another project

# Usage

```
extern "C" unsigned char * read_Image(int size, unsigned char *_img, char *logfile)
```

Intptr is marshalled before and after receiving pointers to the data from the c++ unmanaged code.

```
C#
    [DllImport("nativejpeg")]
    private static extern IntPtr read_Image(int size, IntPtr _img, StringBuilder logfile);
```

# Build

use **ndk-build** to create respective **.so** file.
