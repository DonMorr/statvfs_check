
#include <sys/statvfs.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char *argv[]    )
{

    int errors = 0;
    char *myname;
    struct statvfs vfs;
    char * path = "/media/datammc";

    if( argc == 2 ) {
              printf("statvfs'ing %s\n", argv[1]);
        path = argv[1];    
    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
        return 1;
    }
    else {
        printf("Please specify the path to any file within the mounted filesystem\n");
        return 1;    
    }

    if (statvfs(path, & vfs) != 0) {
        fprintf(stderr, "%s: %s: statfs failed: %s\n",
            myname, path, strerror(errno));
        errors++;
        return 1;
    }

    printf("\tf_bsize: %ld\n", vfs.f_bsize);
    printf("\tf_blocks: %ld\n", vfs.f_blocks);
    printf("\tf_bfree: %ld\n", vfs.f_bfree);
    printf("\tf_bavail: %ld\n", vfs.f_bavail);
    printf("\tf_files: %ld\n", vfs.f_files);
    printf("\tf_ffree: %ld\n", vfs.f_ffree);
    printf("\tf_favail: %ld\n", vfs.f_favail);
    return 0;
}

