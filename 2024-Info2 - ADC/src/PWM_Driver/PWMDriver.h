/*
 * PWMDriver.h
 *
 *  Created on: 1 oct. 2024
 *      Author: Gustavo Fresno
 */

#ifndef PWM_DRIVER_PWMDRIVER_H_
#define PWM_DRIVER_PWMDRIVER_H_

class GPIOPWM : public Gpio , public CALLBACK
{
	private:
		uint8_t duty = 0;
		void Work(void);

	public:
		GPIOPWM(uint32_t _port, uint32_t _pin, uint32_t _dutyInit);

		void Set(uint32_t duty_conf);
		void Callback( void );
};


#endif /* PWM_DRIVER_PWMDRIVER_H_ */
