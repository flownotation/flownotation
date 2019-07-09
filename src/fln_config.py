
old = False
if old:
    READ_NAME = "read"
    READ_NAME_S = "read"
    READP_NAME = "read_ptr"
    READP_NAME_S = "read_ptr"
    WRITE_NAME = "write"
    WRITE_NAME_S = "write"
    WRITEP_NAME = "write_ptr"
    WRITEP_NAME_S = "write_ptr"
    PROJ0_NAME = "r"
    PROJ1_NAME = "w"
    PROJB_NAME = "b"
else:
    READ_NAME = "secrecy"
    READ_NAME_S = "sec"
    READP_NAME = "sec_ptr"
    READP_NAME_S = "sec_ptr"
    WRITE_NAME = "integrity"
    WRITE_NAME_S = "intg"
    WRITEP_NAME = "intg_ptr"
    WRITEP_NAME_S = "intg_ptr"
    PROJ0_NAME = "S"
    PROJ1_NAME = "I"
    PROJB_NAME = "B"

GEN_READ_NAME = "_" + READ_NAME_S
GEN_READP_NAME = "_" + READP_NAME_S
GEN_WRITE_NAME = "_" + WRITE_NAME_S
GEN_WRITEP_NAME = "_" + WRITEP_NAME_S
GEN_PROJ0_NAME = "_" + PROJ0_NAME
GEN_PROJ1_NAME = "_" + PROJ1_NAME
GEN_PROJB_NAME = "_" + PROJB_NAME
