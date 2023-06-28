/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:06 by aaslan            #+#    #+#             */
/*   Updated: 2023/06/28 02:52:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: invalid argument count." << std::endl;
		return 1;
	}

	// parametre olarak gelen değişkenler
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	// dosya okuma
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: " << filename << " can't open." << std::endl;
		return 1;
	}

	// okunan dosyanın içeriğini alma
	// \0 karakteri görene kadar okuyacak.
	// Yani bütün dosyayı tek seferde okumuş olacak.
	std::string file_content;
	std::getline(file, file_content, '\0');

	// file ile işimiz bitti, kapat.
	file.close();

	// okunan dosya boşsa bir şey yapmaya gerek yok.
	if (file_content.empty())
	{
		std::cout << "Error: " << filename << " is empty." << std::endl;
		return 1;
	}

	// file_content içerisinde ki s1 ile s2'leri değiştir.
	int founded_index = file_content.find(s1);
	while (founded_index != -1)
	{
		file_content.erase(founded_index, s1.length());
		file_content.insert(founded_index, s2);
		founded_index = file_content.find(s1);
	}

	// .replace dosyasını yazmak için aç
	std::string filename_replace(filename + ".replace");
	std::ofstream file_replace(filename_replace.c_str());
	if (!file_replace.is_open())
	{
		std::cout << "Error: " << filename_replace << " can't open." << std::endl;
		return (1);
	}

	// elde edilen content'i .replace dosyasına yaz.
	file_replace << file_content;

	// .replace dosyasını kapat.
	file_replace.close();

	return 0;
}
