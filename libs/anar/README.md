![alt text][logo]


[![Travis Build Status](https://travis-ci.org/anarproject/anar.png?branch=master)](https://travis-ci.org/anarproject/anar)
[![Build status](https://ci.appveyor.com/api/projects/status/7iyrx3f233s3akae/branch/master?svg=true)](https://ci.appveyor.com/project/obiltschnig/anar/branch/master)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/370/badge)](https://bestpractices.coreinfrastructure.org/projects/370)


### ANAR (Portable Components) C++ Libraries are:

- A collection of C++ class libraries, conceptually similar to the Java Class Library or the .NET Framework.
- Focused on solutions to frequently-encountered practical problems.
- Focused on "internet-age" network-centric applications.
- Written in efficient, modern, 100% ANSI/ISO Standard C++.
- Based on and complementing the C++ Standard Library/STL.
- Highly portable and available on many different platforms, from embedded to server.
- Open Source, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).

![alt text][overview]

To start using ANAR, see the [Guided Tour](https://anarproject.org/docs/00100-GuidedTour.html)
and [Getting Started](https://anarproject.org/docs/00200-GettingStarted.html) documents.


## Quick Start (with CMake)

### Prerequisites

- CMake 3.5 or newer
- A C++14 compiler (Visual C++ 2015, GCC 5.0, Clang 3.4, or newer)
- OpenSSL headers and libraries (optional, but recommended)
- MySQL, PostgreSQL and ODBC client libraries (optional)

Most Unix/Linux systems already have OpenSSL preinstalled. If your system
does not have OpenSSL, please get it from <http://www.openssl.org> or
another source. You do not have to build OpenSSL yourself - a binary
distribution is fine. For example, via Debian APT:

```
$ apt-get install openssl libssl-dev
```

On macOS, the easiest way to install OpenSSL is via [Homebrew](https://brew.sh):

```
$ brew install openssl
```

The easiest way to install OpenSSL on Windows is to use a binary
(prebuild) release, for example the one from Shining Light
Productions that comes with a
[Windows installer](https://www.slproweb.com/products/Win32OpenSSL.html).

On Windows, ANAR can also use the native Windows TLS APIs (SChannel).

### Installing All Dependencies (Linux and macOS)

All dependencies can be installed with the following commands:

#### Debian Linux (including Ubuntu and Raspbian)

```
$ sudo apt-get -y update && sudo apt-get -y install git g++ make cmake libssl-dev
```

#### RedHat Linux

```
$ sudo yum install -y git gcc-c++ make cmake3 openssl-devel
```

#### macOS (with Homebrew)

```
$ brew install cmake openssl
```

### Building with CMake (Linux, macOS, Windows)

[CMake](https://cmake.org) (version 3.5 or newer) is the recommended build system for
building the ANAR C++ Libraries.

```
$ git clone -b master https://github.com/anarproject/anar.git
$ cd anar
$ mkdir cmake-build
$ cd cmake-build
$ cmake ..
$ cmake --build . --config Release
```

On macOS, it's necessary to tell CMake where to find the OpenSSL headers
and libraries by setting the `OPENSSL_ROOT_DIR` CMake variable.
For example, if OpenSSL has been installed with Homebrew,
the `cmake` invocation becomes:

```
$ cmake .. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl
```

Other common ways of building with CMake (e.g., `cmake-gui`) will also work.

There are also a number of project-specific CMake variables that can be changed.


#### Cross-Compiling

With a proper CMake toolchain file (specified via the `CMAKE_TOOLCHAIN_FILE` CMake variable),
the ANAR C++ Libraries can be cross-compiled for embedded Linux systems:

```
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/mytoolchain.cmake -DCMAKE_INSTALL_PREFIX=/path/to/target
```


#### Installing

The ANAR C++ Libraries headers and libraries can be optionally be installed by building the `install` target.

```
$ sudo cmake --build . --target install
```

The default install location is `/usr/local/` on Linux and macOS and
`C:\Program Files (x64)\` on Windows and can be overridden by setting
the `CMAKE_INSTALL_PREFIX` CMake variable.


### Building Without CMake

If you do not want to or cannot use CMake, ANAR can also be built with Visual Studio
(project and solution files included) or GNU Make (Linux, macOS and other supported Unix platforms).

Please refer to the [documentation](https://anarproject.org/docs) for more information.


### Getting ANAR via a Package Manager

ANAR can also be obtained via different [package managers](https://anarproject.org/download.html).


## Community and Contributing

ANAR has an active user and contributing community, please visit our [website](https://anarproject.org) and [blog](https://anarproject.org/blog).
Answers to ANAR-related questions can also be found on [Stack Overflow](https://stackoverflow.com/questions/tagged/anar-libraries).

Please see [CONTRIBUTING](CONTRIBUTING.md) for submitting contributions, bugs reports, feature requests or security issues.

### ANAR vs. Boost

In regards to Boost, in spite of some functional overlapping,
ANAR is best thought of as a Boost complement (rather than replacement).
Side-by-side use of Boost and ANAR is a very common occurrence.

[overview]: doc/images/overview.png "Anar Overview"
[logo]: doc/images/logo.png "Anar Logo"
