# dectobin

dectobin is a simple linux command to convert decimal numbers to binary. It
accepts some options, see below.

### Install

Clone this repo; cd into it; run the very complex makefile; test

```
git clone https://github.com/Gautley/dectobin.git
cd dectobin
make
./bin/dectobin 999 -s 2
```

Probably, you will want to move the binary to somewhere in your PATH variable.

```
mv ./bin/dectobin "some directory in PATH"
```

### Dependencies

Depends on linux regex library and getopt. 

### Options

#### -n, --no-newline
    No new line after the binary number.

#### -s, --split N\_BITS
    Inserts a space each N_BITS bits in output. Max 2 digit.

#### -l, --at-least N\_BYTES
    Ensures that the binary number will have at least N_BYTES
    (with leading zeros)

#### -h, --help
    Output the usage and help (this message). Can't combine.

#### --version
    Output version.
    Unlike most commands, you can combine this with others options.

so much options
