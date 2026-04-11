#6. Check whether 0.1+0.2 = 0.3 holds true in Python? If not find the ways to make it true.
#Author - Vedika Udgir

print(0.1 + 0.2 == 0.3)

import decimal

print(decimal.Decimal('0.1') + decimal.Decimal('0.2') == decimal.Decimal('0.3'))