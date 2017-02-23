# BooliCPP

## Work in progress

### Environment versions

gcc 5.4.0
glibc 2.23

### Libraries to be able to compile

sudo apt-get install libssl-dev

sudo apt-get install libcurl4-openssl-dev

### For unit tests install google test

sudo apt-get install libgtest-dev

Note that this package only install source files. You have to compile the code yourself to create the necessary library files. These source files should be located at /usr/src/gtest. Browse to this folder and use cmake to compile the library:

sudo apt-get install cmake

cd /usr/src/gtest

sudo cmake CMakeLists.txt

sudo make

copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder

sudo cp *.a /usr/lib
