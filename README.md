# statvfs_check
Stand alone c program for running statvfs on a filesystem

Useful for embedded systems where not all df options are available. E.g. when the df -i inode option has not been configured in Busybox.

## Compilation
To compile, simply run one of the following depending if you are cross or native compiling:
* gcc statvfs_check.c -o statvfs_check
* arm-linux-gnueabihf-gcc statfs_check.c -o statfs_check

## To run
./statfs_check /media/file_system_to_check

## Example Output
The following is example of the command being run on a mounted MMC partition: 
```
# ~/statfs_check /media/mounted_fs/
statvfs'ing /media/mounted_fs/
        f_bsize: 1024
        f_blocks: 7344362
        f_bfree: 6457929
        f_bavail: 6072957
        f_files: 1904640
        f_ffree: 1104044
        f_favail: 1104044
```
