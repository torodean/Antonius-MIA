/*
 * D0sag3Conversation.h
 *
 *  Created on: Oct 17, 2014
 *      Author: antonius
 */

#include <string>
#ifndef D0SAG3CONVERSATION_H_
#define D0SAG3CONVERSATION_H_

namespace std {

class D0sag3Conversation {
public:
	D0sag3Conversation();
	bool isTerm(string term);
	void reply(string term);
	virtual ~D0sag3Conversation();
};

} /* namespace std */

#endif /* D0SAG3CONVERSATION_H_ */
