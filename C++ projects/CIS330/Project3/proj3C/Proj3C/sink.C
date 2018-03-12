#include <sink.h>

Sink::Sink(){
	input1 = nullptr;
	input2 = nullptr;
}

void Sink::SetInput(Image* in){
	input1 = in;
}

void Sink::SetInput2(Image* in){
	input2 = in;
};
