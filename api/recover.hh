#ifndef __RECOVER__
#define __RECOVER__

#include <iostream>

enum Errors {
    ERR_FILE_NOT_EXIST = -1,
    VERIFY_SUCCESS = 100,
    EXTRACT_SUCCESS = 101,
};


/* System Image 
   
   ** Start **
   
   --> verify [ gpg sign ] 
   --> extract [ /tmp/recovery_img ]
   --> configure [replace /lib64/ld-linux-x86_64.so -> /tmp/recovery_img
                        /lib
                        /bin
                        /sbin
                links ]
   --> ldconfig 
   --> replace [ /usr              -> /usr_old ]
               [ /tmp/recovery_img -> /usr     ]

   --> configure again [ replace /lib64/ld-linux-x86_64.so -> /usr 
                                 /lib
                                 /bin
                                 /sbin 
                        links ]
   --> ldconfig

   ** Done **

*/
class Sysimage {
    int verify();
    int extract();
    std::string img_loc;
    std::string extract_loc;
public:
    Sysimage(std::string img_loc);
    int recover();
};

#endif