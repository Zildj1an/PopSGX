# userfaultfd-dsm
PoC for Distributed Shared Memory Server-Client using linux's userfaultfd and SSL/TLS security.

Generate the certificate at the server:

``` 
$ bash generate_cert.sh 
``` 
Client and server use the same binary. 

Call both using: ```./popsgx```
