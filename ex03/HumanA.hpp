/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:25:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/25 15:07:35 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string name;

	// HumanA her zaman bir silaha sahip olacak, yani NULL olma durumu yok. 
	// Bu nedenle Weapon'un Reference olarak tanımlanması daha uygundur.
	Weapon &weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void attack();
};

#endif
