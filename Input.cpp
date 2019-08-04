#include "Input.h"

int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::mouseL = 0;
int Input::mouseM = 0;
int Input::mouseR = 0;
int Input::key[256] = {0};
char Input::keyBuf[256] = {0};

void Input::Update(){
	GetMousePoint(&mouseX, &mouseY);
	if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) mouseL++;
	else mouseL = 0;
	if((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) mouseR++;
	else mouseR = 0;
	if((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0) mouseM++;
	else mouseM = 0;

	GetHitKeyStateAll(keyBuf);
	for(int i=0;i<256;i++){
		if(keyBuf[i]==1){
			key[i] += 1;
		}
		else if(key[i] > 0){
			key[i] = 0;
		}
	}	
}

void Input::Mouse(int *x,int *y){
	*x = mouseX;
	*y = mouseY;
}

void Input::Draw(){
	
}

int Input::Key(int k){
	return key[k];
}


int Input::MouseL(){return mouseL;}
int Input::MouseM(){return mouseM;}
int Input::MouseR(){return mouseR;}