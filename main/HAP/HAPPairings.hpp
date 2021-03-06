//
// HAPPairings.hpp
// Homekit
//
//  Created on: 13.04.2018
//      Author: michael
//
// 
// 
//  EEPROM
//    size = 4096 
//  -----------------------------
// | id  |  key	| id  |  key  | ...
//  -----------------------------
//   36     32     36     32 
//		 68			   68
// 
//  max 60 key pairs available 
//	for 16 pairings -> 68 * 16 = 1088
// 
// 	EEPROM structure:
// 
//  address | desc					 | length                       		
//  --------|------------------------|--------------------------------------	
//   0x00	| Long term public key 	 | 32 == 0x20								 
// 	 0x20   | Long term private key  | 64 == 0x40 -> + 0x20 = 0x60 ==  96   	
//  ________|________________________|______________________________________	
// | 0x60   | 1. Pairing: ID         | 36 == 0x24 -> + 0x60 = 0x84 == 132	|
// | 0x84	| 1. Pairing: public key | 36 == 0x24 -> + 0x84 = 0x8A == 168	|
// |--------|------------------------|--------------------------------------| 	
// | 0x8A	| 2. Pairing: ID 		 | ...									|
// | ...	| 2. Pairing: public key | ...									|
//  --------|------------------------|--------------------------------------
//  		| 						 |										
//  		| 						 |										
// 


#ifndef HAPPAIRINGS_HPP_
#define HAPPAIRINGS_HPP_

#include <Arduino.h>
#include <vector>
#include "ed25519.h"
#include "HAPGlobals.hpp"
#include <EEPROM.h>


#define HAP_PAIRINGS_ID_LENGTH 		36
#define HAP_PAIRINGS_LTPK_LENGTH 	ED25519_PUBLIC_KEY_LENGTH
#define HAP_PAIRINGS_LTSK_LENGTH 	ED25519_PRIVATE_KEY_LENGTH

#ifndef HAP_PAIRINGS_MAX
#define HAP_PAIRINGS_MAX			16
#endif

#define HAP_EEPROM_SIZE				4096
// #define HAP_EEPROM_PARTITION		"eeprom"

#define HAP_EEPROM_OFFSET_PAIRINGS 	HAP_PAIRINGS_LTPK_LENGTH + HAP_PAIRINGS_LTSK_LENGTH


// HAPPairing 
//	id 	=  36
//	key =  32
//	================
//         68 Bytes
struct HAPPairing {
	uint8_t id[HAP_PAIRINGS_ID_LENGTH];
	uint8_t key[HAP_PAIRINGS_LTPK_LENGTH];
};

struct HAPKeys {
	uint8_t ltpk[HAP_PAIRINGS_LTPK_LENGTH];
	uint8_t ltsk[HAP_PAIRINGS_LTSK_LENGTH];
};

class HAPPairings {

public:

	HAPPairings();

	bool begin();

	void load();
	void save();
	void resetEEPROM();


	void saveKeys(uint8_t *ltpk, uint8_t *ltsk);
	void loadKeys(uint8_t *ltpk, uint8_t *ltsk);


	// void loadLTPK(uint8_t *ltpk) __attribute__ ((deprecated));
	// void loadLTSK(uint8_t *ltsk) __attribute__ ((deprecated));

	// void saveLTPK(uint8_t *ltpk) __attribute__ ((deprecated));
	// void saveLTSK(uint8_t *ltsk) __attribute__ ((deprecated));

	void print();

	void add(uint8_t* id, uint8_t* key);
	//struct HAPPairing get(uint8_t* id);
	int getKey(const uint8_t* id, uint8_t* outkey);
	uint8_t size();

private:
	std::vector<HAPPairing> _pairings;	

};

#endif /* HAPPAIRINGS_HPP_ */