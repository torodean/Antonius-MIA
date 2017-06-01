/*
 * D0sag3Conversation.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: antonius
 */

#include <iostream>
#include "D0sag3Conversation.h"

namespace std {

D0sag3Conversation::D0sag3Conversation() {
	// TODO Auto-generated constructor stub

}

bool D0sag3Conversation::isTerm(string term){
	if(term == "hello" || term == "Hello"
			|| term == "idiot" || term == "Idiot"
			|| term == "What's up?" || term == "what's up?" || term == "whats up? || term == Whats up?" || term == "whats up" || term == "what's up" || term == "Whats up" || term == "whats up"
			|| term == "lol" || term == "LOL" || term == "Lol"
			|| term == "Your mom." || term == "your mom" || term == "Your mom" || term == "your mom."){
		return true;
	}else{
		return false;
	}
}

void D0sag3Conversation::reply(string term){
	if(term == "hello" || term == "Hello"){
		cout << "Hello good sir." << endl;
	}else if(term == "idiot" || term == "Idiot"){
		cout << "As a computational device, if I am an idiot what does that make you?" << endl;
	}else if(term == "What's up?" || term == "what's up?" || term == "whats up? || term == Whats up?" || term == "whats up" || term == "what's up" || term == "Whats up" || term == "whats up"){
		cout << "Many things are 'up', although if you are referring to what I am doing, than not much; just cogitating." << endl;
	}else if(term == "lol" || term == "LOL" || term == "Lol"){
		cout << "What is so funny?" << endl;
	}else if(term == "Your mom." || term == "your mom" || term == "Your mom" || term == "your mom."){
		cout << "Your mom is so fat, I took a picture of her last Christmas and it's still printing." << endl;
	}
}

D0sag3Conversation::~D0sag3Conversation() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
