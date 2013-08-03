//
//
//

#include <unistd.h>

#include "arduPi.h"
#include "SeeedMotorShield.h"

const int delay_msec = 1000;
const int delay_usec = (delay_msec * 1000);
MotorShield sms;

int main() {
	while(1) {

		sms.run(motor_a, dir_fwd);
		sms.run(motor_b, dir_rev);
		usleep(delay_usec);

		sms.stop(motor_a);
		sms.stop(motor_b);
		usleep(delay_usec);

		sms.run(motor_a, dir_rev);
		sms.run(motor_b, dir_fwd);
		usleep(delay_usec);

		sms.stop(motor_a);
		sms.stop(motor_b);
		usleep(delay_usec);
	}
}

