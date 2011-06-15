/*
** uncopyable.hpp
** Login : <Amoriello>
** Started on  Sat Jun 11 23:58:44 2011
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

#ifndef   	UNCOPYABLE_HPP_
# define   	UNCOPYABLE_HPP_

class uncopyable
{
protected:
  uncopyable() {};
  ~uncopyable() {};

private:
  const uncopyable& operator =(const uncopyable&);
  uncopyable(const uncopyable&);
};

#endif	    /* !UNCOPYABLE_PP_ */
