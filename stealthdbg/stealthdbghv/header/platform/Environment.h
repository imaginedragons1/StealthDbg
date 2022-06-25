/**
 * @file Environment.h
 * @author anonymous
 * @brief The running environment of StealthDbg
 * @details
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#pragma once

//////////////////////////////////////////////////
//				    Definitions	        		//
//////////////////////////////////////////////////

//
// Check for platform
//

#if defined(_WIN32) || defined(_WIN64)
#    define ENV_WINDOWS
#else
#    error "This code cannot compile on non windows platforms"
#endif
