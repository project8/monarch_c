module Monarch
using Base

export open, close

const EOF = -1

type monarch
    _c_handle :: Ptr{Void}
    recsize :: Int64
    nrecs :: Int32
    _rec_hndl :: Ptr{Void}
end

function open(fname::String)
    H = __open(fname)
    if H == C_NULL
        error("couldn't open for reading!")
    end

    R = __rec_len(H)
    Rec = __new_record(R)
    NR = __n_channels(H)
    monarch(H, R, NR, Rec)
end

function close(file::monarch)
    R = __close(file._c_handle)
    R
end

function next_record(handle::monarch)
    R = __next_record(handle._c_handle, handle._rec_hndl)
    if R == 0
        Ktemp = pointer_to_array(Monarch.__record_data_ptr(handle._rec_hndl),
                                 (handle.recsize, 1), false)
        if handle.nrecs == 2
            K = [sub(Ktemp,1:2:handle.recsize) sub(Ktemp,2:2:handle.recsize)]
        else
            K = Ktemp
        end
    else
        K = EOF
    end
    K
end

function __open(fname::String)
    ccall((:monarch_open,"libmonarch"),
          Ptr{Void},
          (Ptr{Uint8},Int),
          bytestring(fname),0)
end

function __close(handle::Ptr{Void})
    ccall((:monarch_close, "libmonarch"),
          Int32,
          (Ptr{Void},),
          handle)
end

function __rec_len(handle::Ptr{Void})
    ccall((:monarch_record_len,"libmonarch"),
          Int64,
          (Ptr{Void},),
          handle)
end

function __new_record(recsize)
    ccall((:monarch_new_record_alloc, "libmonarch"),
          Ptr{Void},
          (Int32,),
          recsize)
end

function __next_record(handle::Ptr{Void}, data::Ptr{Void})
    ccall((:monarch_read_next_record, "libmonarch"),
          Int32,
          (Ptr{Void},Ptr{Void}),
          handle,
          data)
end

function __record_data_ptr(record::Ptr{Void})
    ccall((:monarch_record_data, "libmonarch"),
          Ptr{Uint8},
          (Ptr{Void},),
          record)
end

function __n_channels(handle::Ptr{Void})
    ccall((:monarch_n_channels, "libmonarch"),
          Int32,
          (Ptr{Void},),
          handle)
end

end