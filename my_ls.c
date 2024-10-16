#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>

#define INITIAL_PATH_SIZE 256
#define DT_DIR_VALUE 4

void PrintFileInformation(const char *directoryName, struct dirent *directoryEntry, int showHiddenFiles, int displayLongList) {
    if (!showHiddenFiles && directoryEntry->d_name[0] == '.') {
        return;
    }

    if (displayLongList) {
        char *filePath = (char *)malloc(INITIAL_PATH_SIZE * sizeof(char));
        size_t pathSize = INITIAL_PATH_SIZE;

        while (snprintf(filePath, pathSize, "%s/%s", directoryName, directoryEntry->d_name) >= pathSize) {
            pathSize *= 2;
            filePath = (char *)realloc(filePath, pathSize * sizeof(char));
        }

        struct stat fileStatus;
        if (stat(filePath, &fileStatus) == -1) {
            perror("stat");
            free(filePath);
            return;
        }

        printf((S_ISDIR(fileStatus.st_mode)) ? "d" : "-");
        printf((fileStatus.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStatus.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStatus.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStatus.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStatus.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStatus.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStatus.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStatus.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStatus.st_mode & S_IXOTH) ? "x" : "-");

        struct passwd *password = getpwuid(fileStatus.st_uid);
        struct group *group = getgrgid(fileStatus.st_gid);

        printf(" %ld %s %s %ld ", fileStatus.st_nlink, password->pw_name, group->gr_name, fileStatus.st_size);

        char timeBuffer[80];
        struct tm *timeInformation = localtime(&fileStatus.st_mtime);
        strftime(timeBuffer, sizeof(timeBuffer), "%b %d %H:%M", timeInformation);
        printf("%s ", timeBuffer);

        free(filePath);
    }

    printf("%s\n", directoryEntry->d_name);
}

void ListFilesInDirectory(const char *directory, int showHiddenFiles, int displayLongList, int performRecursiveSearch) {
    struct dirent *directoryEntry;
    DIR *directoryPointer;

    directoryPointer = opendir(directory);
    if (directoryPointer == NULL) {
        perror("opendir");
        return;
    }

    while ((directoryEntry = readdir(directoryPointer)) != NULL) {
        PrintFileInformation(directory, directoryEntry, showHiddenFiles, displayLongList);
    }

    if (performRecursiveSearch) {
        rewinddir(directoryPointer);

        while ((directoryEntry = readdir(directoryPointer)) != NULL) {
            if (directoryEntry->d_type != DT_DIR_VALUE || strcmp(directoryEntry->d_name, ".") == 0 || strcmp(directoryEntry->d_name, "..") == 0) {
                continue;
            }

            char *nextDirectory = (char *)malloc(INITIAL_PATH_SIZE * sizeof(char));
            size_t pathSize = INITIAL_PATH_SIZE;

            while (snprintf(nextDirectory, pathSize, "%s/%s", directory, directoryEntry->d_name) >= pathSize) {
                pathSize *= 2;
                nextDirectory = (char *)realloc(nextDirectory, pathSize * sizeof(char));
            }

            printf("\n%s:\n", nextDirectory);
            ListFilesInDirectory(nextDirectory, showHiddenFiles, displayLongList, performRecursiveSearch);

            free(nextDirectory);
        }
    }

    closedir(directoryPointer);
}

int main(int argumentCount, char *argumentValues[]) {
    int showHiddenFiles = 0;
    int displayLongList = 0;
    int performRecursiveSearch = 0;

    const char *directory = ".";

    for (int i = 1; i < argumentCount; i++) {
        if (argumentValues[i][0] == '-') {
            for (int j = 1; argumentValues[i][j] != '\0'; j++) {
                switch (argumentValues[i][j]) {
                    case 'a': showHiddenFiles = 1; break;
                    case 'l': displayLongList = 1; break;
                    case 'R': performRecursiveSearch = 1; break;
                    default:
                        printf("Unknown option: %c\n", argumentValues[i][j]);
                        return EXIT_FAILURE;
                }
            }
        } else {
            directory = argumentValues[i];
        }
    }

    ListFilesInDirectory(directory, showHiddenFiles, displayLongList, performRecursiveSearch);

    return EXIT_SUCCESS;
}
