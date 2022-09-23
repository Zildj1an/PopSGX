#include <iostream>
#include <string>
//#include "sgx_urts.h"

#include <openenclave/host.h>
#include "sqlite_u.h"

using namespace std;

# define MAX_PATH FILENAME_MAX
# define ENCLAVE_FILENAME "enclave.signed.so"

// ocalls for printing string (C++ ocalls)
void ocall_print_error(const char *str){
    cerr << str << endl;
}

void ocall_print_string(const char *str){
    cout << str;
}

void ocall_println_string(const char *str){
    cout << str << endl;
}

// Application entry
int main(int argc, char *argv[])
{
    if ( argc != 2 ){
        cout << "Usage: " << argv[0] << " <database>" << endl;
        return -1;
    }
    const char* dbname = argv[1];

    oe_enclave_t* enclave = NULL;
    char token_path[MAX_PATH] = {'\0'};
    sgx_launch_token_t token = {0};
    int ret = 0; // status flag for enclave calls
    int updated = 0;
    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;

    // Initialize the enclave
    ret = oe_create_sqlite_enclave(
	"sqlitenc.signed",OE_ENCLAVE_TYPE_AUTO,flags, NULL,0,&enclave);

    if (ret != OE_OK) {
        cerr << "Error: creating enclave" << endl;
        return -1;
    }

    cout << "Info: SQLite SGX enclave successfully created." << endl;

    // Open SQLite database
    ret = ecall_opendb(enclave, dbname);

    if (ret != OE_OK) {
        cerr << "Error: Making an ecall_open()" << endl;
        return -1;
    }

    cout << "Enter SQL statement to execute or 'quit' to exit: " << endl;
    string input;
    cout << "> ";

    while(getline(cin, input)) {
        if (input == "quit"){
            break;
        }
        const char* sql = input.c_str();
        ret =  ecall_execute_sql(enclave, sql);
        if (ret != OE_OK) {
            cerr << "Error: Making an ecall_execute_sql()" << endl;
            return -1;
        }
        cout << "> ";
    }

    // Closing SQLite database inside enclave
    ret =  ecall_closedb(enclave);
    if (ret != OE_OK) {
        cerr << "Error: Making an ecall_closedb()" << endl;
        return -1;
    }

    // Destroy the enclave
    if (enclave)
    	oe_terminate_enclave(enclave);

    if (ret != OE_OK) {
        cerr << "Error: destroying enclave" << endl;
        return -1;
    }

    cout << "Info: SQLite SGX enclave successfully returned." << endl;
    return 0;
}
