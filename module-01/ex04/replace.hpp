/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:13:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/09/01 14:13:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

// Reads the entire content of a file into a string.
bool readFileContent(const std::string &filename, std::string &content);

// Replaces all occurrences of s1 with s2 in the given content.
std::string replaceContent(const std::string &content, const std::string &s1,
                           const std::string &s2);

// Writes the given content to a new file.
bool writeFileContent(const std::string &filename, const std::string &content);

#endif
