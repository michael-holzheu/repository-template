# Example template

### Contents of package

- libexample: Implementation of sample library
  - include/lib/example.h: Prototypes
- libutil: Helper functions from s390-tools package
- examples: Example program

The package also contains the following files:

 * [LICENSE](LICENSE): The MIT license that applies to this package
 * [CHANGELOG](CHANGELOG.md): The history of turing-machine versions

### Build

```bash
~/src/repository-template (master)$ make
```

### Run example

```bash
holzheu:~/src/repository-template (master)$ examples/example  -h
Usage: example [OPTIONS]

Show an example

OPTIONS
 -i, --int-test INTEGER  Hold an integer
 -b, --bool-test         Boolean option
 -h, --help              Print this help, then exit
 -v, --version           Print version information, then exit
```

```bash
holzheu:~/src/repository-template (master)$ examples/example  -i 42 -b
bool: 1
int.: 42
Invocation: Example library
```
