# ID3 Tag Reader

This repository contains simple console application that reads and displays ID3 metadata from a given MP3 file using TagLib library.

---

## Features

- Read the **title** (`TIT2`) from an MP3 file
- Extract and save the **cover image** (`APIC`) embedded in the file

---

## Installation

This project is built for Linux OS.

### Dependencies

- C++ compiler (`g++`)
- [TagLib](https://taglib.org/) library
- `build-essential` package (for `make`)

### Steps

1. Clone this repository:

``` bash
$ git clone https://github.com/Mafpo/id3-metadata
$ cd id3-metadata
```

2. Install the required TagLib library (Ubuntu / Debian):

``` bash
$ sudo apt install libtag1-dev
```
Alternatively, you can get TagLib from: https://github.com/taglib/taglib

3. Build the project:

``` bash
$ make
``` 

---

## Usage

Run the application from the command line, passing the path to the MP3 file as an argument:

``` bash
./app <path_to_mp3>
``` 

### Example
``` bash
./app ~/Downloads/file.mp3
``` 
The program will display the ID3 metadata (such as the song title) and save the embedded cover image to the current directory, if available.

---

## Limitations

- Only **ID3v2** tags are supported. ID3v1 tags may be partially supported.
- Tested only on **Linux** (Ubuntu). Compatibility with other operating systems is not guaranteed.
- The input must be a valid `.mp3` file containing proper ID3v2 metadata. If not, the program may throw an exception or fail to parse the file.

---

## Used libraries

### [TagLib](https://taglib.org/)
- Well-documented
- Provides a rich C++ API
- Supports many audio file formats

---
