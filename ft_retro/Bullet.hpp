/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletObject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 17:17:09 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETOBJECT_HPP
#define  BULLETOBJECT_HPP

#include "GameObject.hpp"
#include "LivingObject.hpp"

class BulletObject : public LivingObject
{
	
	public:
		bool	destroyOutOfBounds;
		BulletObject( bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		BulletObject(BulletObject& copy);
		~BulletObject(void);
		BulletObject& operator=(BulletObject& copyFrom);

};

#endif
