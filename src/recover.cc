#include <recover.hh>
#include <releax/filesys.hh>


Sysimage::Sysimage(std::string img_loc)
{
    this->img_loc = img_loc;
}

int
Sysimage::verify()
{
    return VERIFY_SUCCESS;
}


int
Sysimage::extract()
{
    return EXTRACT_SUCCESS;
}

int
Sysimage::recover()
{
    if (!filesys::exist(img_loc)) {
        return ERR_FILE_NOT_EXIST;
    }

    int status = this->verify();
    if ( status != VERIFY_SUCCESS) {
        return status;
    } 

    status = this->extract();
    if (status != EXTRACT_SUCCESS) {
        return status;
    }

    
}

