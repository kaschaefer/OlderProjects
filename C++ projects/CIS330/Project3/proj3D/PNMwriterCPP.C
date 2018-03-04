#include <PNMwriterCPP.h>

void PNMwriterCPP::Write(char* file) {
	Image* output = this->input1;
	int width = output->getWidth();
	int height = output->getHeight();
	int maxval = 255;
	ofstream f_out;
	f_out.open (file, ios::binary);
	if (f_out.is_open()){
		f_out << "P6\n" << width << " " << height << "\n" << maxval << "\n";
		f_out.write(reinterpret_cast<char*>(output->getBuffer()), sizeof(Pixel)*width*height);
	}
	else{
		cout << "There was an error opening the file" << endl;
	}
	f_out.close();
};
