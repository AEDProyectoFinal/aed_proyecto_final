
#include <iostream>
#include <string>
#include <sstream>
#include "twitcurl.h"
#include "oauthlib.h"
#include <algorithm>
#include "nlohmann/json.hpp"

using namespace std;
FILE _iob[] = { *stdin,*stdout,*stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
extern "C" void __imp__set_output__format(void){}

int main1() {

	twitCurl twitterObj;
	string replyMsg;
	string tmpStr, tmpStr2;
	char tmpBuf[1024];
	twitterObj.setTwitterUsername("la_musice");
	twitterObj.setTwitterPassword("Fortachon091");

	cout << "test" << endl;
	string consumerKey = "b3xOQ7MqJNDFAcXwOx35JdbSX";
	string consumerKeysecret = "VKQNJCJW05YEFgaA6nfdR4x2BqrvpDdA9s0xykQGGAxGkCT9Bb";
	string myOAuthAccessTokenKey = "780626992550989824-eDyB0LaTPTYig1JDK5X0t4SQPD7lw6W";
	string myOAuthAccessTokenSecret = "rOBoLqzODfnRoFn8VbZrJCf7gVfrShaRYZtM3rvOUgtiG";

	// Setting Keys - Poniendo los tokens , username y password

	/* Step 0: Set OAuth related params. These are got by registering your app at twitter.com */
	twitterObj.getOAuth().setConsumerKey(consumerKey);
	twitterObj.getOAuth().setConsumerSecret(consumerKeysecret);
	twitterObj.getOAuth().setOAuthTokenKey(myOAuthAccessTokenKey);
	twitterObj.getOAuth().setOAuthTokenSecret(myOAuthAccessTokenSecret);


	// Codigo obtener tweets
	tmpStr = "petro"; // Esta es la palabra que queremos buscar aparentemente solo funciona con tweets recientes 
	replyMsg = "";
	if (twitterObj.search(tmpStr))
	{
		twitterObj.getLastWebResponse(replyMsg);
		printf("\ntwitterClient:: twitCurl::search web response:\n%s\n", replyMsg.c_str());
	}
	else
	{
		twitterObj.getLastCurlError(replyMsg);
		printf("\ntwitterClient:: twitCurl::search error:\n%s\n", replyMsg.c_str());
	}



	system("pause");
	ofstream out("Twitter_API.json");
	out << replyMsg;
	out.close();
	return 0;
}

