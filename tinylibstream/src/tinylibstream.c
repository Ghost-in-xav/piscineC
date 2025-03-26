
/////////////////////////////////////////////////////////////////////////////
//////////////////////////INCLUDE////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./../include/libstream.h"

/////////////////////////////////////////////////////////////////////////////
//////////////////////////F_OPEN/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

static struct stream *lbs_flags(struct stream *res, const char *mode)
{
    if (strcmp(mode, "r") == 0)
    {
        res->flags = O_RDONLY;
        res->io_operation = STREAM_READING;
    }
    else if (strcmp(mode, "r+") == 0)
    {
        res->flags = O_RDWR;
        res->io_operation = STREAM_READING;
    }
    else if (strcmp(mode, "w") == 0)
    {
        res->flags = O_WRONLY | O_CREAT | O_TRUNC;
    }

    else if (strcmp(mode, "w+") == 0)
    {
        res->flags = O_RDWR | O_CREAT | O_TRUNC;
        res->io_operation = STREAM_READING;
    }
    else
    {
        res->error = -1;
        res->flags = 0;
    }
    return res;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    if (path == NULL)
        return NULL;

    int flag_temp;

    if (strcmp(mode, "r") == 0)
        flag_temp = O_RDONLY;
    else if (strcmp(mode, "r+") == 0)
        flag_temp = O_RDWR;
    else if (strcmp(mode, "w") == 0)
    {
        flag_temp = O_WRONLY | O_CREAT | O_TRUNC;
    }
    else if (strcmp(mode, "w+") == 0)
        flag_temp = O_RDWR | O_CREAT | O_TRUNC;
    else
        return NULL;

    /////FLAGS OK////////FILE DESCRIPTOR//////
    int fd_temp = open(path, flag_temp);

    /////ERREUR OPEN//////
    if (fd_temp < 0)
        return NULL;

    /////NO ERROR OCCURED////
    return lbs_fdopen(fd_temp, mode);
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////FD_OPEN////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

struct stream *lbs_fdopen(int fd, const char *mode)
{
    //////////////////INVALID FILE DESCRIPTOR//////////
    if (fd < 0)
        return NULL;

    struct stream *new_open = malloc(sizeof(struct stream));
    if (new_open == NULL)
        return NULL;

    //////////INITIALISATION DES VALUES PAR DEFAUT/////////
    new_open->error = 0;
    new_open->fd = fd;
    new_open->buffering_mode = STREAM_BUFFERED;
    new_open->buffered_size = 0;
    new_open->already_read = 0;

    ///////////////RECUPERATION DES FLAGS//////////////
    new_open = lbs_flags(new_open, mode);

    /////WRONG FLAGS///////
    if (new_open->error == -1)
    {
        free(new_open);
        return NULL;
    }

    /////NO ERROR OCCURED////
    return new_open;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////FFLUSH///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int lbs_fflush(struct stream *stream)
{
    if (stream == NULL)
        return LBS_EOF;

    int fail = 0;
    if (stream->io_operation == STREAM_READING)
    {
        /////case reading
        ///////les donnes sont ecraser ////////

        if (stream->already_read != stream->buffered_size)
            lseek(stream->fd, -stream_remaining_buffered(stream), SEEK_CUR);
        stream->buffered_size = 0;
        stream->already_read = 0;
    }

    if (stream->io_operation == STREAM_WRITING)
    {
        fail = write(stream->fd, stream->buffer, stream->buffered_size);
        if (fail == -1)
        {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->already_read = 0;
        stream->buffered_size = 0;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////FCLOSE///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int lbs_fclose(struct stream *stream)
{
    if (stream == NULL)
        return LBS_EOF;

    lbs_fflush(stream);
    int fail = close(stream->fd);
    if (fail == -1)
    {
        stream->error = 1;
        return LBS_EOF;
    }
    free(stream);
    return fail;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////FPUTC////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int lbs_fputc(int c, struct stream *stream)
{
    if (stream == NULL)
        return LBS_EOF;

    //////si le fichier n'es pas en mode ecriture close////
    if (stream_writable(stream) == false)
    {
        stream->error = 1;
        return LBS_EOF;
    }

    ///////////////passage en writing si reading et sinon reste en
    /// writing//////////////
    if (stream->io_operation == STREAM_READING)
        lbs_fflush(stream);
    stream->io_operation = STREAM_WRITING;

    ///////recuperation du charactere////
    unsigned char lettre = c;
    stream->buffer[stream->buffered_size] = lettre;
    stream->buffered_size++;

    ////////////////////////flush ou pas en fonction /////////////////

    if (stream_unused_buffer_space(stream) == 0)
        lbs_fflush(stream);

    if (stream->buffering_mode == STREAM_UNBUFFERED)
        lbs_fflush(stream);

    else if (stream->buffering_mode == STREAM_LINE_BUFFERED && lettre == '\n')
        lbs_fflush(stream);

    return lettre;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////FGETC////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int lbs_fgetc(struct stream *stream)
{
    if (stream == NULL)
        return LBS_EOF;

    //////si le fichier n'es pas en mode lecture close////
    if (stream_readable(stream) == false)
    {
        stream->error = 1;
        return LBS_EOF;
    }

    if (stream->io_operation == STREAM_WRITING)
        lbs_fflush(stream);
    stream->io_operation = STREAM_READING;

    /////si vide on refill///////
    if (stream_remaining_buffered(stream) == 0)
    {
        lbs_fflush(stream);

        int fail = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        stream->buffered_size = fail;
        if (fail <= 0)
        {
            stream->error = -666;
            return LBS_EOF;
        }
        stream->already_read = 0;
    }

    unsigned char lettre = stream->buffer[stream->already_read];
    stream->already_read++;
    return lettre;
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////////END////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
