#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>

int main(int argc, char *argv[])
{
    Blender br;

    Color blue(2000, 2000, 0, 0, 255);
    Color red(2000, 2000, 255, 0, 0);

    br.SetFactor(.5);

    br.SetInput(blue.GetOutput());
    br.SetInput2(red.GetOutput());

    br.GetOutput()->Update();

    PNMwriter writer;
    writer.SetInput(br.GetOutput());
    writer.Write(argv[1]);

    CheckSum cs;
    cs.SetInput(br.GetOutput());
    cs.OutputCheckSum("proj3G_checksum");
}
