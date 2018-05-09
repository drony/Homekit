//
// HAPEncryption.hpp
// Homekit
//
//  Created on: 08.05.2018
//      Author: michael
//

#ifndef HAPENCRYPTION_HPP_
#define HAPENCRYPTION_HPP_

#include <Arduino.h>
#include <sodium.h>

#define HAP_AAD_LENGTH 2

class HAPEncryption {
public:
	// Set the following values to ... to get the padded buffer size 
	//		buf 		  	= NULL
	//  	max_buflen 		= 0
	static int pad(size_t *padded_buflen_p, uint8_t *msg, 
			const uint8_t *buf, size_t unpadded_buflen, 
			size_t blocksize, size_t max_msglen, bool zeroPadded = true);

	static size_t paddedLength(size_t unpadded_buflen, size_t blocksize) {
			size_t padded_buflen = 0;
			
			pad(&padded_buflen, NULL, NULL, unpadded_buflen, blocksize, 0);
		return padded_buflen;
	}

	// only working for non-zero padded
	static int unpad(size_t *unpadded_buflen_p, const unsigned char *buf,
			size_t padded_buflen, size_t blocksize);


	static int computePoly1305(uint8_t* hmac, uint8_t* cipherText, 
			size_t cipherTextLength, uint8_t* AAD, uint8_t *nonce, 
			uint8_t *key);

	static int verifyAndDecrypt(uint8_t *decrypted, uint8_t cipherText[], uint16_t length, 
			uint8_t mac[], uint8_t aad[], uint16_t decryptCount, uint8_t key[]);
};

#endif /* HAPENCRYPTION_HPP_ */