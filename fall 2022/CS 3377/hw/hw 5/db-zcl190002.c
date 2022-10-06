/*
        Written by Zach Leach for CS 3377.004 on 9/28/2022
        NetID: zcl190002
*/

#include <stdio.h>     // for sscanf, fprintf, perror
#include <stdint.h>    // for int32_t
#include <assert.h>    // for assert
#include "sr.h"
// add include files
#include <fcntl.h>      // for open, O_RDONLY
#include <unistd.h>     // for read, close, lseek
#include <stdlib.h>     // for malloc, exit, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>     // for strlen()


/**
 * sets the file pointer to index * sizeof(sr).
 */
static void setFilePtr(int fd, int index) {
        lseek(fd, index * sizeof(sr), SEEK_SET);
}

/**
 * writes the given record to the file at it's specified index.
 */
static int writeRecord(int fd, sr* recordPtr) {
        setFilePtr(fd, recordPtr->index);
        return write(fd, recordPtr, sizeof(*recordPtr));
}

/**
 * reads the record index' many sr' from the start of the file to the the record pointed to by recordPtr.
 */
static int readRecord(int fd, sr* recordPtr, int index) {
        setFilePtr(fd, index);
        return read(fd, recordPtr, sizeof(*recordPtr));
}

/**
 * prompts the user for record information then writes it to the specified file.
 */
void put(int32_t fd) {
        // read name
        printf("Enter the student name: "); 
        sr s; 
        fgets(s.name, MAX_NAME_LENGTH, stdin);
        
        // replace '\n' with '\0' from name
        int nameLen = strlen(s.name);
        s.name[nameLen - 1] = '\0';
        
        // read id 
        printf("Enter the student id: ");
        scanf("%d", &s.sid);
        
        // read index
        printf("Enter the record index: ");
        scanf("%d", &s.index);
        
        // write the record
	writeRecord(fd, &s);
}

/**
 * prompts the user for a record index in the given file,
 * reads the record at that index,
 * then prints the contents of that record.
 */
void get(int32_t fd) {
        sr s;
        int32_t index;
        
        // read index
        printf("Enter the record index: ");
        scanf("%d", &index);
        
        // read record
        int read = readRecord(fd, &s, index);
        
        // if read fails
        if (read == 0) {
                printf("ERROR: Get read failed.\n");
                return;
        }
        
        // if record not put yet (first element of name is nullptr)
        if (s.name[0] == '\0') {
                printf("ERROR: Index not in database.\n");
                return;
        }
        
        // professor code below
        printf("Student name %s \n", s.name);
        printf("Student id: %d \n", s.sid);
        printf("Record index: %d \n", s.index);
        assert(index == s.index);
}