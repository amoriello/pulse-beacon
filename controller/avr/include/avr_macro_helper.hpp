/*
** avr_macro_helper.hpp
** Login : <Amoriello>
** Started on  Fri Jun 10 12:39:51 2011
**
** Author(s):
**  - Amoriello Hutti <amoriello.hutti@gmail.com>
**
** Copyright (C) 2011 Amoriello Hutti
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef   	AVR_MACRO_HELPER_HPP_
# define   	AVR_MACRO_HELPER_HPP_

# include <stdint.h>

//-----------------------------------------------------------------------------
// DDR, PORT, PIN Macro Helper
//-----------------------------------------------------------------------------

// I N D I R E C T    M A C R O    H E L P E R : Do not use directly
# ifndef DDR__
#  define DDR__(PortId)          DDR##PortId
# endif /* !DDR__ */

# ifndef PORT__
#  define PORT__(PortId)         PORT##PortId
# endif /* !PORT__ */

# ifndef PIN__
#  define PIN__(PortId, PinId)   P##PortId##PinId
# endif /*! PIN__ */



# ifndef DDR
#  define DDR(PortId)           DDR__(PortId)
# endif /* !DDR */

# ifndef PORT
#  define PORT(PortId)          PORT__(PortId)
# endif /* !PORT */

# ifndef PIN
#  define PIN(PortId, PinId)    PIN__(PortId, PinId)
# endif /*! PIN */



//-----------------------------------------------------------------------------
// Enable, Disable "Type checked macrofunctions"
//-----------------------------------------------------------------------------
template <typename T1>
inline void    enable(volatile T1& Port, uint8_t bit_pos) {
  Port |= _BV(bit_pos);
}


template <typename T1>
inline void    disable(volatile T1& Port, uint8_t bit_pos)
{
  Port &= ~(_BV(bit_pos));
}



//-----------------------------------------------------------------------------
// _BV() oposite
//-----------------------------------------------------------------------------
#define _ZERO(BitPos)   (0 << (BitPos))


#endif 	    /* !AVR_MACRO_HELPER_HPP_ */
