#ifndef __monarch_h
#define __monarch_h

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "MonarchHeader.pb-c.h"

// io modes
typedef enum {
  read_mode = 0,
  write_mode = 1
} monarch_io_mode;

// the monarch_fd structure encapsulates all of the monarch file data
typedef struct {
  monarch_io_mode _file_mode;
  FILE* _raw_fd;
  struct _MonarchPB__MonarchHeader* _header;
} monarch_fd;

// monarch record
typedef unsigned long int acq_id_type;
typedef unsigned long int rec_id_type;
typedef clock_t clock_type;
typedef unsigned char data_type;

typedef struct {
  acq_id_type _a_id;
  rec_id_type _r_id;
  clock_type  _tick;
  data_type _data_ptr[];
} monarch_record;

// open and close
monarch_fd* monarch_open(const char* filename, monarch_io_mode mode);
int monarch_close(monarch_fd* fd);

// safely allocate memory for a new record
monarch_record* monarch_new_record_alloc(unsigned data_len);
int monarch_destroy_record(monarch_record* tgt);

// get next record
int monarch_n_channels(monarch_fd* fd);
size_t monarch_record_len(monarch_fd* fd);
int monarch_read_next_record(monarch_fd* fd, monarch_record* dest);

// record accessors.
data_type* monarch_record_data(monarch_record* rec);

#endif //__monarch_h
