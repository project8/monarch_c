#include "monarch.h"

size_t _monarch_read_magic(monarch_fd* tgt) {
  size_t res = 0;
  FILE* _ptr = NULL;
  if(tgt && (_ptr = tgt->_raw_fd)) {
    if( fseek(_ptr, 0, SEEK_SET) != 0) {
      fprintf(stderr, "oh no... seek error.  couldn't read magic bytes!\n");
    }
    else {
      if( fread(&res, sizeof(res), 1, _ptr) != 1 ) {
	fprintf(stderr, "prelude read error.  this read is a little sloppy.\n");
      }
    }
  }
  return res;
}

int _monarch_parse_hdr(monarch_fd* tgt)
{
  int _hdr_size = 0;
  int res = -1;
  if( (_hdr_size = _monarch_read_magic(tgt)) > 0 ) {
    uint8_t _header_buf[_hdr_size];
    fread(_header_buf, sizeof(char), _hdr_size, tgt->_raw_fd);
    tgt->_header = monarch_pb__monarch_header__unpack(NULL, 
						      _hdr_size, 
						      _header_buf);
    res = 0;
  }
  return res;
}

monarch_fd* _monarch_open_read(const char* filename) {
  FILE* _fd = NULL;
  monarch_fd* res = NULL;
  if( (_fd = fopen(filename, "rb")) != NULL ) {
    res = (monarch_fd*)malloc(sizeof(monarch_fd));
    res->_raw_fd = _fd;
    res->_file_mode = read_mode;
    if( _monarch_parse_hdr(res) != 0 ) {
      fprintf(stderr, "couldn't parse header for file %s!\n", filename);
      monarch_close(res);
      res = NULL;
    }
  }
  return res;
}

monarch_fd* _monarch_open_write(const char* filename) {
}

monarch_fd* monarch_open(const char* filename, monarch_io_mode mode) 
{
  monarch_fd* res = NULL;
  switch(mode) {
  case read_mode:
    res = _monarch_open_read(filename);
    break;
  case write_mode:
    res = _monarch_open_write(filename);
    break;
  }
  return res;
}

int monarch_close(monarch_fd* fd)
{
  int res = -1;
  if(fd) {
    fclose(fd->_raw_fd);
    res = 0;
  }
  return res;
}

monarch_record* monarch_new_record_alloc(unsigned data_len)
{
  void* _mem = malloc(sizeof(acq_id_type) 
		      + sizeof(rec_id_type) 
		      + sizeof(clock_type)
		      + data_len*sizeof(data_type));
  return (monarch_record*)(_mem);
}

int monarch_destroy_record(monarch_record* tgt)
{
  int res = -1;
  if(tgt) {
    free(tgt->_data_ptr);
    free(tgt);
    res = 0;
  }
  return res;
}

size_t monarch_record_len(monarch_fd* fd)
{
  size_t res = 0;
  if(fd && fd->_header) {
    res = fd->_header->recsize;
  }
  return res;
}

int monarch_read_next_record(monarch_fd* fd, monarch_record* dest)
{
  int res = 0;

  // should cache this...
  size_t recsize = sizeof(acq_id_type) 
    + sizeof(rec_id_type)
    + sizeof(clock_type)
    + monarch_record_len(fd)*sizeof(data_type);
  int nread = fread(dest, recsize, 1, fd->_raw_fd);
  if( nread != 1 ) {
    if( feof(fd->_raw_fd) != 0 ) res = -1;
    else if( ferror(fd->_raw_fd) != 0 ) {
      fprintf(stderr, "file read error while processing file!\n");
      res = -2;
    }
  }
  return res;
}

int monarch_n_channels(monarch_fd* fd)
{
  return fd->_header->acqmode;
}

data_type* monarch_record_data(monarch_record* rec)
{
  return rec->_data_ptr;
}
