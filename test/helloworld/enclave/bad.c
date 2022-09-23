/*
 * File auto generated for PopSGX, DO NOT EDIT.
 * Inquiries: bilbao at vt dot edu 
 */
#include "helloworld_t.h"

#include <execinfo.h>
#include <openenclave/edger8r/enclave.h>
OE_EXTERNC_BEGIN

/**** Trusted function IDs ****/
enum
{
    helloworld_fcn_id_enclave_helloworld = 0,
    helloworld_fcn_id_oe_get_sgx_report_ecall = 1,
    helloworld_fcn_id_oe_get_report_v2_ecall = 2,
    helloworld_fcn_id_oe_verify_local_report_ecall = 3,
    helloworld_fcn_id_oe_sgx_init_context_switchless_ecall = 4,
    helloworld_fcn_id_oe_sgx_switchless_enclave_worker_thread_ecall = 5,
    helloworld_fcn_id_trusted_call_id_max = OE_ENUM_MAX
};

/**** ECALL marshalling structs. ****/
typedef struct _enclave_helloworld_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
} enclave_helloworld_args_t;

typedef struct _oe_get_sgx_report_ecall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    void* opt_params;
    size_t opt_params_size;
    sgx_report_t* report;
} oe_get_sgx_report_ecall_args_t;

typedef struct _oe_get_report_v2_ecall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    uint32_t flags;
    void* opt_params;
    size_t opt_params_size;
    uint8_t** report_buffer;
    size_t* report_buffer_size;
} oe_get_report_v2_ecall_args_t;

typedef struct _oe_verify_local_report_ecall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    uint8_t* report;
    size_t report_size;
    oe_report_t* parsed_report;
} oe_verify_local_report_ecall_args_t;

typedef struct _oe_sgx_init_context_switchless_ecall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    oe_host_worker_context_t* host_worker_contexts;
    uint64_t num_host_workers;
} oe_sgx_init_context_switchless_ecall_args_t;

typedef struct _oe_sgx_switchless_enclave_worker_thread_ecall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_enclave_worker_context_t* context;
} oe_sgx_switchless_enclave_worker_thread_ecall_args_t;

/**** ECALL functions. ****/

static void ecall_enclave_helloworld(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    enclave_helloworld_args_t* _pargs_in = (enclave_helloworld_args_t*)input_buffer;
    enclave_helloworld_args_t* _pargs_out = (enclave_helloworld_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    /* There were no in nor in-out parameters. */

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    /* There were no out nor in-out parameters. */

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    enclave_helloworld(
    );

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

static void ecall_oe_get_sgx_report_ecall(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    oe_get_sgx_report_ecall_args_t* _pargs_in = (oe_get_sgx_report_ecall_args_t*)input_buffer;
    oe_get_sgx_report_ecall_args_t* _pargs_out = (oe_get_sgx_report_ecall_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    if (_pargs_in->opt_params)
        OE_SET_IN_POINTER(opt_params, 1, _pargs_in->opt_params_size, void*);

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    if (_pargs_in->report)
        OE_SET_OUT_POINTER(report, 1, sizeof(sgx_report_t), sgx_report_t*);

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    _pargs_out->oe_retval = oe_get_sgx_report_ecall(
        (const void*)_pargs_in->opt_params,
        _pargs_in->opt_params_size,
        _pargs_in->report);

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

static void ecall_oe_get_report_v2_ecall(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    oe_get_report_v2_ecall_args_t* _pargs_in = (oe_get_report_v2_ecall_args_t*)input_buffer;
    oe_get_report_v2_ecall_args_t* _pargs_out = (oe_get_report_v2_ecall_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    if (_pargs_in->opt_params)
        OE_SET_IN_POINTER(opt_params, 1, _pargs_in->opt_params_size, void*);

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    if (_pargs_in->report_buffer)
        OE_SET_OUT_POINTER(report_buffer, 1, sizeof(uint8_t*), uint8_t**);
    if (_pargs_in->report_buffer_size)
        OE_SET_OUT_POINTER(report_buffer_size, 1, sizeof(size_t), size_t*);

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    _pargs_out->oe_retval = oe_get_report_v2_ecall(
        _pargs_in->flags,
        (const void*)_pargs_in->opt_params,
        _pargs_in->opt_params_size,
        _pargs_in->report_buffer,
        _pargs_in->report_buffer_size);

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

static void ecall_oe_verify_local_report_ecall(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    oe_verify_local_report_ecall_args_t* _pargs_in = (oe_verify_local_report_ecall_args_t*)input_buffer;
    oe_verify_local_report_ecall_args_t* _pargs_out = (oe_verify_local_report_ecall_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    if (_pargs_in->report)
        OE_SET_IN_POINTER(report, 1, _pargs_in->report_size, uint8_t*);

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    if (_pargs_in->parsed_report)
        OE_SET_OUT_POINTER(parsed_report, 1, sizeof(oe_report_t), oe_report_t*);

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    _pargs_out->oe_retval = oe_verify_local_report_ecall(
        (const uint8_t*)_pargs_in->report,
        _pargs_in->report_size,
        _pargs_in->parsed_report);

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

static void ecall_oe_sgx_init_context_switchless_ecall(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    oe_sgx_init_context_switchless_ecall_args_t* _pargs_in = (oe_sgx_init_context_switchless_ecall_args_t*)input_buffer;
    oe_sgx_init_context_switchless_ecall_args_t* _pargs_out = (oe_sgx_init_context_switchless_ecall_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    /* There were no in nor in-out parameters. */

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    /* There were no out nor in-out parameters. */

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    _pargs_out->oe_retval = oe_sgx_init_context_switchless_ecall(
        _pargs_in->host_worker_contexts,
        _pargs_in->num_host_workers);

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

static void ecall_oe_sgx_switchless_enclave_worker_thread_ecall(
    uint8_t* input_buffer,
    size_t input_buffer_size,
    uint8_t* output_buffer,
    size_t output_buffer_size,
    size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters. */
    oe_sgx_switchless_enclave_worker_thread_ecall_args_t* _pargs_in = (oe_sgx_switchless_enclave_worker_thread_ecall_args_t*)input_buffer;
    oe_sgx_switchless_enclave_worker_thread_ecall_args_t* _pargs_out = (oe_sgx_switchless_enclave_worker_thread_ecall_args_t*)output_buffer;

    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    if (input_buffer_size < sizeof(*_pargs_in) || output_buffer_size < sizeof(*_pargs_in))
        goto done;

    /* Make sure input and output buffers lie within the enclave. */
    /* oe_is_within_enclave explicitly checks if buffers are null or not. */
    if (!oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers. */
    /* There were no in nor in-out parameters. */

    /* Set out and in-out pointers. */
    /* In-out parameters are copied to output buffer. */
    /* There were no out nor in-out parameters. */

    /* Check that in/in-out strings are null terminated. */
    /* There were no in nor in-out string parameters. */

    /* lfence after checks. */
    oe_lfence();

    /* Call user function. */
    oe_sgx_switchless_enclave_worker_thread_ecall(
        _pargs_in->context);

    /* There is no deep-copyable out parameter. */
    _pargs_out->deepcopy_out_buffer = NULL;
    _pargs_out->deepcopy_out_buffer_size = 0;

    /* Success. */
    _result = OE_OK;
    *output_bytes_written = _output_buffer_offset;

done:
    if (output_buffer_size >= sizeof(*_pargs_out) &&
        oe_is_within_enclave(_pargs_out, output_buffer_size))
        _pargs_out->oe_result = _result;
}

/**** ECALL function table. ****/

oe_ecall_func_t oe_ecalls_table[] = {
    (oe_ecall_func_t) ecall_enclave_helloworld,
    (oe_ecall_func_t) ecall_oe_get_sgx_report_ecall,
    (oe_ecall_func_t) ecall_oe_get_report_v2_ecall,
    (oe_ecall_func_t) ecall_oe_verify_local_report_ecall,
    (oe_ecall_func_t) ecall_oe_sgx_init_context_switchless_ecall,
    (oe_ecall_func_t) ecall_oe_sgx_switchless_enclave_worker_thread_ecall
};

size_t oe_ecalls_table_size = OE_COUNTOF(oe_ecalls_table);

/**** Untrusted function IDs. ****/
enum
{
    helloworld_fcn_id_host_helloworld = 0,
    helloworld_fcn_id_oe_syscall_epoll_create1_ocall = 1,
    helloworld_fcn_id_oe_syscall_epoll_wait_ocall = 2,
    helloworld_fcn_id_oe_syscall_epoll_wake_ocall = 3,
    helloworld_fcn_id_oe_syscall_epoll_ctl_ocall = 4,
    helloworld_fcn_id_oe_syscall_epoll_close_ocall = 5,
    helloworld_fcn_id_oe_syscall_open_ocall = 6,
    helloworld_fcn_id_oe_syscall_read_ocall = 7,
    helloworld_fcn_id_oe_syscall_write_ocall = 8,
    helloworld_fcn_id_oe_syscall_readv_ocall = 9,
    helloworld_fcn_id_oe_syscall_writev_ocall = 10,
    helloworld_fcn_id_oe_syscall_lseek_ocall = 11,
    helloworld_fcn_id_oe_syscall_pread_ocall = 12,
    helloworld_fcn_id_oe_syscall_pwrite_ocall = 13,
    helloworld_fcn_id_oe_syscall_close_ocall = 14,
    helloworld_fcn_id_oe_syscall_flock_ocall = 15,
    helloworld_fcn_id_oe_syscall_fsync_ocall = 16,
    helloworld_fcn_id_oe_syscall_fdatasync_ocall = 17,
    helloworld_fcn_id_oe_syscall_dup_ocall = 18,
    helloworld_fcn_id_oe_syscall_opendir_ocall = 19,
    helloworld_fcn_id_oe_syscall_readdir_ocall = 20,
    helloworld_fcn_id_oe_syscall_rewinddir_ocall = 21,
    helloworld_fcn_id_oe_syscall_closedir_ocall = 22,
    helloworld_fcn_id_oe_syscall_stat_ocall = 23,
    helloworld_fcn_id_oe_syscall_fstat_ocall = 24,
    helloworld_fcn_id_oe_syscall_access_ocall = 25,
    helloworld_fcn_id_oe_syscall_link_ocall = 26,
    helloworld_fcn_id_oe_syscall_unlink_ocall = 27,
    helloworld_fcn_id_oe_syscall_rename_ocall = 28,
    helloworld_fcn_id_oe_syscall_truncate_ocall = 29,
    helloworld_fcn_id_oe_syscall_ftruncate_ocall = 30,
    helloworld_fcn_id_oe_syscall_mkdir_ocall = 31,
    helloworld_fcn_id_oe_syscall_rmdir_ocall = 32,
    helloworld_fcn_id_oe_syscall_fcntl_ocall = 33,
    helloworld_fcn_id_oe_syscall_ioctl_ocall = 34,
    helloworld_fcn_id_oe_syscall_poll_ocall = 35,
    helloworld_fcn_id_oe_syscall_kill_ocall = 36,
    helloworld_fcn_id_oe_syscall_close_socket_ocall = 37,
    helloworld_fcn_id_oe_syscall_socket_ocall = 38,
    helloworld_fcn_id_oe_syscall_shutdown_sockets_device_ocall = 39,
    helloworld_fcn_id_oe_syscall_socketpair_ocall = 40,
    helloworld_fcn_id_oe_syscall_connect_ocall = 41,
    helloworld_fcn_id_oe_syscall_accept_ocall = 42,
    helloworld_fcn_id_oe_syscall_bind_ocall = 43,
    helloworld_fcn_id_oe_syscall_listen_ocall = 44,
    helloworld_fcn_id_oe_syscall_recvmsg_ocall = 45,
    helloworld_fcn_id_oe_syscall_sendmsg_ocall = 46,
    helloworld_fcn_id_oe_syscall_recv_ocall = 47,
    helloworld_fcn_id_oe_syscall_recvfrom_ocall = 48,
    helloworld_fcn_id_oe_syscall_send_ocall = 49,
    helloworld_fcn_id_oe_syscall_sendto_ocall = 50,
    helloworld_fcn_id_oe_syscall_recvv_ocall = 51,
    helloworld_fcn_id_oe_syscall_sendv_ocall = 52,
    helloworld_fcn_id_oe_syscall_shutdown_ocall = 53,
    helloworld_fcn_id_oe_syscall_setsockopt_ocall = 54,
    helloworld_fcn_id_oe_syscall_getsockopt_ocall = 55,
    helloworld_fcn_id_oe_syscall_getsockname_ocall = 56,
    helloworld_fcn_id_oe_syscall_getpeername_ocall = 57,
    helloworld_fcn_id_oe_syscall_getaddrinfo_open_ocall = 58,
    helloworld_fcn_id_oe_syscall_getaddrinfo_read_ocall = 59,
    helloworld_fcn_id_oe_syscall_getaddrinfo_close_ocall = 60,
    helloworld_fcn_id_oe_syscall_getnameinfo_ocall = 61,
    helloworld_fcn_id_oe_syscall_nanosleep_ocall = 62,
    helloworld_fcn_id_oe_syscall_clock_nanosleep_ocall = 63,
    helloworld_fcn_id_oe_syscall_getpid_ocall = 64,
    helloworld_fcn_id_oe_syscall_getppid_ocall = 65,
    helloworld_fcn_id_oe_syscall_getpgrp_ocall = 66,
    helloworld_fcn_id_oe_syscall_getuid_ocall = 67,
    helloworld_fcn_id_oe_syscall_geteuid_ocall = 68,
    helloworld_fcn_id_oe_syscall_getgid_ocall = 69,
    helloworld_fcn_id_oe_syscall_getegid_ocall = 70,
    helloworld_fcn_id_oe_syscall_getpgid_ocall = 71,
    helloworld_fcn_id_oe_syscall_getgroups_ocall = 72,
    helloworld_fcn_id_oe_syscall_uname_ocall = 73,
    helloworld_fcn_id_oe_get_supported_attester_format_ids_ocall = 74,
    helloworld_fcn_id_oe_get_qetarget_info_ocall = 75,
    helloworld_fcn_id_oe_get_quote_ocall = 76,
    helloworld_fcn_id_oe_get_quote_verification_collateral_ocall = 77,
    helloworld_fcn_id_oe_verify_quote_ocall = 78,
    helloworld_fcn_id_oe_sgx_get_cpuid_table_ocall = 79,
    helloworld_fcn_id_oe_sgx_backtrace_symbols_ocall = 80,
    helloworld_fcn_id_oe_sgx_thread_wake_wait_ocall = 81,
    helloworld_fcn_id_oe_sgx_wake_switchless_worker_ocall = 82,
    helloworld_fcn_id_oe_sgx_sleep_switchless_worker_ocall = 83,
    helloworld_fcn_id_untrusted_call_max = OE_ENUM_MAX
};

/**** OCALL marshalling structs. ****/
typedef struct _host_helloworld_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
} host_helloworld_args_t;

typedef struct _oe_syscall_epoll_create1_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_fd_t oe_retval;
    int flags;
    int ocall_errno;
} oe_syscall_epoll_create1_ocall_args_t;

typedef struct _oe_syscall_epoll_wait_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int64_t epfd;
    struct oe_epoll_event* events;
    unsigned int maxevents;
    int timeout;
    int ocall_errno;
} oe_syscall_epoll_wait_ocall_args_t;

typedef struct _oe_syscall_epoll_wake_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int ocall_errno;
} oe_syscall_epoll_wake_ocall_args_t;

typedef struct _oe_syscall_epoll_ctl_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int64_t epfd;
    int op;
    int64_t fd;
    struct oe_epoll_event* event;
    int ocall_errno;
} oe_syscall_epoll_ctl_ocall_args_t;

typedef struct _oe_syscall_epoll_close_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t epfd;
    int ocall_errno;
} oe_syscall_epoll_close_ocall_args_t;

typedef struct _oe_syscall_open_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_fd_t oe_retval;
    char* pathname;
    size_t pathname_len;
    int flags;
    oe_mode_t mode;
    int ocall_errno;
} oe_syscall_open_ocall_args_t;

typedef struct _oe_syscall_read_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* buf;
    size_t count;
    int ocall_errno;
} oe_syscall_read_ocall_args_t;

typedef struct _oe_syscall_write_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* buf;
    size_t count;
    int ocall_errno;
} oe_syscall_write_ocall_args_t;

typedef struct _oe_syscall_readv_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* iov_buf;
    int iovcnt;
    size_t iov_buf_size;
    int ocall_errno;
} oe_syscall_readv_ocall_args_t;

typedef struct _oe_syscall_writev_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* iov_buf;
    int iovcnt;
    size_t iov_buf_size;
    int ocall_errno;
} oe_syscall_writev_ocall_args_t;

typedef struct _oe_syscall_lseek_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_off_t oe_retval;
    oe_host_fd_t fd;
    oe_off_t offset;
    int whence;
    int ocall_errno;
} oe_syscall_lseek_ocall_args_t;

typedef struct _oe_syscall_pread_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* buf;
    size_t count;
    oe_off_t offset;
    int ocall_errno;
} oe_syscall_pread_ocall_args_t;

typedef struct _oe_syscall_pwrite_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* buf;
    size_t count;
    oe_off_t offset;
    int ocall_errno;
} oe_syscall_pwrite_ocall_args_t;

typedef struct _oe_syscall_close_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    int ocall_errno;
} oe_syscall_close_ocall_args_t;

typedef struct _oe_syscall_flock_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    int operation;
    int ocall_errno;
} oe_syscall_flock_ocall_args_t;

typedef struct _oe_syscall_fsync_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    int ocall_errno;
} oe_syscall_fsync_ocall_args_t;

typedef struct _oe_syscall_fdatasync_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    int ocall_errno;
} oe_syscall_fdatasync_ocall_args_t;

typedef struct _oe_syscall_dup_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_fd_t oe_retval;
    oe_host_fd_t oldfd;
    int ocall_errno;
} oe_syscall_dup_ocall_args_t;

typedef struct _oe_syscall_opendir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    uint64_t oe_retval;
    char* name;
    size_t name_len;
    int ocall_errno;
} oe_syscall_opendir_ocall_args_t;

typedef struct _oe_syscall_readdir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    uint64_t dirp;
    struct oe_dirent* entry;
    int ocall_errno;
} oe_syscall_readdir_ocall_args_t;

typedef struct _oe_syscall_rewinddir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    uint64_t dirp;
} oe_syscall_rewinddir_ocall_args_t;

typedef struct _oe_syscall_closedir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    uint64_t dirp;
    int ocall_errno;
} oe_syscall_closedir_ocall_args_t;

typedef struct _oe_syscall_stat_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* pathname;
    size_t pathname_len;
    struct oe_stat_t* buf;
    int ocall_errno;
} oe_syscall_stat_ocall_args_t;

typedef struct _oe_syscall_fstat_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    struct oe_stat_t* buf;
    int ocall_errno;
} oe_syscall_fstat_ocall_args_t;

typedef struct _oe_syscall_access_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* pathname;
    size_t pathname_len;
    int mode;
    int ocall_errno;
} oe_syscall_access_ocall_args_t;

typedef struct _oe_syscall_link_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* oldpath;
    size_t oldpath_len;
    char* newpath;
    size_t newpath_len;
    int ocall_errno;
} oe_syscall_link_ocall_args_t;

typedef struct _oe_syscall_unlink_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* pathname;
    size_t pathname_len;
    int ocall_errno;
} oe_syscall_unlink_ocall_args_t;

typedef struct _oe_syscall_rename_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* oldpath;
    size_t oldpath_len;
    char* newpath;
    size_t newpath_len;
    int ocall_errno;
} oe_syscall_rename_ocall_args_t;

typedef struct _oe_syscall_truncate_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* path;
    size_t path_len;
    oe_off_t length;
    int ocall_errno;
} oe_syscall_truncate_ocall_args_t;

typedef struct _oe_syscall_ftruncate_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    oe_off_t length;
    int ocall_errno;
} oe_syscall_ftruncate_ocall_args_t;

typedef struct _oe_syscall_mkdir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* pathname;
    size_t pathname_len;
    oe_mode_t mode;
    int ocall_errno;
} oe_syscall_mkdir_ocall_args_t;

typedef struct _oe_syscall_rmdir_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* pathname;
    size_t pathname_len;
    int ocall_errno;
} oe_syscall_rmdir_ocall_args_t;

typedef struct _oe_syscall_fcntl_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    int cmd;
    uint64_t arg;
    uint64_t argsize;
    void* argout;
    int ocall_errno;
} oe_syscall_fcntl_ocall_args_t;

typedef struct _oe_syscall_ioctl_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t fd;
    uint64_t request;
    uint64_t arg;
    uint64_t argsize;
    void* argout;
    int ocall_errno;
} oe_syscall_ioctl_ocall_args_t;

typedef struct _oe_syscall_poll_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    struct oe_host_pollfd* host_fds;
    oe_nfds_t nfds;
    int timeout;
    int ocall_errno;
} oe_syscall_poll_ocall_args_t;

typedef struct _oe_syscall_kill_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int pid;
    int signum;
    int ocall_errno;
} oe_syscall_kill_ocall_args_t;

typedef struct _oe_syscall_close_socket_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int ocall_errno;
} oe_syscall_close_socket_ocall_args_t;

typedef struct _oe_syscall_socket_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_fd_t oe_retval;
    int domain;
    int type;
    int protocol;
    int ocall_errno;
} oe_syscall_socket_ocall_args_t;

typedef struct _oe_syscall_shutdown_sockets_device_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int ocall_errno;
} oe_syscall_shutdown_sockets_device_ocall_args_t;

typedef struct _oe_syscall_socketpair_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int domain;
    int type;
    int protocol;
    oe_host_fd_t* sv;
    int ocall_errno;
} oe_syscall_socketpair_ocall_args_t;

typedef struct _oe_syscall_connect_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    struct oe_sockaddr* addr;
    oe_socklen_t addrlen;
    int ocall_errno;
} oe_syscall_connect_ocall_args_t;

typedef struct _oe_syscall_accept_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_fd_t oe_retval;
    oe_host_fd_t sockfd;
    struct oe_sockaddr* addr;
    oe_socklen_t addrlen_in;
    oe_socklen_t* addrlen_out;
    int ocall_errno;
} oe_syscall_accept_ocall_args_t;

typedef struct _oe_syscall_bind_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    struct oe_sockaddr* addr;
    oe_socklen_t addrlen;
    int ocall_errno;
} oe_syscall_bind_ocall_args_t;

typedef struct _oe_syscall_listen_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int backlog;
    int ocall_errno;
} oe_syscall_listen_ocall_args_t;

typedef struct _oe_syscall_recvmsg_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* msg_name;
    oe_socklen_t msg_namelen;
    oe_socklen_t* msg_namelen_out;
    void* msg_iov_buf;
    size_t msg_iovlen;
    size_t msg_iov_buf_size;
    void* msg_control;
    size_t msg_controllen;
    size_t* msg_controllen_out;
    int flags;
    int ocall_errno;
} oe_syscall_recvmsg_ocall_args_t;

typedef struct _oe_syscall_sendmsg_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* msg_name;
    oe_socklen_t msg_namelen;
    void* msg_iov_buf;
    size_t msg_iovlen;
    size_t msg_iov_buf_size;
    void* msg_control;
    size_t msg_controllen;
    int flags;
    int ocall_errno;
} oe_syscall_sendmsg_ocall_args_t;

typedef struct _oe_syscall_recv_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* buf;
    size_t len;
    int flags;
    int ocall_errno;
} oe_syscall_recv_ocall_args_t;

typedef struct _oe_syscall_recvfrom_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* buf;
    size_t len;
    int flags;
    struct oe_sockaddr* src_addr;
    oe_socklen_t addrlen_in;
    oe_socklen_t* addrlen_out;
    int ocall_errno;
} oe_syscall_recvfrom_ocall_args_t;

typedef struct _oe_syscall_send_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* buf;
    size_t len;
    int flags;
    int ocall_errno;
} oe_syscall_send_ocall_args_t;

typedef struct _oe_syscall_sendto_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t sockfd;
    void* buf;
    size_t len;
    int flags;
    struct oe_sockaddr* dest_addr;
    oe_socklen_t addrlen;
    int ocall_errno;
} oe_syscall_sendto_ocall_args_t;

typedef struct _oe_syscall_recvv_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* iov_buf;
    int iovcnt;
    size_t iov_buf_size;
    int ocall_errno;
} oe_syscall_recvv_ocall_args_t;

typedef struct _oe_syscall_sendv_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    ssize_t oe_retval;
    oe_host_fd_t fd;
    void* iov_buf;
    int iovcnt;
    size_t iov_buf_size;
    int ocall_errno;
} oe_syscall_sendv_ocall_args_t;

typedef struct _oe_syscall_shutdown_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int how;
    int ocall_errno;
} oe_syscall_shutdown_ocall_args_t;

typedef struct _oe_syscall_setsockopt_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int level;
    int optname;
    void* optval;
    oe_socklen_t optlen;
    int ocall_errno;
} oe_syscall_setsockopt_ocall_args_t;

typedef struct _oe_syscall_getsockopt_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    int level;
    int optname;
    void* optval;
    oe_socklen_t optlen_in;
    oe_socklen_t* optlen_out;
    int ocall_errno;
} oe_syscall_getsockopt_ocall_args_t;

typedef struct _oe_syscall_getsockname_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    struct oe_sockaddr* addr;
    oe_socklen_t addrlen_in;
    oe_socklen_t* addrlen_out;
    int ocall_errno;
} oe_syscall_getsockname_ocall_args_t;

typedef struct _oe_syscall_getpeername_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_host_fd_t sockfd;
    struct oe_sockaddr* addr;
    oe_socklen_t addrlen_in;
    oe_socklen_t* addrlen_out;
    int ocall_errno;
} oe_syscall_getpeername_ocall_args_t;

typedef struct _oe_syscall_getaddrinfo_open_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    char* node;
    size_t node_len;
    char* service;
    size_t service_len;
    struct oe_addrinfo* hints;
    uint64_t* handle;
    int ocall_errno;
} oe_syscall_getaddrinfo_open_ocall_args_t;

typedef struct _oe_syscall_getaddrinfo_read_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    uint64_t handle;
    int* ai_flags;
    int* ai_family;
    int* ai_socktype;
    int* ai_protocol;
    oe_socklen_t ai_addrlen_in;
    oe_socklen_t* ai_addrlen;
    struct oe_sockaddr* ai_addr;
    size_t ai_canonnamelen_in;
    size_t* ai_canonnamelen;
    char* ai_canonname;
    int ocall_errno;
} oe_syscall_getaddrinfo_read_ocall_args_t;

typedef struct _oe_syscall_getaddrinfo_close_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    uint64_t handle;
    int ocall_errno;
} oe_syscall_getaddrinfo_close_ocall_args_t;

typedef struct _oe_syscall_getnameinfo_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    struct oe_sockaddr* sa;
    oe_socklen_t salen;
    char* host;
    oe_socklen_t hostlen;
    char* serv;
    oe_socklen_t servlen;
    int flags;
    int ocall_errno;
} oe_syscall_getnameinfo_ocall_args_t;

typedef struct _oe_syscall_nanosleep_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    struct oe_timespec* req;
    struct oe_timespec* rem;
    int ocall_errno;
} oe_syscall_nanosleep_ocall_args_t;

typedef struct _oe_syscall_clock_nanosleep_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    oe_clockid_t clockid;
    int flag;
    struct oe_timespec* req;
    struct oe_timespec* rem;
    int ocall_errno;
} oe_syscall_clock_nanosleep_ocall_args_t;

typedef struct _oe_syscall_getpid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
} oe_syscall_getpid_ocall_args_t;

typedef struct _oe_syscall_getppid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
} oe_syscall_getppid_ocall_args_t;

typedef struct _oe_syscall_getpgrp_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
} oe_syscall_getpgrp_ocall_args_t;

typedef struct _oe_syscall_getuid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    unsigned int oe_retval;
} oe_syscall_getuid_ocall_args_t;

typedef struct _oe_syscall_geteuid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    unsigned int oe_retval;
} oe_syscall_geteuid_ocall_args_t;

typedef struct _oe_syscall_getgid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    unsigned int oe_retval;
} oe_syscall_getgid_ocall_args_t;

typedef struct _oe_syscall_getegid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    unsigned int oe_retval;
} oe_syscall_getegid_ocall_args_t;

typedef struct _oe_syscall_getpgid_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    int pid;
    int ocall_errno;
} oe_syscall_getpgid_ocall_args_t;

typedef struct _oe_syscall_getgroups_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    size_t size;
    unsigned int* list;
    int ocall_errno;
} oe_syscall_getgroups_ocall_args_t;

typedef struct _oe_syscall_uname_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    int oe_retval;
    struct oe_utsname* buf;
    int ocall_errno;
} oe_syscall_uname_ocall_args_t;

typedef struct _oe_get_supported_attester_format_ids_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    format_ids_t* format_ids;
} oe_get_supported_attester_format_ids_ocall_args_t;

typedef struct _oe_get_qetarget_info_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    oe_uuid_t* format_id;
    void* opt_params;
    size_t opt_params_size;
    sgx_target_info_t* target_info;
} oe_get_qetarget_info_ocall_args_t;

typedef struct _oe_get_quote_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    oe_uuid_t* format_id;
    void* opt_params;
    size_t opt_params_size;
    sgx_report_t* sgx_report;
    void* quote;
    size_t quote_size;
    size_t* quote_size_out;
} oe_get_quote_ocall_args_t;

typedef struct _oe_get_quote_verification_collateral_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    uint8_t* fmspc;
    uint8_t collateral_provider;
    void* tcb_info;
    size_t tcb_info_size;
    size_t* tcb_info_size_out;
    void* tcb_info_issuer_chain;
    size_t tcb_info_issuer_chain_size;
    size_t* tcb_info_issuer_chain_size_out;
    void* pck_crl;
    size_t pck_crl_size;
    size_t* pck_crl_size_out;
    void* root_ca_crl;
    size_t root_ca_crl_size;
    size_t* root_ca_crl_size_out;
    void* pck_crl_issuer_chain;
    size_t pck_crl_issuer_chain_size;
    size_t* pck_crl_issuer_chain_size_out;
    void* qe_identity;
    size_t qe_identity_size;
    size_t* qe_identity_size_out;
    void* qe_identity_issuer_chain;
    size_t qe_identity_issuer_chain_size;
    size_t* qe_identity_issuer_chain_size_out;
} oe_get_quote_verification_collateral_ocall_args_t;

typedef struct _oe_verify_quote_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    oe_uuid_t* format_id;
    void* opt_params;
    size_t opt_params_size;
    void* p_quote;
    uint32_t quote_size;
    time_t expiration_check_date;
    uint32_t* p_collateral_expiration_status;
    uint32_t* p_quote_verification_result;
    void* p_qve_report_info;
    uint32_t qve_report_info_size;
    void* p_supplemental_data;
    uint32_t supplemental_data_size;
    uint32_t* p_supplemental_data_size_out;
    uint32_t collateral_version;
    void* p_tcb_info;
    uint32_t tcb_info_size;
    void* p_tcb_info_issuer_chain;
    uint32_t tcb_info_issuer_chain_size;
    void* p_pck_crl;
    uint32_t pck_crl_size;
    void* p_root_ca_crl;
    uint32_t root_ca_crl_size;
    void* p_pck_crl_issuer_chain;
    uint32_t pck_crl_issuer_chain_size;
    void* p_qe_identity;
    uint32_t qe_identity_size;
    void* p_qe_identity_issuer_chain;
    uint32_t qe_identity_issuer_chain_size;
} oe_verify_quote_ocall_args_t;

typedef struct _oe_sgx_get_cpuid_table_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    void* cpuid_table_buffer;
    size_t cpuid_table_buffer_size;
} oe_sgx_get_cpuid_table_ocall_args_t;

typedef struct _oe_sgx_backtrace_symbols_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_result_t oe_retval;
    oe_enclave_t* oe_enclave;
    uint64_t* buffer;
    size_t size;
    void* symbols_buffer;
    size_t symbols_buffer_size;
    size_t* symbols_buffer_size_out;
} oe_sgx_backtrace_symbols_ocall_args_t;

typedef struct _oe_sgx_thread_wake_wait_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_enclave_t* oe_enclave;
    uint64_t waiter_tcs;
    uint64_t self_tcs;
} oe_sgx_thread_wake_wait_ocall_args_t;

typedef struct _oe_sgx_wake_switchless_worker_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_host_worker_context_t* context;
} oe_sgx_wake_switchless_worker_ocall_args_t;

typedef struct _oe_sgx_sleep_switchless_worker_ocall_args_t
{
    oe_result_t oe_result;
    uint8_t* deepcopy_out_buffer;
    size_t deepcopy_out_buffer_size;
    oe_enclave_worker_context_t* context;
} oe_sgx_sleep_switchless_worker_ocall_args_t;

/**** OCALL function wrappers. ****/

oe_result_t host_helloworld(
    )
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    host_helloworld_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(host_helloworld_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(host_helloworld_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (host_helloworld_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_host_helloworld);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_host_helloworld,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (host_helloworld_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_epoll_create1_ocall(
    oe_host_fd_t* _retval,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_epoll_create1_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_epoll_create1_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_epoll_create1_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_epoll_create1_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_epoll_create1_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_epoll_create1_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_epoll_create1_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_epoll_wait_ocall(
    int* _retval,
    int64_t epfd,
    struct oe_epoll_event* events,
    unsigned int maxevents,
    int timeout)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_epoll_wait_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.epfd = epfd;
    _args.events = (struct oe_epoll_event*)events;
    _args.maxevents = maxevents;
    _args.timeout = timeout;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_epoll_wait_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_epoll_wait_ocall_args_t));
    if (events)
        OE_ADD_ARG_SIZE(_output_buffer_size, _args.maxevents, sizeof(struct oe_epoll_event));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_epoll_wait_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_epoll_wait_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_epoll_wait_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_epoll_wait_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(events, _args.maxevents, sizeof(struct oe_epoll_event));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_epoll_wake_ocall(int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_epoll_wake_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_epoll_wake_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_epoll_wake_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_epoll_wake_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_epoll_wake_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_epoll_wake_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_epoll_wake_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_epoll_ctl_ocall(
    int* _retval,
    int64_t epfd,
    int op,
    int64_t fd,
    struct oe_epoll_event* event)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_epoll_ctl_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.epfd = epfd;
    _args.op = op;
    _args.fd = fd;
    _args.event = (struct oe_epoll_event*)event;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_epoll_ctl_ocall_args_t));
    if (event)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_epoll_event));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_epoll_ctl_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_epoll_ctl_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (event)
        OE_WRITE_IN_PARAM(event, 1, sizeof(struct oe_epoll_event), struct oe_epoll_event*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_epoll_ctl_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_epoll_ctl_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_epoll_ctl_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_epoll_close_ocall(
    int* _retval,
    oe_host_fd_t epfd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_epoll_close_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.epfd = epfd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_epoll_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_epoll_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_epoll_close_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_epoll_close_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_epoll_close_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_epoll_close_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_open_ocall(
    oe_host_fd_t* _retval,
    const char* pathname,
    int flags,
    oe_mode_t mode)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_open_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;
    _args.flags = flags;
    _args.mode = mode;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_open_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_open_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_open_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_open_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_open_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_open_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_read_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    void* buf,
    size_t count)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_read_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.buf = (void*)buf;
    _args.count = count;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_read_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_read_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.count);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_read_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_read_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_read_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_read_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, _args.count);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_write_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    const void* buf,
    size_t count)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_write_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.buf = (void*)buf;
    _args.count = count;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_write_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.count);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_write_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_write_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (buf)
        OE_WRITE_IN_PARAM(buf, 1, _args.count, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_write_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_write_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_write_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_readv_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    void* iov_buf,
    int iovcnt,
    size_t iov_buf_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_readv_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.iov_buf = (void*)iov_buf;
    _args.iovcnt = iovcnt;
    _args.iov_buf_size = iov_buf_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_readv_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.iov_buf_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_readv_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.iov_buf_size);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_readv_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (iov_buf)
        OE_WRITE_IN_OUT_PARAM(iov_buf, 1, _args.iov_buf_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_readv_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_readv_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_readv_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(iov_buf, 1, _args.iov_buf_size);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_writev_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    const void* iov_buf,
    int iovcnt,
    size_t iov_buf_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_writev_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.iov_buf = (void*)iov_buf;
    _args.iovcnt = iovcnt;
    _args.iov_buf_size = iov_buf_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_writev_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.iov_buf_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_writev_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_writev_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (iov_buf)
        OE_WRITE_IN_PARAM(iov_buf, 1, _args.iov_buf_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_writev_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_writev_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_writev_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_lseek_ocall(
    oe_off_t* _retval,
    oe_host_fd_t fd,
    oe_off_t offset,
    int whence)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_lseek_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.offset = offset;
    _args.whence = whence;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_lseek_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_lseek_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_lseek_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_lseek_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_lseek_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_lseek_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_pread_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    void* buf,
    size_t count,
    oe_off_t offset)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_pread_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.buf = (void*)buf;
    _args.count = count;
    _args.offset = offset;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_pread_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_pread_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.count);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_pread_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_pread_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_pread_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_pread_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, _args.count);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_pwrite_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    const void* buf,
    size_t count,
    oe_off_t offset)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_pwrite_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.buf = (void*)buf;
    _args.count = count;
    _args.offset = offset;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_pwrite_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.count);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_pwrite_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_pwrite_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (buf)
        OE_WRITE_IN_PARAM(buf, 1, _args.count, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_pwrite_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_pwrite_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_pwrite_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_close_ocall(
    int* _retval,
    oe_host_fd_t fd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_close_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_close_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_close_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_close_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_close_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_flock_ocall(
    int* _retval,
    oe_host_fd_t fd,
    int operation)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_flock_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.operation = operation;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_flock_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_flock_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_flock_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_flock_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_flock_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_flock_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_fsync_ocall(
    int* _retval,
    oe_host_fd_t fd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_fsync_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_fsync_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_fsync_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_fsync_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_fsync_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_fsync_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_fsync_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_fdatasync_ocall(
    int* _retval,
    oe_host_fd_t fd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_fdatasync_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_fdatasync_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_fdatasync_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_fdatasync_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_fdatasync_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_fdatasync_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_fdatasync_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_dup_ocall(
    oe_host_fd_t* _retval,
    oe_host_fd_t oldfd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_dup_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.oldfd = oldfd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_dup_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_dup_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_dup_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_dup_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_dup_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_dup_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_opendir_ocall(
    uint64_t* _retval,
    const char* name)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_opendir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.name = (char*)name;
    _args.name_len = (name) ? (oe_strlen(name) + 1) : 0;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_opendir_ocall_args_t));
    if (name)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.name_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_opendir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_opendir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (name)
        OE_WRITE_IN_PARAM(name, _args.name_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_opendir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_opendir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_opendir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_readdir_ocall(
    int* _retval,
    uint64_t dirp,
    struct oe_dirent* entry)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_readdir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.dirp = dirp;
    _args.entry = (struct oe_dirent*)entry;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_readdir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_readdir_ocall_args_t));
    if (entry)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_dirent));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_readdir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_readdir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_readdir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_readdir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(entry, 1, sizeof(struct oe_dirent));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_rewinddir_ocall(uint64_t dirp)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_rewinddir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.dirp = dirp;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_rewinddir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_rewinddir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_rewinddir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_rewinddir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_rewinddir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_rewinddir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_closedir_ocall(
    int* _retval,
    uint64_t dirp)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_closedir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.dirp = dirp;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_closedir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_closedir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_closedir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_closedir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_closedir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_closedir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_stat_ocall(
    int* _retval,
    const char* pathname,
    struct oe_stat_t* buf)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_stat_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;
    _args.buf = (struct oe_stat_t*)buf;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_stat_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_stat_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_stat_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_stat_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_stat_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_stat_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_stat_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, sizeof(struct oe_stat_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_fstat_ocall(
    int* _retval,
    oe_host_fd_t fd,
    struct oe_stat_t* buf)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_fstat_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.buf = (struct oe_stat_t*)buf;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_fstat_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_fstat_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_stat_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_fstat_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_fstat_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_fstat_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_fstat_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, sizeof(struct oe_stat_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_access_ocall(
    int* _retval,
    const char* pathname,
    int mode)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_access_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;
    _args.mode = mode;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_access_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_access_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_access_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_access_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_access_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_access_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_link_ocall(
    int* _retval,
    const char* oldpath,
    const char* newpath)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_link_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.oldpath = (char*)oldpath;
    _args.oldpath_len = (oldpath) ? (oe_strlen(oldpath) + 1) : 0;
    _args.newpath = (char*)newpath;
    _args.newpath_len = (newpath) ? (oe_strlen(newpath) + 1) : 0;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_link_ocall_args_t));
    if (oldpath)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.oldpath_len, sizeof(char));
    if (newpath)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.newpath_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_link_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_link_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (oldpath)
        OE_WRITE_IN_PARAM(oldpath, _args.oldpath_len, sizeof(char), char*);
    if (newpath)
        OE_WRITE_IN_PARAM(newpath, _args.newpath_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_link_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_link_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_link_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_unlink_ocall(
    int* _retval,
    const char* pathname)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_unlink_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_unlink_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_unlink_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_unlink_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_unlink_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_unlink_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_unlink_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_rename_ocall(
    int* _retval,
    const char* oldpath,
    const char* newpath)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_rename_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.oldpath = (char*)oldpath;
    _args.oldpath_len = (oldpath) ? (oe_strlen(oldpath) + 1) : 0;
    _args.newpath = (char*)newpath;
    _args.newpath_len = (newpath) ? (oe_strlen(newpath) + 1) : 0;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_rename_ocall_args_t));
    if (oldpath)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.oldpath_len, sizeof(char));
    if (newpath)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.newpath_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_rename_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_rename_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (oldpath)
        OE_WRITE_IN_PARAM(oldpath, _args.oldpath_len, sizeof(char), char*);
    if (newpath)
        OE_WRITE_IN_PARAM(newpath, _args.newpath_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_rename_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_rename_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_rename_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_truncate_ocall(
    int* _retval,
    const char* path,
    oe_off_t length)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_truncate_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.path = (char*)path;
    _args.path_len = (path) ? (oe_strlen(path) + 1) : 0;
    _args.length = length;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_truncate_ocall_args_t));
    if (path)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.path_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_truncate_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_truncate_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (path)
        OE_WRITE_IN_PARAM(path, _args.path_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_truncate_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_truncate_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_truncate_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_ftruncate_ocall(
    int* _retval,
    oe_host_fd_t fd,
    oe_off_t length)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_ftruncate_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.length = length;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_ftruncate_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_ftruncate_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_ftruncate_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_ftruncate_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_ftruncate_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_ftruncate_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_mkdir_ocall(
    int* _retval,
    const char* pathname,
    oe_mode_t mode)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_mkdir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;
    _args.mode = mode;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_mkdir_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_mkdir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_mkdir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_mkdir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_mkdir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_mkdir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_rmdir_ocall(
    int* _retval,
    const char* pathname)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_rmdir_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pathname = (char*)pathname;
    _args.pathname_len = (pathname) ? (oe_strlen(pathname) + 1) : 0;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_rmdir_ocall_args_t));
    if (pathname)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.pathname_len, sizeof(char));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_rmdir_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_rmdir_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (pathname)
        OE_WRITE_IN_PARAM(pathname, _args.pathname_len, sizeof(char), char*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_rmdir_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_rmdir_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_rmdir_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_fcntl_ocall(
    int* _retval,
    oe_host_fd_t fd,
    int cmd,
    uint64_t arg,
    uint64_t argsize,
    void* argout)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_fcntl_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.cmd = cmd;
    _args.arg = arg;
    _args.argsize = argsize;
    _args.argout = (void*)argout;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_fcntl_ocall_args_t));
    if (argout)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.argsize);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_fcntl_ocall_args_t));
    if (argout)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.argsize);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_fcntl_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (argout)
        OE_WRITE_IN_OUT_PARAM(argout, 1, _args.argsize, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_fcntl_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_fcntl_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_fcntl_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(argout, 1, _args.argsize);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_ioctl_ocall(
    int* _retval,
    oe_host_fd_t fd,
    uint64_t request,
    uint64_t arg,
    uint64_t argsize,
    void* argout)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_ioctl_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.request = request;
    _args.arg = arg;
    _args.argsize = argsize;
    _args.argout = (void*)argout;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_ioctl_ocall_args_t));
    if (argout)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.argsize);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_ioctl_ocall_args_t));
    if (argout)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.argsize);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_ioctl_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (argout)
        OE_WRITE_IN_OUT_PARAM(argout, 1, _args.argsize, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_ioctl_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_ioctl_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_ioctl_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(argout, 1, _args.argsize);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_poll_ocall(
    int* _retval,
    struct oe_host_pollfd* host_fds,
    oe_nfds_t nfds,
    int timeout)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_poll_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.host_fds = (struct oe_host_pollfd*)host_fds;
    _args.nfds = nfds;
    _args.timeout = timeout;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_poll_ocall_args_t));
    if (host_fds)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.nfds, sizeof(struct oe_host_pollfd));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_poll_ocall_args_t));
    if (host_fds)
        OE_ADD_ARG_SIZE(_output_buffer_size, _args.nfds, sizeof(struct oe_host_pollfd));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_poll_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (host_fds)
        OE_WRITE_IN_OUT_PARAM(host_fds, _args.nfds, sizeof(struct oe_host_pollfd), struct oe_host_pollfd*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_poll_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_poll_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_poll_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(host_fds, _args.nfds, sizeof(struct oe_host_pollfd));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_kill_ocall(
    int* _retval,
    int pid,
    int signum)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_kill_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pid = pid;
    _args.signum = signum;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_kill_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_kill_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_kill_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_kill_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_kill_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_kill_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_close_socket_ocall(
    int* _retval,
    oe_host_fd_t sockfd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_close_socket_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_close_socket_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_close_socket_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_close_socket_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_close_socket_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_close_socket_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_close_socket_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_socket_ocall(
    oe_host_fd_t* _retval,
    int domain,
    int type,
    int protocol)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_socket_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.domain = domain;
    _args.type = type;
    _args.protocol = protocol;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_socket_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_socket_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_socket_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_socket_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_socket_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_socket_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_shutdown_sockets_device_ocall(
    int* _retval,
    oe_host_fd_t sockfd)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_shutdown_sockets_device_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_shutdown_sockets_device_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_shutdown_sockets_device_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_shutdown_sockets_device_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_shutdown_sockets_device_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_shutdown_sockets_device_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_shutdown_sockets_device_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_socketpair_ocall(
    int* _retval,
    int domain,
    int type,
    int protocol,
    oe_host_fd_t sv[2])
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_socketpair_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.domain = domain;
    _args.type = type;
    _args.protocol = protocol;
    _args.sv = (oe_host_fd_t*)sv;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_socketpair_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_socketpair_ocall_args_t));
    if (sv)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_host_fd_t[2]));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_socketpair_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_socketpair_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_socketpair_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_socketpair_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(sv, 1, sizeof(oe_host_fd_t[2]));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_connect_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    const struct oe_sockaddr* addr,
    oe_socklen_t addrlen)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_connect_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.addr = (struct oe_sockaddr*)addr;
    _args.addrlen = addrlen;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_connect_ocall_args_t));
    if (addr)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.addrlen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_connect_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_connect_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (addr)
        OE_WRITE_IN_PARAM(addr, 1, _args.addrlen, struct oe_sockaddr*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_connect_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_connect_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_connect_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_accept_ocall(
    oe_host_fd_t* _retval,
    oe_host_fd_t sockfd,
    struct oe_sockaddr* addr,
    oe_socklen_t addrlen_in,
    oe_socklen_t* addrlen_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_accept_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.addr = (struct oe_sockaddr*)addr;
    _args.addrlen_in = addrlen_in;
    _args.addrlen_out = (oe_socklen_t*)addrlen_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_accept_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_accept_ocall_args_t));
    if (addr)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.addrlen_in);
    if (addrlen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_socklen_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_accept_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_accept_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_accept_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_accept_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(addr, 1, _args.addrlen_in);
    OE_READ_OUT_PARAM(addrlen_out, 1, sizeof(oe_socklen_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_bind_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    const struct oe_sockaddr* addr,
    oe_socklen_t addrlen)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_bind_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.addr = (struct oe_sockaddr*)addr;
    _args.addrlen = addrlen;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_bind_ocall_args_t));
    if (addr)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.addrlen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_bind_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_bind_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (addr)
        OE_WRITE_IN_PARAM(addr, 1, _args.addrlen, struct oe_sockaddr*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_bind_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_bind_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_bind_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_listen_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    int backlog)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_listen_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.backlog = backlog;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_listen_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_listen_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_listen_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_listen_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_listen_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_listen_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_recvmsg_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    void* msg_name,
    oe_socklen_t msg_namelen,
    oe_socklen_t* msg_namelen_out,
    void* msg_iov_buf,
    size_t msg_iovlen,
    size_t msg_iov_buf_size,
    void* msg_control,
    size_t msg_controllen,
    size_t* msg_controllen_out,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_recvmsg_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.msg_name = (void*)msg_name;
    _args.msg_namelen = msg_namelen;
    _args.msg_namelen_out = (oe_socklen_t*)msg_namelen_out;
    _args.msg_iov_buf = (void*)msg_iov_buf;
    _args.msg_iovlen = msg_iovlen;
    _args.msg_iov_buf_size = msg_iov_buf_size;
    _args.msg_control = (void*)msg_control;
    _args.msg_controllen = msg_controllen;
    _args.msg_controllen_out = (size_t*)msg_controllen_out;
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_recvmsg_ocall_args_t));
    if (msg_iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.msg_iov_buf_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_recvmsg_ocall_args_t));
    if (msg_name)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.msg_namelen);
    if (msg_namelen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_socklen_t));
    if (msg_iov_buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.msg_iov_buf_size);
    if (msg_control)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.msg_controllen);
    if (msg_controllen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_recvmsg_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (msg_iov_buf)
        OE_WRITE_IN_OUT_PARAM(msg_iov_buf, 1, _args.msg_iov_buf_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_recvmsg_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_recvmsg_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_recvmsg_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(msg_name, 1, _args.msg_namelen);
    OE_READ_OUT_PARAM(msg_namelen_out, 1, sizeof(oe_socklen_t));
    OE_READ_IN_OUT_PARAM(msg_iov_buf, 1, _args.msg_iov_buf_size);
    OE_READ_OUT_PARAM(msg_control, 1, _args.msg_controllen);
    OE_READ_OUT_PARAM(msg_controllen_out, 1, sizeof(size_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_sendmsg_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    const void* msg_name,
    oe_socklen_t msg_namelen,
    void* msg_iov_buf,
    size_t msg_iovlen,
    size_t msg_iov_buf_size,
    const void* msg_control,
    size_t msg_controllen,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_sendmsg_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.msg_name = (void*)msg_name;
    _args.msg_namelen = msg_namelen;
    _args.msg_iov_buf = (void*)msg_iov_buf;
    _args.msg_iovlen = msg_iovlen;
    _args.msg_iov_buf_size = msg_iov_buf_size;
    _args.msg_control = (void*)msg_control;
    _args.msg_controllen = msg_controllen;
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_sendmsg_ocall_args_t));
    if (msg_name)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.msg_namelen);
    if (msg_iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.msg_iov_buf_size);
    if (msg_control)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.msg_controllen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_sendmsg_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_sendmsg_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (msg_name)
        OE_WRITE_IN_PARAM(msg_name, 1, _args.msg_namelen, void*);
    if (msg_iov_buf)
        OE_WRITE_IN_PARAM(msg_iov_buf, 1, _args.msg_iov_buf_size, void*);
    if (msg_control)
        OE_WRITE_IN_PARAM(msg_control, 1, _args.msg_controllen, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_sendmsg_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_sendmsg_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_sendmsg_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_recv_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    void* buf,
    size_t len,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_recv_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.buf = (void*)buf;
    _args.len = len;
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_recv_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_recv_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.len);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_recv_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_recv_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_recv_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_recv_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, _args.len);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_recvfrom_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    void* buf,
    size_t len,
    int flags,
    struct oe_sockaddr* src_addr,
    oe_socklen_t addrlen_in,
    oe_socklen_t* addrlen_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_recvfrom_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.buf = (void*)buf;
    _args.len = len;
    _args.flags = flags;
    _args.src_addr = (struct oe_sockaddr*)src_addr;
    _args.addrlen_in = addrlen_in;
    _args.addrlen_out = (oe_socklen_t*)addrlen_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_recvfrom_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_recvfrom_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.len);
    if (src_addr)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.addrlen_in);
    if (addrlen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_socklen_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_recvfrom_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_recvfrom_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_recvfrom_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_recvfrom_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, _args.len);
    OE_READ_OUT_PARAM(src_addr, 1, _args.addrlen_in);
    OE_READ_OUT_PARAM(addrlen_out, 1, sizeof(oe_socklen_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_send_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    const void* buf,
    size_t len,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_send_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.buf = (void*)buf;
    _args.len = len;
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_send_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.len);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_send_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_send_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (buf)
        OE_WRITE_IN_PARAM(buf, 1, _args.len, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_send_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_send_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_send_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_sendto_ocall(
    ssize_t* _retval,
    oe_host_fd_t sockfd,
    const void* buf,
    size_t len,
    int flags,
    const struct oe_sockaddr* dest_addr,
    oe_socklen_t addrlen)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_sendto_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.buf = (void*)buf;
    _args.len = len;
    _args.flags = flags;
    _args.dest_addr = (struct oe_sockaddr*)dest_addr;
    _args.addrlen = addrlen;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_sendto_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.len);
    if (dest_addr)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.addrlen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_sendto_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_sendto_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (buf)
        OE_WRITE_IN_PARAM(buf, 1, _args.len, void*);
    if (dest_addr)
        OE_WRITE_IN_PARAM(dest_addr, 1, _args.addrlen, struct oe_sockaddr*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_sendto_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_sendto_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_sendto_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_recvv_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    void* iov_buf,
    int iovcnt,
    size_t iov_buf_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_recvv_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.iov_buf = (void*)iov_buf;
    _args.iovcnt = iovcnt;
    _args.iov_buf_size = iov_buf_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_recvv_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.iov_buf_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_recvv_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.iov_buf_size);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_recvv_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (iov_buf)
        OE_WRITE_IN_OUT_PARAM(iov_buf, 1, _args.iov_buf_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_recvv_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_recvv_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_recvv_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(iov_buf, 1, _args.iov_buf_size);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_sendv_ocall(
    ssize_t* _retval,
    oe_host_fd_t fd,
    const void* iov_buf,
    int iovcnt,
    size_t iov_buf_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_sendv_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fd = fd;
    _args.iov_buf = (void*)iov_buf;
    _args.iovcnt = iovcnt;
    _args.iov_buf_size = iov_buf_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_sendv_ocall_args_t));
    if (iov_buf)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.iov_buf_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_sendv_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_sendv_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (iov_buf)
        OE_WRITE_IN_PARAM(iov_buf, 1, _args.iov_buf_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_sendv_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_sendv_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_sendv_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_shutdown_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    int how)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_shutdown_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.how = how;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_shutdown_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_shutdown_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_shutdown_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_shutdown_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_shutdown_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_shutdown_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_setsockopt_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    int level,
    int optname,
    const void* optval,
    oe_socklen_t optlen)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_setsockopt_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.level = level;
    _args.optname = optname;
    _args.optval = (void*)optval;
    _args.optlen = optlen;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_setsockopt_ocall_args_t));
    if (optval)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.optlen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_setsockopt_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_setsockopt_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (optval)
        OE_WRITE_IN_PARAM(optval, 1, _args.optlen, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_setsockopt_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_setsockopt_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_setsockopt_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getsockopt_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    int level,
    int optname,
    void* optval,
    oe_socklen_t optlen_in,
    oe_socklen_t* optlen_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getsockopt_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.level = level;
    _args.optname = optname;
    _args.optval = (void*)optval;
    _args.optlen_in = optlen_in;
    _args.optlen_out = (oe_socklen_t*)optlen_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getsockopt_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getsockopt_ocall_args_t));
    if (optval)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.optlen_in);
    if (optlen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_socklen_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getsockopt_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getsockopt_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getsockopt_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getsockopt_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(optval, 1, _args.optlen_in);
    OE_READ_OUT_PARAM(optlen_out, 1, sizeof(oe_socklen_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getsockname_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    struct oe_sockaddr* addr,
    oe_socklen_t addrlen_in,
    oe_socklen_t* addrlen_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getsockname_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.addr = (struct oe_sockaddr*)addr;
    _args.addrlen_in = addrlen_in;
    _args.addrlen_out = (oe_socklen_t*)addrlen_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getsockname_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getsockname_ocall_args_t));
    if (addr)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.addrlen_in);
    if (addrlen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, 1);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getsockname_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getsockname_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getsockname_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getsockname_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(addr, 1, _args.addrlen_in);
    OE_READ_OUT_PARAM(addrlen_out, 1, 1);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getpeername_ocall(
    int* _retval,
    oe_host_fd_t sockfd,
    struct oe_sockaddr* addr,
    oe_socklen_t addrlen_in,
    oe_socklen_t* addrlen_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getpeername_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sockfd = sockfd;
    _args.addr = (struct oe_sockaddr*)addr;
    _args.addrlen_in = addrlen_in;
    _args.addrlen_out = (oe_socklen_t*)addrlen_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getpeername_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getpeername_ocall_args_t));
    if (addr)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.addrlen_in);
    if (addrlen_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, 1);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getpeername_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getpeername_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getpeername_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getpeername_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(addr, 1, _args.addrlen_in);
    OE_READ_OUT_PARAM(addrlen_out, 1, 1);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getaddrinfo_open_ocall(
    int* _retval,
    const char* node,
    const char* service,
    const struct oe_addrinfo* hints,
    uint64_t* handle)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getaddrinfo_open_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.node = (char*)node;
    _args.node_len = (node) ? (oe_strlen(node) + 1) : 0;
    _args.service = (char*)service;
    _args.service_len = (service) ? (oe_strlen(service) + 1) : 0;
    _args.hints = (struct oe_addrinfo*)hints;
    _args.handle = (uint64_t*)handle;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getaddrinfo_open_ocall_args_t));
    if (node)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.node_len, sizeof(char));
    if (service)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.service_len, sizeof(char));
    if (hints)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_addrinfo));
    if (hints && hints->ai_addr)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.hints->ai_addrlen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getaddrinfo_open_ocall_args_t));
    if (handle)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(uint64_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getaddrinfo_open_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (node)
        OE_WRITE_IN_PARAM(node, _args.node_len, sizeof(char), char*);
    if (service)
        OE_WRITE_IN_PARAM(service, _args.service_len, sizeof(char), char*);
    if (hints)
        OE_WRITE_IN_PARAM(hints, 1, sizeof(struct oe_addrinfo), struct oe_addrinfo*);
    if (hints && hints->ai_addr)
        OE_WRITE_IN_PARAM(hints->ai_addr, 1, _args.hints->ai_addrlen, struct oe_sockaddr*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getaddrinfo_open_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getaddrinfo_open_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getaddrinfo_open_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(handle, 1, sizeof(uint64_t));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getaddrinfo_read_ocall(
    int* _retval,
    uint64_t handle,
    int* ai_flags,
    int* ai_family,
    int* ai_socktype,
    int* ai_protocol,
    oe_socklen_t ai_addrlen_in,
    oe_socklen_t* ai_addrlen,
    struct oe_sockaddr* ai_addr,
    size_t ai_canonnamelen_in,
    size_t* ai_canonnamelen,
    char* ai_canonname)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getaddrinfo_read_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.handle = handle;
    _args.ai_flags = (int*)ai_flags;
    _args.ai_family = (int*)ai_family;
    _args.ai_socktype = (int*)ai_socktype;
    _args.ai_protocol = (int*)ai_protocol;
    _args.ai_addrlen_in = ai_addrlen_in;
    _args.ai_addrlen = (oe_socklen_t*)ai_addrlen;
    _args.ai_addr = (struct oe_sockaddr*)ai_addr;
    _args.ai_canonnamelen_in = ai_canonnamelen_in;
    _args.ai_canonnamelen = (size_t*)ai_canonnamelen;
    _args.ai_canonname = (char*)ai_canonname;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getaddrinfo_read_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getaddrinfo_read_ocall_args_t));
    if (ai_flags)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(int));
    if (ai_family)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(int));
    if (ai_socktype)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(int));
    if (ai_protocol)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(int));
    if (ai_addrlen)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(oe_socklen_t));
    if (ai_addr)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.ai_addrlen_in);
    if (ai_canonnamelen)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (ai_canonname)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.ai_canonnamelen_in);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getaddrinfo_read_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getaddrinfo_read_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getaddrinfo_read_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getaddrinfo_read_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(ai_flags, 1, sizeof(int));
    OE_READ_OUT_PARAM(ai_family, 1, sizeof(int));
    OE_READ_OUT_PARAM(ai_socktype, 1, sizeof(int));
    OE_READ_OUT_PARAM(ai_protocol, 1, sizeof(int));
    OE_READ_OUT_PARAM(ai_addrlen, 1, sizeof(oe_socklen_t));
    OE_READ_OUT_PARAM(ai_addr, 1, _args.ai_addrlen_in);
    OE_READ_OUT_PARAM(ai_canonnamelen, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(ai_canonname, 1, _args.ai_canonnamelen_in);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getaddrinfo_close_ocall(
    int* _retval,
    uint64_t handle)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getaddrinfo_close_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.handle = handle;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getaddrinfo_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getaddrinfo_close_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getaddrinfo_close_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getaddrinfo_close_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getaddrinfo_close_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getaddrinfo_close_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getnameinfo_ocall(
    int* _retval,
    const struct oe_sockaddr* sa,
    oe_socklen_t salen,
    char* host,
    oe_socklen_t hostlen,
    char* serv,
    oe_socklen_t servlen,
    int flags)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getnameinfo_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.sa = (struct oe_sockaddr*)sa;
    _args.salen = salen;
    _args.host = (char*)host;
    _args.hostlen = hostlen;
    _args.serv = (char*)serv;
    _args.servlen = servlen;
    _args.flags = flags;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getnameinfo_ocall_args_t));
    if (sa)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.salen);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getnameinfo_ocall_args_t));
    if (host)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.hostlen);
    if (serv)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.servlen);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getnameinfo_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (sa)
        OE_WRITE_IN_PARAM(sa, 1, _args.salen, struct oe_sockaddr*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getnameinfo_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getnameinfo_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getnameinfo_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(host, 1, _args.hostlen);
    OE_READ_OUT_PARAM(serv, 1, _args.servlen);

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_nanosleep_ocall(
    int* _retval,
    struct oe_timespec* req,
    struct oe_timespec* rem)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_nanosleep_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.req = (struct oe_timespec*)req;
    _args.rem = (struct oe_timespec*)rem;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_nanosleep_ocall_args_t));
    if (req)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_timespec));
    if (rem)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_timespec));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_nanosleep_ocall_args_t));
    if (rem)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_timespec));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_nanosleep_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (req)
        OE_WRITE_IN_PARAM(req, 1, sizeof(struct oe_timespec), struct oe_timespec*);
    if (rem)
        OE_WRITE_IN_OUT_PARAM(rem, 1, sizeof(struct oe_timespec), struct oe_timespec*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_nanosleep_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_nanosleep_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_nanosleep_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(rem, 1, sizeof(struct oe_timespec));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_clock_nanosleep_ocall(
    int* _retval,
    oe_clockid_t clockid,
    int flag,
    struct oe_timespec* req,
    struct oe_timespec* rem)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_clock_nanosleep_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.clockid = clockid;
    _args.flag = flag;
    _args.req = (struct oe_timespec*)req;
    _args.rem = (struct oe_timespec*)rem;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_clock_nanosleep_ocall_args_t));
    if (req)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_timespec));
    if (rem)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(struct oe_timespec));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_clock_nanosleep_ocall_args_t));
    if (rem)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_timespec));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_clock_nanosleep_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (req)
        OE_WRITE_IN_PARAM(req, 1, sizeof(struct oe_timespec), struct oe_timespec*);
    if (rem)
        OE_WRITE_IN_OUT_PARAM(rem, 1, sizeof(struct oe_timespec), struct oe_timespec*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_clock_nanosleep_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_clock_nanosleep_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_clock_nanosleep_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_IN_OUT_PARAM(rem, 1, sizeof(struct oe_timespec));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getpid_ocall(int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getpid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getpid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getpid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getpid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getpid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getpid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getpid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getppid_ocall(int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getppid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getppid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getppid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getppid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getppid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getppid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getppid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getpgrp_ocall(int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getpgrp_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getpgrp_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getpgrp_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getpgrp_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getpgrp_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getpgrp_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getpgrp_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getuid_ocall(unsigned int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getuid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getuid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getuid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getuid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getuid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getuid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getuid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_geteuid_ocall(unsigned int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_geteuid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_geteuid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_geteuid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_geteuid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_geteuid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_geteuid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_geteuid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getgid_ocall(unsigned int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getgid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getgid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getgid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getgid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getgid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getgid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getgid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getegid_ocall(unsigned int* _retval)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getegid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getegid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getegid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getegid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getegid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getegid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getegid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getpgid_ocall(
    int* _retval,
    int pid)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getpgid_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.pid = pid;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getpgid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getpgid_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getpgid_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getpgid_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getpgid_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getpgid_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_getgroups_ocall(
    int* _retval,
    size_t size,
    unsigned int* list)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_getgroups_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.size = size;
    _args.list = (unsigned int*)list;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_getgroups_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_getgroups_ocall_args_t));
    if (list)
        OE_ADD_ARG_SIZE(_output_buffer_size, _args.size, sizeof(unsigned int));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_getgroups_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_getgroups_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_getgroups_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_getgroups_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(list, _args.size, sizeof(unsigned int));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_syscall_uname_ocall(
    int* _retval,
    struct oe_utsname* buf)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_syscall_uname_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.buf = (struct oe_utsname*)buf;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_syscall_uname_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_syscall_uname_ocall_args_t));
    if (buf)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(struct oe_utsname));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_syscall_uname_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_syscall_uname_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_syscall_uname_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_syscall_uname_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(buf, 1, sizeof(struct oe_utsname));

    /* Retrieve propagated errno from OCALL. */
    oe_errno = _pargs_out->ocall_errno;


    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_get_supported_attester_format_ids_ocall(
    oe_result_t* _retval,
    format_ids_t* format_ids)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_get_supported_attester_format_ids_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;
    uint8_t* _deepcopy_out_buffer = NULL;
    size_t _deepcopy_out_buffer_size = 0;
    size_t _deepcopy_out_buffer_offset = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.format_ids = (format_ids_t*)format_ids;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_get_supported_attester_format_ids_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_get_supported_attester_format_ids_ocall_args_t));
    if (format_ids)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(format_ids_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_get_supported_attester_format_ids_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_get_supported_attester_format_ids_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_get_supported_attester_format_ids_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_get_supported_attester_format_ids_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    _deepcopy_out_buffer = _pargs_out->deepcopy_out_buffer;
    _deepcopy_out_buffer_size = _pargs_out->deepcopy_out_buffer_size;
    if (_deepcopy_out_buffer && _deepcopy_out_buffer_size && 
        !oe_is_within_enclave(_deepcopy_out_buffer, _deepcopy_out_buffer_size))
    {
        _result = OE_FAILURE;
        goto done;
    }

    OE_READ_OUT_PARAM(format_ids, 1, sizeof(format_ids_t));
    if (format_ids && format_ids->data)
        OE_SET_DEEPCOPY_OUT_PARAM(format_ids->data, 1, format_ids->size, void*);

    if (_deepcopy_out_buffer_offset != _deepcopy_out_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    if (_deepcopy_out_buffer)
        oe_free(_deepcopy_out_buffer);

    return _result;
}

oe_result_t oe_get_qetarget_info_ocall(
    oe_result_t* _retval,
    const oe_uuid_t* format_id,
    const void* opt_params,
    size_t opt_params_size,
    sgx_target_info_t* target_info)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_get_qetarget_info_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.format_id = (oe_uuid_t*)format_id;
    _args.opt_params = (void*)opt_params;
    _args.opt_params_size = opt_params_size;
    _args.target_info = (sgx_target_info_t*)target_info;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_get_qetarget_info_ocall_args_t));
    if (format_id)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(oe_uuid_t));
    if (opt_params)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.opt_params_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_get_qetarget_info_ocall_args_t));
    if (target_info)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(sgx_target_info_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_get_qetarget_info_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (format_id)
        OE_WRITE_IN_PARAM(format_id, 1, sizeof(oe_uuid_t), oe_uuid_t*);
    if (opt_params)
        OE_WRITE_IN_PARAM(opt_params, 1, _args.opt_params_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_get_qetarget_info_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_get_qetarget_info_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_get_qetarget_info_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(target_info, 1, sizeof(sgx_target_info_t));

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_get_quote_ocall(
    oe_result_t* _retval,
    const oe_uuid_t* format_id,
    const void* opt_params,
    size_t opt_params_size,
    const sgx_report_t* sgx_report,
    void* quote,
    size_t quote_size,
    size_t* quote_size_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_get_quote_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.format_id = (oe_uuid_t*)format_id;
    _args.opt_params = (void*)opt_params;
    _args.opt_params_size = opt_params_size;
    _args.sgx_report = (sgx_report_t*)sgx_report;
    _args.quote = (void*)quote;
    _args.quote_size = quote_size;
    _args.quote_size_out = (size_t*)quote_size_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_get_quote_ocall_args_t));
    if (format_id)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(oe_uuid_t));
    if (opt_params)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.opt_params_size);
    if (sgx_report)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(sgx_report_t));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_get_quote_ocall_args_t));
    if (quote)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.quote_size);
    if (quote_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_get_quote_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (format_id)
        OE_WRITE_IN_PARAM(format_id, 1, sizeof(oe_uuid_t), oe_uuid_t*);
    if (opt_params)
        OE_WRITE_IN_PARAM(opt_params, 1, _args.opt_params_size, void*);
    if (sgx_report)
        OE_WRITE_IN_PARAM(sgx_report, 1, sizeof(sgx_report_t), sgx_report_t*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_get_quote_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_get_quote_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_get_quote_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(quote, 1, _args.quote_size);
    OE_READ_OUT_PARAM(quote_size_out, 1, sizeof(size_t));

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_get_quote_verification_collateral_ocall(
    oe_result_t* _retval,
    uint8_t fmspc[6],
    uint8_t collateral_provider,
    void* tcb_info,
    size_t tcb_info_size,
    size_t* tcb_info_size_out,
    void* tcb_info_issuer_chain,
    size_t tcb_info_issuer_chain_size,
    size_t* tcb_info_issuer_chain_size_out,
    void* pck_crl,
    size_t pck_crl_size,
    size_t* pck_crl_size_out,
    void* root_ca_crl,
    size_t root_ca_crl_size,
    size_t* root_ca_crl_size_out,
    void* pck_crl_issuer_chain,
    size_t pck_crl_issuer_chain_size,
    size_t* pck_crl_issuer_chain_size_out,
    void* qe_identity,
    size_t qe_identity_size,
    size_t* qe_identity_size_out,
    void* qe_identity_issuer_chain,
    size_t qe_identity_issuer_chain_size,
    size_t* qe_identity_issuer_chain_size_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_get_quote_verification_collateral_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.fmspc = (uint8_t*)fmspc;
    _args.collateral_provider = collateral_provider;
    _args.tcb_info = (void*)tcb_info;
    _args.tcb_info_size = tcb_info_size;
    _args.tcb_info_size_out = (size_t*)tcb_info_size_out;
    _args.tcb_info_issuer_chain = (void*)tcb_info_issuer_chain;
    _args.tcb_info_issuer_chain_size = tcb_info_issuer_chain_size;
    _args.tcb_info_issuer_chain_size_out = (size_t*)tcb_info_issuer_chain_size_out;
    _args.pck_crl = (void*)pck_crl;
    _args.pck_crl_size = pck_crl_size;
    _args.pck_crl_size_out = (size_t*)pck_crl_size_out;
    _args.root_ca_crl = (void*)root_ca_crl;
    _args.root_ca_crl_size = root_ca_crl_size;
    _args.root_ca_crl_size_out = (size_t*)root_ca_crl_size_out;
    _args.pck_crl_issuer_chain = (void*)pck_crl_issuer_chain;
    _args.pck_crl_issuer_chain_size = pck_crl_issuer_chain_size;
    _args.pck_crl_issuer_chain_size_out = (size_t*)pck_crl_issuer_chain_size_out;
    _args.qe_identity = (void*)qe_identity;
    _args.qe_identity_size = qe_identity_size;
    _args.qe_identity_size_out = (size_t*)qe_identity_size_out;
    _args.qe_identity_issuer_chain = (void*)qe_identity_issuer_chain;
    _args.qe_identity_issuer_chain_size = qe_identity_issuer_chain_size;
    _args.qe_identity_issuer_chain_size_out = (size_t*)qe_identity_issuer_chain_size_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_get_quote_verification_collateral_ocall_args_t));
    if (fmspc)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(uint8_t[6]));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_get_quote_verification_collateral_ocall_args_t));
    if (tcb_info)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.tcb_info_size);
    if (tcb_info_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (tcb_info_issuer_chain)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.tcb_info_issuer_chain_size);
    if (tcb_info_issuer_chain_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (pck_crl)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.pck_crl_size);
    if (pck_crl_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (root_ca_crl)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.root_ca_crl_size);
    if (root_ca_crl_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (pck_crl_issuer_chain)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.pck_crl_issuer_chain_size);
    if (pck_crl_issuer_chain_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (qe_identity)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.qe_identity_size);
    if (qe_identity_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    if (qe_identity_issuer_chain)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.qe_identity_issuer_chain_size);
    if (qe_identity_issuer_chain_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_get_quote_verification_collateral_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (fmspc)
        OE_WRITE_IN_PARAM(fmspc, 1, sizeof(uint8_t[6]), uint8_t*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_get_quote_verification_collateral_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_get_quote_verification_collateral_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_get_quote_verification_collateral_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(tcb_info, 1, _args.tcb_info_size);
    OE_READ_OUT_PARAM(tcb_info_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(tcb_info_issuer_chain, 1, _args.tcb_info_issuer_chain_size);
    OE_READ_OUT_PARAM(tcb_info_issuer_chain_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(pck_crl, 1, _args.pck_crl_size);
    OE_READ_OUT_PARAM(pck_crl_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(root_ca_crl, 1, _args.root_ca_crl_size);
    OE_READ_OUT_PARAM(root_ca_crl_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(pck_crl_issuer_chain, 1, _args.pck_crl_issuer_chain_size);
    OE_READ_OUT_PARAM(pck_crl_issuer_chain_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(qe_identity, 1, _args.qe_identity_size);
    OE_READ_OUT_PARAM(qe_identity_size_out, 1, sizeof(size_t));
    OE_READ_OUT_PARAM(qe_identity_issuer_chain, 1, _args.qe_identity_issuer_chain_size);
    OE_READ_OUT_PARAM(qe_identity_issuer_chain_size_out, 1, sizeof(size_t));

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_verify_quote_ocall(
    oe_result_t* _retval,
    const oe_uuid_t* format_id,
    const void* opt_params,
    size_t opt_params_size,
    const void* p_quote,
    uint32_t quote_size,
    const time_t expiration_check_date,
    uint32_t* p_collateral_expiration_status,
    uint32_t* p_quote_verification_result,
    void* p_qve_report_info,
    uint32_t qve_report_info_size,
    void* p_supplemental_data,
    uint32_t supplemental_data_size,
    uint32_t* p_supplemental_data_size_out,
    uint32_t collateral_version,
    const void* p_tcb_info,
    uint32_t tcb_info_size,
    const void* p_tcb_info_issuer_chain,
    uint32_t tcb_info_issuer_chain_size,
    const void* p_pck_crl,
    uint32_t pck_crl_size,
    const void* p_root_ca_crl,
    uint32_t root_ca_crl_size,
    const void* p_pck_crl_issuer_chain,
    uint32_t pck_crl_issuer_chain_size,
    const void* p_qe_identity,
    uint32_t qe_identity_size,
    const void* p_qe_identity_issuer_chain,
    uint32_t qe_identity_issuer_chain_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_verify_quote_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.format_id = (oe_uuid_t*)format_id;
    _args.opt_params = (void*)opt_params;
    _args.opt_params_size = opt_params_size;
    _args.p_quote = (void*)p_quote;
    _args.quote_size = quote_size;
    _args.expiration_check_date = expiration_check_date;
    _args.p_collateral_expiration_status = (uint32_t*)p_collateral_expiration_status;
    _args.p_quote_verification_result = (uint32_t*)p_quote_verification_result;
    _args.p_qve_report_info = (void*)p_qve_report_info;
    _args.qve_report_info_size = qve_report_info_size;
    _args.p_supplemental_data = (void*)p_supplemental_data;
    _args.supplemental_data_size = supplemental_data_size;
    _args.p_supplemental_data_size_out = (uint32_t*)p_supplemental_data_size_out;
    _args.collateral_version = collateral_version;
    _args.p_tcb_info = (void*)p_tcb_info;
    _args.tcb_info_size = tcb_info_size;
    _args.p_tcb_info_issuer_chain = (void*)p_tcb_info_issuer_chain;
    _args.tcb_info_issuer_chain_size = tcb_info_issuer_chain_size;
    _args.p_pck_crl = (void*)p_pck_crl;
    _args.pck_crl_size = pck_crl_size;
    _args.p_root_ca_crl = (void*)p_root_ca_crl;
    _args.root_ca_crl_size = root_ca_crl_size;
    _args.p_pck_crl_issuer_chain = (void*)p_pck_crl_issuer_chain;
    _args.pck_crl_issuer_chain_size = pck_crl_issuer_chain_size;
    _args.p_qe_identity = (void*)p_qe_identity;
    _args.qe_identity_size = qe_identity_size;
    _args.p_qe_identity_issuer_chain = (void*)p_qe_identity_issuer_chain;
    _args.qe_identity_issuer_chain_size = qe_identity_issuer_chain_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_verify_quote_ocall_args_t));
    if (format_id)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, sizeof(oe_uuid_t));
    if (opt_params)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.opt_params_size);
    if (p_quote)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.quote_size);
    if (p_qve_report_info)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.qve_report_info_size);
    if (p_tcb_info)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.tcb_info_size);
    if (p_tcb_info_issuer_chain)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.tcb_info_issuer_chain_size);
    if (p_pck_crl)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.pck_crl_size);
    if (p_root_ca_crl)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.root_ca_crl_size);
    if (p_pck_crl_issuer_chain)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.pck_crl_issuer_chain_size);
    if (p_qe_identity)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.qe_identity_size);
    if (p_qe_identity_issuer_chain)
        OE_ADD_ARG_SIZE(_input_buffer_size, 1, _args.qe_identity_issuer_chain_size);
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_verify_quote_ocall_args_t));
    if (p_collateral_expiration_status)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(uint32_t));
    if (p_quote_verification_result)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(uint32_t));
    if (p_qve_report_info)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.qve_report_info_size);
    if (p_supplemental_data)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.supplemental_data_size);
    if (p_supplemental_data_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(uint32_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_verify_quote_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (format_id)
        OE_WRITE_IN_PARAM(format_id, 1, sizeof(oe_uuid_t), oe_uuid_t*);
    if (opt_params)
        OE_WRITE_IN_PARAM(opt_params, 1, _args.opt_params_size, void*);
    if (p_quote)
        OE_WRITE_IN_PARAM(p_quote, 1, _args.quote_size, void*);
    if (p_qve_report_info)
        OE_WRITE_IN_OUT_PARAM(p_qve_report_info, 1, _args.qve_report_info_size, void*);
    if (p_tcb_info)
        OE_WRITE_IN_PARAM(p_tcb_info, 1, _args.tcb_info_size, void*);
    if (p_tcb_info_issuer_chain)
        OE_WRITE_IN_PARAM(p_tcb_info_issuer_chain, 1, _args.tcb_info_issuer_chain_size, void*);
    if (p_pck_crl)
        OE_WRITE_IN_PARAM(p_pck_crl, 1, _args.pck_crl_size, void*);
    if (p_root_ca_crl)
        OE_WRITE_IN_PARAM(p_root_ca_crl, 1, _args.root_ca_crl_size, void*);
    if (p_pck_crl_issuer_chain)
        OE_WRITE_IN_PARAM(p_pck_crl_issuer_chain, 1, _args.pck_crl_issuer_chain_size, void*);
    if (p_qe_identity)
        OE_WRITE_IN_PARAM(p_qe_identity, 1, _args.qe_identity_size, void*);
    if (p_qe_identity_issuer_chain)
        OE_WRITE_IN_PARAM(p_qe_identity_issuer_chain, 1, _args.qe_identity_issuer_chain_size, void*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_verify_quote_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_verify_quote_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_verify_quote_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(p_collateral_expiration_status, 1, sizeof(uint32_t));
    OE_READ_OUT_PARAM(p_quote_verification_result, 1, sizeof(uint32_t));
    OE_READ_IN_OUT_PARAM(p_qve_report_info, 1, _args.qve_report_info_size);
    OE_READ_OUT_PARAM(p_supplemental_data, 1, _args.supplemental_data_size);
    OE_READ_OUT_PARAM(p_supplemental_data_size_out, 1, sizeof(uint32_t));

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_sgx_get_cpuid_table_ocall(
    oe_result_t* _retval,
    void* cpuid_table_buffer,
    size_t cpuid_table_buffer_size)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_sgx_get_cpuid_table_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.cpuid_table_buffer = (void*)cpuid_table_buffer;
    _args.cpuid_table_buffer_size = cpuid_table_buffer_size;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_sgx_get_cpuid_table_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_sgx_get_cpuid_table_ocall_args_t));
    if (cpuid_table_buffer)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.cpuid_table_buffer_size);
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_sgx_get_cpuid_table_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_sgx_get_cpuid_table_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_sgx_get_cpuid_table_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_sgx_get_cpuid_table_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(cpuid_table_buffer, 1, _args.cpuid_table_buffer_size);

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_sgx_backtrace_symbols_ocall(
    oe_result_t* _retval,
    oe_enclave_t* oe_enclave,
    const uint64_t* buffer,
    size_t size,
    void* symbols_buffer,
    size_t symbols_buffer_size,
    size_t* symbols_buffer_size_out)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_sgx_backtrace_symbols_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.oe_enclave = (oe_enclave_t*)oe_enclave;
    _args.buffer = (uint64_t*)buffer;
    _args.size = size;
    _args.symbols_buffer = (void*)symbols_buffer;
    _args.symbols_buffer_size = symbols_buffer_size;
    _args.symbols_buffer_size_out = (size_t*)symbols_buffer_size_out;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_sgx_backtrace_symbols_ocall_args_t));
    if (buffer)
        OE_ADD_ARG_SIZE(_input_buffer_size, _args.size, sizeof(uint64_t));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_sgx_backtrace_symbols_ocall_args_t));
    if (symbols_buffer)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, _args.symbols_buffer_size);
    if (symbols_buffer_size_out)
        OE_ADD_ARG_SIZE(_output_buffer_size, 1, sizeof(size_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_sgx_backtrace_symbols_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (buffer)
        OE_WRITE_IN_PARAM(buffer, _args.size, sizeof(uint64_t), uint64_t*);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_sgx_backtrace_symbols_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_sgx_backtrace_symbols_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_sgx_backtrace_symbols_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    *_retval = _pargs_out->oe_retval;

    OE_READ_OUT_PARAM(symbols_buffer, 1, _args.symbols_buffer_size);
    OE_READ_OUT_PARAM(symbols_buffer_size_out, 1, sizeof(size_t));

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_sgx_thread_wake_wait_ocall(
    oe_enclave_t* oe_enclave,
    uint64_t waiter_tcs,
    uint64_t self_tcs)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_sgx_thread_wake_wait_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.oe_enclave = (oe_enclave_t*)oe_enclave;
    _args.waiter_tcs = waiter_tcs;
    _args.self_tcs = self_tcs;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_sgx_thread_wake_wait_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_sgx_thread_wake_wait_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_sgx_thread_wake_wait_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_sgx_thread_wake_wait_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_sgx_thread_wake_wait_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_sgx_thread_wake_wait_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_sgx_wake_switchless_worker_ocall(oe_host_worker_context_t* context)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_sgx_wake_switchless_worker_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.context = (oe_host_worker_context_t*)context;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_sgx_wake_switchless_worker_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_sgx_wake_switchless_worker_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_sgx_wake_switchless_worker_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_sgx_wake_switchless_worker_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_sgx_wake_switchless_worker_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_sgx_wake_switchless_worker_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

oe_result_t oe_sgx_sleep_switchless_worker_ocall(oe_enclave_worker_context_t* context)
{
    oe_result_t _result = OE_FAILURE;

    /* If the enclave is in crashing/crashed status, new OCALL should fail
       immediately. */
    if (oe_get_enclave_status() != OE_OK)
        return oe_get_enclave_status();

    /* Marshalling struct. */
    oe_sgx_sleep_switchless_worker_ocall_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;
    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.context = (oe_enclave_worker_context_t*)context;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(oe_sgx_sleep_switchless_worker_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(oe_sgx_sleep_switchless_worker_ocall_args_t));
    /* There were no corresponding parameters. */
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (oe_sgx_sleep_switchless_worker_ocall_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    /* There were no in nor in-out parameters. */
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    _result = popsgx_call("oe_call_host_function",1,helloworld_fcn_id_oe_sgx_sleep_switchless_worker_ocall);
    goto done;

    /* Call host function. */
    if ((_result = oe_call_host_function(
             helloworld_fcn_id_oe_sgx_sleep_switchless_worker_ocall,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (oe_sgx_sleep_switchless_worker_ocall_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->oe_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */

    /* There were no out nor in-out parameters. */

    /* Retrieve propagated errno from OCALL. */
    /* Errno propagation not enabled. */

    _result = OE_OK;

done:
    if (_buffer)
        oe_free_ocall_buffer(_buffer);

    return _result;
}

OE_EXTERNC_END
