#include <iostream>
#include <cstring>

uint8_t recvBuf[30]={0x7f,0x12,0x13,0x14,0x15,
                     0x16,0x17,0x18,0x19,0x7f,

                     0x7f,0x12,0x13,0x14,0x7f,

                     0x7f,0x17,0x18,0x19,0x12,
                     0x13,0x12,0x13,0x14,0x7f,

                     0x7f,0x17,0x18,0x19,0x56
                    };
uint8_t recvBuf1[30]={0x7f,0x7f,0x13,0x14,0x15,
                     0x16,0x17,0x18,0x19,0x7f,

                     0x7f,0x12,0x13,0x14,0x7f,

                     0x7f,0x17,0x18,0x19,0x12,
                     0x13,0x12,0x13,0x14,0x7f,

                     0x7f,0x17,0x18,0x19,0x7f
                    };
uint8_t txBuf[10];
uint16_t length = 0;
bool checkIfBufIsAvailable(uint8_t *txBuf,uint8_t* recvBuf,uint16_t& len);

int main()
{

    while(checkIfBufIsAvailable(txBuf,recvBuf,length)==true){
        for(int i=0;i<length;i++){
            std::cout<<std::hex<<static_cast<int>(txBuf[i])<<std::endl;
        }
        std::cout<<"\n";
    }
    while(checkIfBufIsAvailable(txBuf,recvBuf1,length)==true){
        for(int i=0;i<length;i++){
            std::cout<<std::hex<<static_cast<int>(txBuf[i])<<std::endl;
        }
        std::cout<<"\n";
}
        return 0;
    }

bool checkIfBufIsAvailable(uint8_t* txBuf,uint8_t* recvBuf,uint16_t& len){
    int ret=30;
    static int i=0;
    static uint8_t recvBufIndex=0;
    static uint8_t inc = 0;
    //std::memset(&txBuf[0],0,10);
    while(recvBufIndex<ret){
        if(recvBuf[recvBufIndex]==0x7f){
            txBuf[i]=recvBuf[recvBufIndex];
            inc++;
        }
        else{
            txBuf[i]=recvBuf[recvBufIndex];
        }
        i++;
        recvBufIndex++;
        if(inc == 2){
            inc=0;
            len =i;
            i=0;
            return true;
        }
    }
    recvBufIndex=0;
    return false;
}
