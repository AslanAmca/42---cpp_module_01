/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:24:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/25 15:10:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string name;

	// HumanB her zaman bir silaha sahip olmak zorunda değil, yani NULL olabilir.
	// Reference NULL olamaz, bu nedenle Weapon pointer olarak tanımlanmalıdır.
	Weapon *weapon;

public:
	HumanB(std::string name);
	~HumanB(void);
	void attack();
	void setWeapon(Weapon &weapon);
};


#endif
