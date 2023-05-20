#include "usb_thread.h"


USB_Thread::USB_Thread()
{
    isStop = false;
}


void USB_Thread::closeThread()
{
    isStop = true;
}


void USB_Thread::run()
{
    unsigned char rbuf[64];
    QString str;
    while (1)
    {
        if(isStop)
            return;
        for(int i=0;i<64;i++)
            rbuf[i]=0x0b;
        hid_read(handle,rbuf,64);          // 读一包数据，判断是否有数据进来
        sleep(1);                          // 此处延时不可省略，否则接收数据不完全
        if(rbuf[0]!=0x0b&&rbuf[63]!=0x0b)  // 判断包头包尾是否自己写入的
        {
            while(1)
            {
                for(int i = 1;i < 64;i++)  // 跳过第一位数据长度
                {
                   str+=tr("%1,").arg(rbuf[i]);
                }
                for(int i=0;i<64;i++)
                    rbuf[i]=0x0b;
                hid_read(handle,rbuf,64);  // 读一包数据，判断是否数据读取完毕，最大支持接收（32-1）*n=31*n字节数据
                if(rbuf[0]==0x0b&&rbuf[63]==0x0b)
                    break;
            }
            emit updateString11(str);
        }
        else
            str.clear();
    }
}
