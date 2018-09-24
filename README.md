# dectobin

dectobin is a simple linux command to convert decimal numbers to binary. It
accepts some options, see below.

### Install

Clone this repo
cd into it 
run the very complex makefile 
test

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

Depends of linux regex library and getopt. Tested only in one machine running Arco

### Options

#### [-n|--no-newline]
    No new line after the binary number.

#### [-s|--splitted] SEPN
    Inserts a space each SEPN numbers in output. Max 2 digit.

#### [-h|--help]
    Output the usage and help (this message). Can't combine.

#### --version
    Output version. Unlike most commands, you can combine this with others options.

so much options
