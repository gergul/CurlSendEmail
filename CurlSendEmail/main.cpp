/*
	Example of how to this SMTP library to send attachments.
*/

#include <iostream>
#include "email.h"

using namespace std;

int main(void)
{
	Email e;
	int curlError = 0;
	// e.dump();

	e.setTo("coolcn@qq.com");
	e.setFrom("lsmy_notice@163.com");
	e.setSubject("Test Email");
	e.setCc("");
	e.setBody("Do not reply to this email");

	e.setSMTP_uri("smtps://smtp.163.com:465");
	//e.setSMTP_uri("smtp://smtp.163.com:25");
	e.setSMTP_username("lsmy_notice@163.com");
	e.setSMTP_password("************");

	//e.addAttachment("e:\\1.txt");

	e.constructEmail();
	e.dump("1.log");

	curlError = e.send();

	if (curlError){
		cout << "Error sending email!" << endl;
	}

	else{
		cout << "Email sent successfully!" << endl;
	}

	return 0;
}

