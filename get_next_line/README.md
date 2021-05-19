# Get Next Line

```C
int get_next_line(int fd, char **line);
```
Get next line takes as parameter a file descriptor and the address of a string. Each time the function is called, it will save the next line of text from the specified file in **line**. It will then return a different value depending on its state.
| Value | Meaning |
| --- | --- |
| `-1` | The function has encountered an error. Possible errors are : malloc error, ... |
| `0` | The line has been read and EOF  has been reached |
| `1` | The line has been read |
## Instalation
Before cloning this repo, please make sure that there are no files/folders called Cursus19 or get_next_line in the destination folder!!

If you want to use this library please run:
```
git clone https://github.com/TimourP/Cursus19.git Cursus19 && cp -r Cursus19/get_next_line ./ && rm -rf Cursus19
```
