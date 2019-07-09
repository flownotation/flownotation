#include "../../src/pycparser/utils/fake_libc_include/stdint.h"
#include "../../src/pycparser/utils/fake_libc_include/string.h"

#include "openpgp-do_snip__fln.h"

#define SIZE_OF_KDF_DO_MIN 90
#define SIZE_OF_KDF_DO_MAX 110
#define OPENPGP_KDF_ITERSALTED_S2K 3
#define OPENPGP_SHA256 8

#define GPG_DO_KDF 1
#define NR_DO_KDF 1
#define NR_DO_PRVKEY_SIG 1
#define NR_DO_PRVKEY_DEC 1
#define NR_DO_PRVKEY_AUT 1
#define NR_DO_KEYSTRING_PW1 1
#define NR_DO_KEYSTRING_RC 1
#define NR_DO_KEYSTRING_PW3 1
#define NR_DO__LAST__ 1

static uint8_t *res_p;
static const uint8_t *do_ptr[NR_DO__LAST__];

static void copy_tag(uint16_t tag) { return; }
void flash_do_release(const uint8_t *do_data) { return; }
void gpg_do_write_simple(uint8_t nr, const uint8_t *data, int size) { return; }
void ac_reset_admin(void) { return; }
void ac_reset_pso_cds(void) { return; }
void ac_reset_other(void) { return; }
const uint8_t *flash_do_write(uint8_t nr, const uint8_t *data, int len) { return data; }

// ---- NEW FLN helper function for memcpy [2]
int assign_len(int old, int new)
{
if (new >= 0)
{
old = new;
}
else
{
return 0;
}
}

// Param 2: Main bug fix [1]
static void copy_do_1(uint16_t tag, const uint8_t *do_data, int with_tag)
{
int len__fln_0;

if (with_tag)
{
copy_tag(tag);

if (do_data[0] >= 128)
*res_p++ = 0x81;

// --- Original ---
// len = do_data[0] + 1;
// --- FLN fix ----
int tmp = do_data[0] + 1;
len = assign_len(len, tmp);
//      - Assigned length must be positive
// ----------------
}
else
{
// --- Original ---
// len = do_data[0];
// --- FLN fix ----
int tmp = do_data[0];
len = assign_len(len, tmp);
//      - Assigned length must be positive
// ----------------
do_data++;
}

memcpy(res_p, do_data, len);
res_p += len;
}

// ---- NEW FLN helper function for main bug fix [1]
const uint8_t *check_do_ptr(const uint8_t *do_ptr)
{
if (do_ptr)
{
return do_ptr;
}
else
{
return 0;
}
}

// --- NEW FLN helper function for sequencing invariant [3]
int check_prvkey_sig(int no_key_invar, uint8_t prvkey_sig)
{
if (prvkey_sig)
{
return 0;
}
else
{
return no_key_invar;
}
}
// --- NEW FLN helper function for sequencing invariant [3]
int check_prvkey_dec(int no_key_invar, uint8_t prvkey_dec)
{
if (prvkey_dec)
{
return 0;
}
else
{
return no_key_invar;
}
}
// --- NEW FLN helper function for sequencing invariant [3]
int check_prvkey_aut(int no_key_invar, uint8_t prvkey_aut)
{
if (prvkey_aut)
{
return 0;
}
else
{
return no_key_invar;
}
}
// --- NEW FLN helper function for sequencing invariant [3]
int prvkey_aut_to_bool(int no_key_invar)
{
if (no_key_invar)
{
return 0;
}
else
{
return 1;
}
}

static int rw_kdf(uint16_t tag, int with_tag, const uint8_t *data, int len, int is_write)
{
if (tag != GPG_DO_KDF)
return 0; /* Failure */

if (is_write)
{
const uint8_t **do_data_p = (const uint8_t **)&do_ptr[NR_DO_KDF];

/* KDF DO can be changed only when no keys are registered.  */
// --- Original ---
// if (do_ptr[NR_DO_PRVKEY_SIG] || do_ptr[NR_DO_PRVKEY_DEC] || do_ptr[NR_DO_PRVKEY_AUT])
//     return 0;
// --- FLN Fix ----
int no_key_invar__fln_1;
if (prvkey_aut_to_bool(check_prvkey_aut(check_prvkey_dec(check_prvkey_sig(no_key_invar,do_ptr[NR_DO_PRVKEY_SIG]),do_ptr[NR_DO_PRVKEY_DEC]),do_ptr[NR_DO_PRVKEY_AUT])))
{

}
else
{
return 0;
}
// -----------------

/* The valid data format is:
Deleting:
nothing
Minimum (for admin-less):
81 01 03 = KDF_ITERSALTED_S2K
82 01 08 = SHA256
83 04 4-byte... = count
84 08 8-byte... = salt
87 20 32-byte user hash
88 20 32-byte admin hash
Full:
81 01 03 = KDF_ITERSALTED_S2K
82 01 08 = SHA256
83 04 4-byte... = count
84 08 8-byte... = salt user
85 08 8-byte... = salt reset-code
86 08 8-byte... = salt admin
87 20 32-byte user hash
88 20 32-byte admin hash
*/
if (!(len == 0 || (len == SIZE_OF_KDF_DO_MIN && (data[0] == 0x81 && data[3] == 0x82 && data[6] == 0x83 && data[12] == 0x84 && data[22] == 0x87 && data[56] == 0x88)) || (len == SIZE_OF_KDF_DO_MAX && (data[0] == 0x81 && data[3] == 0x82 && data[6] == 0x83 && data[12] == 0x84 && data[22] == 0x85 && data[32] == 0x86 && data[42] == 0x87 && data[76] == 0x88))))
return 0;

if (*do_data_p)
flash_do_release(*do_data_p);

/* Clear all keystrings and auth states */
gpg_do_write_simple(NR_DO_KEYSTRING_PW1, NULL, 0);
gpg_do_write_simple(NR_DO_KEYSTRING_RC, NULL, 0);
gpg_do_write_simple(NR_DO_KEYSTRING_PW3, NULL, 0);
ac_reset_admin();
ac_reset_pso_cds();
ac_reset_other();

if (len == 0)
{
*do_data_p = NULL;
return 1;
}
else
{
*do_data_p = flash_do_write(NR_DO_KDF, data, len);
if (*do_data_p)
return 1;
else
return 0;
}
}
else
{
// ---------- Original -------------
// copy_do_1(tag, do_ptr[NR_DO_KDF], with_tag);
// ---------- FLN fix --------------
copy_do_1(tag, check_do_ptr(do_ptr[NR_DO_KDF]), with_tag);
//     - check_do_ptr fulfills the policy on copy_do_1
//     - "#param(2) check_valid_ptr:integrity"
//     - Ref: [1]
// -------- Official patch ---------
// if (do_ptr[NR_DO_KDF])
//     copy_do_1(tag, do_ptr[NR_DO_KDF], with_tag);
// else
//     return 0;

return 1;
}
}

int main()
{
return 0;
}
