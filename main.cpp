#include <fstream>
#include <cerrno>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <iostream>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()
{
    
    char diskNameR[] = "/dev/sda1";
    char diskNameW[] = "/home/cslab3/CaptainPartition/dumb.bin";
    unsigned int blockSize = 0;
    std::string diskError = std::string() + diskNameR + ": ";

    // getting blocksize
    int fd = open(diskNameR, O_RDWR);
    if (fd < 0)
        cout << "can not open /dev/sda1 \n" ;
    int rc = ioctl(fd, BLKSSZGET, &blockSize);

    cout << "Block size is: " << blockSize << endl;

    cout << "File is opened" << endl;

    // close(fd);

    // Open device file
    // std::ifstream disk(diskNameR, std::ios_base::binary);
    // size_t blockSize;
    // int fd = disk.open();

    // Open device file method 2
    // int fdes = open("/dev/sda1", O_RDONLY);
    // if (fdes < 0)
    //     err(1, "/dev/sda1");

    // if (!disk)
    //     throw(std::runtime_error(diskError + std::strerror(errno)));

    // // Seek to 54321'th sector
    // disk.seekg(blockSize * 2058);
    // if (!disk)
    //     throw(std::runtime_error(diskError + std::strerror(errno)));

    // cout << "Seeked!\n";
    // Read in one sector

    int numberOfSectors = blockSize;
    int extentOfRead = 0;
    char buffer[numberOfSectors];
    int nread;
    // disk.read(&buffer[0], 512);
    // if (!disk)
    //     throw(std::runtime_error(diskError + std::strerror(errno)));

    int i = 0;

    // std::ofstream dumbFile ("/home/cslab3/CaptainPartition/dumb.bin",std::ofstream::binary);

    int fdW = open(diskNameW, O_RDWR);
    if (fdW < 0)
        cout << "can not open /home/cslab3/CaptainPartition/Dumb.bin \n" ;
    else
        cout << diskNameW << " opened" << endl;

    while (nread = read(fd,&buffer,numberOfSectors) > extentOfRead)
    {
        cout << buffer[i];
        i++;
        write(fdW,buffer,sizeof(char));
    }

    //read stored dumb data

    // while (nread = read(fdW,&buffer,numberOfSectors) > 0)
    // {
    //     cout << buffer[i];
    //     i++;
    // }


    

    
    // for (int i = 0; i != 512; ++i)
    // {
    //     cout << "Data " << buffer[i] << endl;
    // }

}