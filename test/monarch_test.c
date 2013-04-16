#include "monarch.h"

int main() {
  // read verify.egg test.
  monarch_fd* test = monarch_open("verify.egg", read_mode);
  if(test) {
    printf("testing verify.egg to make sure library works.\n");
    size_t reclen = monarch_record_len(test);
    printf("i see records are %ld elements long.\n", reclen);
    monarch_record* rec = monarch_new_record_alloc(reclen);
    rec_id_type id = 0;

    // first verify that we can correctly read record id#s and that
    // the bytes we read are correct.
    while( monarch_read_next_record(test, rec) == 0 ) {
      printf("rec_id: %ld == %ld", rec->_r_id, id);
      assert(rec->_r_id == (id));
      printf(" OK\n");

      printf("rec byte 0: %hhd == %ld", (rec->_data_ptr)[0], id);
      assert((rec->_data_ptr)[0] == (char)id);
      printf(" OK\n");
      id++;
    }

    monarch_close(test);
  }
  else {
    fprintf(stderr, "failed to open verify.egg!  do you have the file?\n");
  }

  // write and readback test.

  return 0;
}
