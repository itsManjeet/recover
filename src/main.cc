#include <func.hh>
#include <releax/filesys.hh>
#include <releax/config.hh>

#define loc_config "config.cfg"
#define global_config "/etc/recover.cfg"

int 
main(int    ac,
     char** av)
{
    

    auto app = new App();
    app->name("recover")
       ->version(0.1)
       ->release('a')
       ->desc("System recovery tool")
       
       ->author(
           "Manjeet Saini",
           "itsmanjeet1998@gmail.com",
           "Lead Developer"
        )

        ->config_file(loc_config)

        ->sub(
            "sysimage",
            "Recover system from backup image ( replace /usr )",
            "-i [ImageLoc]",
            func_recover
        )
        
        ->sub(
            "reset",
            "Reset System configurations ( delete ~/.* , /etc, /var )",
            "\t\t",
            func_reset
        );


    int status = app->execute(ac, av);
    if (status != 0) {
        std::cout << "Error occured " << status << std::endl;
    }

    delete app;
    return status;
}