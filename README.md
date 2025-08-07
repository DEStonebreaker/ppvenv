# ppvenv
PPVENV (PREPARE PYTHON VIRTUAL ENVIRONMENT) is my personal tool for managing python modules and virtual environments. This is an (almost) accidental clone of Poetry. I was unaware of its existance until I had finished this small command line program.

#### Note
I do plan on changing the std::system() calls to something safer in the future. It was just easier for me to write a quick draft with them. I am not by anymeans recommending this as a safe tool and if you somehow manage to break your machine with this, my condolonces.

#### Usage
Using PPVENV is simple enough. There are only 4 commands that you need to know to use: init, run, add, and sync.
```
ppvenv init
```
  - Init takes no arguments and simply sets up a python virtual environment with a call to ```python -m venv .venv```.
  - Init sets up a requirements.txt file in the same directory that the .venv dir can be found, if it does not already exist.

```
ppvenv run [file_name]
```
  - Run only takes one argument and runs the file using the virtual environment made by ```init```.

```
ppvenv add [module_name(==, >=, <=)version]
```
  - Add appends a module into requirements, there is no error checking.

```
ppvenv sync
```
  - Sync installs the requirements.txt contents if they have not been already.
