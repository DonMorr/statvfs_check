# statvfs_check
Stand alone c program for running statvfs on a filesystem

Useful for embedded systems where not all df options are available. E.g. when the df -i inode option has not been configured in Busybox.
