/**
*   This file is part of assembly_for_raspberry_pi_bare_metal
*   (https://github.com/RomanLabsIO/assembly_for_raspberry_pi_bare_metal).
*
*   Copyright (c) 2021 RomanLabs I/O
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
**/

.section ".text"
.align 2

.global _bitwise_count_leading_zeroes_binary_64_bits
_bitwise_count_leading_zeroes_binary_64_bits:
    blr x30

.global _bitwise_2_to_the_nth_64_bits
_bitwise_2_to_the_nth_64_bits:
    blr x30

.global _bitwise_swap_endianness_64_bits
_bitwise_swap_endianness_64_bits:
    blr x30

.global _bitwise_hex_digit_repeat_64_bits
_bitwise_hex_digit_repeat_64_bits:
    blr x30