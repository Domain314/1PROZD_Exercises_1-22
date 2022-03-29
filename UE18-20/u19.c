/*
 * Eratosthenes314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPrimality(int num_)
{
    for (int i = num_-1; i > 2; i--) {
        if (num_ % i == 0) return 0;
    }
    return 1;
}

char* sieveOfEratosthenes(int amount_)
{
    char* nums = (char*)calloc(amount_+2, sizeof(char));
    memset(nums, '.', 2);     // set [0], [1] to '.'
    for (int i = 2; i <= amount_; i++) {   // check all numbers
        if(nums[i] == '.') continue;   //continue, when number was multiple of prime
        if(checkPrimality(i)) {
            nums[i] = 'p';          // mark as primary number
            for (int j = i*2; j <= amount_; j += i) {   // set all multiples to '.'
                nums[j] = '.';
            }
        }
    }
    return nums;
}

int main()
{
    int amount;
    printf(": "); scanf(" %d", &amount);
    char* nums = sieveOfEratosthenes(amount);
    int counter = 0;
    for (int i = 0; i <= amount; ++i) {
        if(nums[i] == 'p') {
            printf("%d ", i);
            if(++counter % 10 == 0) printf("\n");
        }
    }
    free(nums);
    return 0;
}
