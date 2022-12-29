/*
 * dc.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Toshiba
 */

#ifndef DC_DC_H_
#define DC_DC_H_

/*
 * dc.h
 *
 * Created: 9/7/2022 7:07:49 PM
 *  Author: Pc
 */
 #include "../dio/dio.h"

#ifndef DC_H_
#define DC_H_

#define DC_LEFT_PORT	DIOA
#define DC_LEFT_PIN		PIN_7

#define DC_RIGHT_PORT	DIOA
#define DC_RIGHT_PIN	PIN_6

void dc_init();
void dc_start();
void dc_stop();

#endif /* DC_H_ */

#endif /* DC_DC_H_ */
