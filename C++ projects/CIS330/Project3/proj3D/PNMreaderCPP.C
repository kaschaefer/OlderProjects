#include <PNMreaderCPP.h>

PNMreaderCPP::PNMreaderCPP(){
	file = nullptr;
}

PNMreaderCPP::PNMreaderCPP(char* filename){
	file = new char[128];
	strcpy(file, filename);
}

PNMreaderCPP::~PNMreaderCPP(){
	if (file != nullptr){
		delete [] file;
	}
}

void PNMreaderCPP::Execute(){
	int width =0;
	int height =0;
	int maxval =0;
	char magicNum[128];
	Image * img = GetOutput();
	ifstream f_in;
	f_in.open (this->file, ios::binary);
	if (f_in.is_open()){
		f_in >> magicNum;
		f_in >> width;
		f_in >> height;
		f_in >> maxval;
		f_in.seekg( 1, ios::cur);
		Pixel* buff;
		if (width != 0 && height !=0) {
			img->ResetSize(width, height);
			buff = img->getBuffer();
		}
		if (buff != nullptr){
			f_in.read(reinterpret_cast<char*>(buff), sizeof(Pixel)*width*height);
		}
	}
	else {
		cout << "There was an error in writing the file" << endl;
	}
	f_in.close();
};

